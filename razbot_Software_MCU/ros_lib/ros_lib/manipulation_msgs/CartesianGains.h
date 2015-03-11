#ifndef _ROS_manipulation_msgs_CartesianGains_h
#define _ROS_manipulation_msgs_CartesianGains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace manipulation_msgs
{

  class CartesianGains : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t gains_length;
      float st_gains;
      float * gains;
      uint8_t fixed_frame_length;
      float st_fixed_frame;
      float * fixed_frame;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = gains_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gains_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gains[i]);
      }
      *(outbuffer + offset++) = fixed_frame_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fixed_frame_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->fixed_frame[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t gains_lengthT = *(inbuffer + offset++);
      if(gains_lengthT > gains_length)
        this->gains = (float*)realloc(this->gains, gains_lengthT * sizeof(float));
      offset += 3;
      gains_length = gains_lengthT;
      for( uint8_t i = 0; i < gains_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_gains));
        memcpy( &(this->gains[i]), &(this->st_gains), sizeof(float));
      }
      uint8_t fixed_frame_lengthT = *(inbuffer + offset++);
      if(fixed_frame_lengthT > fixed_frame_length)
        this->fixed_frame = (float*)realloc(this->fixed_frame, fixed_frame_lengthT * sizeof(float));
      offset += 3;
      fixed_frame_length = fixed_frame_lengthT;
      for( uint8_t i = 0; i < fixed_frame_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_fixed_frame));
        memcpy( &(this->fixed_frame[i]), &(this->st_fixed_frame), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/CartesianGains"; };
    const char * getMD5(){ return "ab347f046ca5736a156ec424cbb63635"; };

  };

}
#endif