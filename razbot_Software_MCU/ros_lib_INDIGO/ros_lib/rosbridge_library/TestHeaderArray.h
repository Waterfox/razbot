#ifndef _ROS_rosbridge_library_TestHeaderArray_h
#define _ROS_rosbridge_library_TestHeaderArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rosbridge_library
{

  class TestHeaderArray : public ros::Msg
  {
    public:
      uint8_t header_length;
      std_msgs::Header st_header;
      std_msgs::Header * header;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = header_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < header_length; i++){
      offset += this->header[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t header_lengthT = *(inbuffer + offset++);
      if(header_lengthT > header_length)
        this->header = (std_msgs::Header*)realloc(this->header, header_lengthT * sizeof(std_msgs::Header));
      offset += 3;
      header_length = header_lengthT;
      for( uint8_t i = 0; i < header_length; i++){
      offset += this->st_header.deserialize(inbuffer + offset);
        memcpy( &(this->header[i]), &(this->st_header), sizeof(std_msgs::Header));
      }
     return offset;
    }

    const char * getType(){ return "rosbridge_library/TestHeaderArray"; };
    const char * getMD5(){ return "d7be0bb39af8fb9129d5a76e6b63a290"; };

  };

}
#endif