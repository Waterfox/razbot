#ifndef _ROS_rosbridge_library_TestChar_h
#define _ROS_rosbridge_library_TestChar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosbridge_library
{

  class TestChar : public ros::Msg
  {
    public:
      uint8_t data_length;
      uint8_t st_data;
      uint8_t * data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "rosbridge_library/TestChar"; };
    const char * getMD5(){ return "7b8d15902c8b049d5a32b4cb73fa86f5"; };

  };

}
#endif