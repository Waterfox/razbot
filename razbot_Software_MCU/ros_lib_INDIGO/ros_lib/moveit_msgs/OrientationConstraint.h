#ifndef _ROS_moveit_msgs_OrientationConstraint_h
#define _ROS_moveit_msgs_OrientationConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"

namespace moveit_msgs
{

  class OrientationConstraint : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Quaternion orientation;
      const char* link_name;
      float absolute_x_axis_tolerance;
      float absolute_y_axis_tolerance;
      float absolute_z_axis_tolerance;
      float weight;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->absolute_x_axis_tolerance);
      offset += serializeAvrFloat64(outbuffer + offset, this->absolute_y_axis_tolerance);
      offset += serializeAvrFloat64(outbuffer + offset, this->absolute_z_axis_tolerance);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->absolute_x_axis_tolerance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->absolute_y_axis_tolerance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->absolute_z_axis_tolerance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/OrientationConstraint"; };
    const char * getMD5(){ return "ab5cefb9bc4c0089620f5eb4caf4e59a"; };

  };

}
#endif