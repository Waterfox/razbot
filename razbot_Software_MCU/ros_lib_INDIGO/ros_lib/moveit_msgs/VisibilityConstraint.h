#ifndef _ROS_moveit_msgs_VisibilityConstraint_h
#define _ROS_moveit_msgs_VisibilityConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace moveit_msgs
{

  class VisibilityConstraint : public ros::Msg
  {
    public:
      float target_radius;
      geometry_msgs::PoseStamped target_pose;
      int32_t cone_sides;
      geometry_msgs::PoseStamped sensor_pose;
      float max_view_angle;
      float max_range_angle;
      uint8_t sensor_view_direction;
      float weight;
      enum { SENSOR_Z = 0 };
      enum { SENSOR_Y = 1 };
      enum { SENSOR_X = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->target_radius);
      offset += this->target_pose.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_cone_sides;
      u_cone_sides.real = this->cone_sides;
      *(outbuffer + offset + 0) = (u_cone_sides.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cone_sides.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cone_sides.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cone_sides.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_sides);
      offset += this->sensor_pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_view_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_range_angle);
      *(outbuffer + offset + 0) = (this->sensor_view_direction >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_view_direction);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->target_radius));
      offset += this->target_pose.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_cone_sides;
      u_cone_sides.base = 0;
      u_cone_sides.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cone_sides.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cone_sides.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cone_sides.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cone_sides = u_cone_sides.real;
      offset += sizeof(this->cone_sides);
      offset += this->sensor_pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_view_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_range_angle));
      this->sensor_view_direction =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_view_direction);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/VisibilityConstraint"; };
    const char * getMD5(){ return "62cda903bfe31ff2e5fcdc3810d577ad"; };

  };

}
#endif