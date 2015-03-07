#ifndef _ROS_moveit_msgs_CostSource_h
#define _ROS_moveit_msgs_CostSource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace moveit_msgs
{

  class CostSource : public ros::Msg
  {
    public:
      float cost_density;
      geometry_msgs::Vector3 aabb_min;
      geometry_msgs::Vector3 aabb_max;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->cost_density);
      offset += this->aabb_min.serialize(outbuffer + offset);
      offset += this->aabb_max.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cost_density));
      offset += this->aabb_min.deserialize(inbuffer + offset);
      offset += this->aabb_max.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/CostSource"; };
    const char * getMD5(){ return "abb7e013237dacaaa8b97e704102f908"; };

  };

}
#endif