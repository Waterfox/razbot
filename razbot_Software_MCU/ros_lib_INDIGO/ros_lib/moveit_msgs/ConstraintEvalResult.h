#ifndef _ROS_moveit_msgs_ConstraintEvalResult_h
#define _ROS_moveit_msgs_ConstraintEvalResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class ConstraintEvalResult : public ros::Msg
  {
    public:
      bool result;
      float distance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ConstraintEvalResult"; };
    const char * getMD5(){ return "093643083d24f6488cb5a868bd47c090"; };

  };

}
#endif