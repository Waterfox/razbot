#ifndef _ROS_SERVICE_TestArrayRequest_h
#define _ROS_SERVICE_TestArrayRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosbridge_library
{

static const char TESTARRAYREQUEST[] = "rosbridge_library/TestArrayRequest";

  class TestArrayRequestRequest : public ros::Msg
  {
    public:
      uint8_t int_length;
      int32_t st_int;
      int32_t * int;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = int_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < int_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_inti;
      u_inti.real = this->int[i];
      *(outbuffer + offset + 0) = (u_inti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->int[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t int_lengthT = *(inbuffer + offset++);
      if(int_lengthT > int_length)
        this->int = (int32_t*)realloc(this->int, int_lengthT * sizeof(int32_t));
      offset += 3;
      int_length = int_lengthT;
      for( uint8_t i = 0; i < int_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_int;
      u_st_int.base = 0;
      u_st_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_int = u_st_int.real;
      offset += sizeof(this->st_int);
        memcpy( &(this->int[i]), &(this->st_int), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return TESTARRAYREQUEST; };
    const char * getMD5(){ return "3d7cfb7e4aa0844868966efa8a264398"; };

  };

  class TestArrayRequestResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TESTARRAYREQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TestArrayRequest {
    public:
    typedef TestArrayRequestRequest Request;
    typedef TestArrayRequestResponse Response;
  };

}
#endif
