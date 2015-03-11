#ifndef _ROS_moveit_msgs_JointLimits_h
#define _ROS_moveit_msgs_JointLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class JointLimits : public ros::Msg
  {
    public:
      const char* joint_name;
      bool has_position_limits;
      float min_position;
      float max_position;
      bool has_velocity_limits;
      float max_velocity;
      bool has_acceleration_limits;
      float max_acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      memcpy(outbuffer + offset, &length_joint_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.real = this->has_position_limits;
      *(outbuffer + offset + 0) = (u_has_position_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_position_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_position);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_position);
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.real = this->has_velocity_limits;
      *(outbuffer + offset + 0) = (u_has_velocity_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_velocity_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_velocity);
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.real = this->has_acceleration_limits;
      *(outbuffer + offset + 0) = (u_has_acceleration_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_acceleration_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name;
      memcpy(&length_joint_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.base = 0;
      u_has_position_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_position_limits = u_has_position_limits.real;
      offset += sizeof(this->has_position_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_position));
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.base = 0;
      u_has_velocity_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_velocity_limits = u_has_velocity_limits.real;
      offset += sizeof(this->has_velocity_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_velocity));
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.base = 0;
      u_has_acceleration_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_acceleration_limits = u_has_acceleration_limits.real;
      offset += sizeof(this->has_acceleration_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_acceleration));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/JointLimits"; };
    const char * getMD5(){ return "8ca618c7329ea46142cbc864a2efe856"; };

  };

}
#endif