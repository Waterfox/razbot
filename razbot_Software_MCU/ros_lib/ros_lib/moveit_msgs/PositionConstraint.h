#ifndef _ROS_moveit_msgs_PositionConstraint_h
#define _ROS_moveit_msgs_PositionConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "moveit_msgs/BoundingVolume.h"

namespace moveit_msgs
{

  class PositionConstraint : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* link_name;
      geometry_msgs::Vector3 target_point_offset;
      moveit_msgs::BoundingVolume constraint_region;
      float weight;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->target_point_offset.serialize(outbuffer + offset);
      offset += this->constraint_region.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->target_point_offset.deserialize(inbuffer + offset);
      offset += this->constraint_region.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PositionConstraint"; };
    const char * getMD5(){ return "c83edf208d87d3aa3169f47775a58e6a"; };

  };

}
#endif