#ifndef _ROS_rosbridge_library_TestUInt8FixedSizeArray16_h
#define _ROS_rosbridge_library_TestUInt8FixedSizeArray16_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosbridge_library
{

  class TestUInt8FixedSizeArray16 : public ros::Msg
  {
    public:
      uint8_t data[16];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "rosbridge_library/TestUInt8FixedSizeArray16"; };
    const char * getMD5(){ return "a4e84d0a73514dfe9696b4796e8755e7"; };

  };

}
#endif