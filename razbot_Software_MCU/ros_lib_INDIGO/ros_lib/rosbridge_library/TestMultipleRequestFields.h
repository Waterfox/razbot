#ifndef _ROS_SERVICE_TestMultipleRequestFields_h
#define _ROS_SERVICE_TestMultipleRequestFields_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosbridge_library
{

static const char TESTMULTIPLEREQUESTFIELDS[] = "rosbridge_library/TestMultipleRequestFields";

  class TestMultipleRequestFieldsRequest : public ros::Msg
  {
    public:
      int32_t int;
      float float;
      const char* string;
      bool bool;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_int;
      u_int.real = this->int;
      *(outbuffer + offset + 0) = (u_int.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->int);
      union {
        float real;
        uint32_t base;
      } u_float;
      u_float.real = this->float;
      *(outbuffer + offset + 0) = (u_float.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_float.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_float.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_float.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->float);
      uint32_t length_string = strlen(this->string);
      memcpy(outbuffer + offset, &length_string, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->string, length_string);
      offset += length_string;
      union {
        bool real;
        uint8_t base;
      } u_bool;
      u_bool.real = this->bool;
      *(outbuffer + offset + 0) = (u_bool.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bool);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_int;
      u_int.base = 0;
      u_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->int = u_int.real;
      offset += sizeof(this->int);
      union {
        float real;
        uint32_t base;
      } u_float;
      u_float.base = 0;
      u_float.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_float.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_float.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_float.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->float = u_float.real;
      offset += sizeof(this->float);
      uint32_t length_string;
      memcpy(&length_string, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_string-1]=0;
      this->string = (char *)(inbuffer + offset-1);
      offset += length_string;
      union {
        bool real;
        uint8_t base;
      } u_bool;
      u_bool.base = 0;
      u_bool.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bool = u_bool.real;
      offset += sizeof(this->bool);
     return offset;
    }

    const char * getType(){ return TESTMULTIPLEREQUESTFIELDS; };
    const char * getMD5(){ return "6cce9fb727dd0f31d504d7d198a1f4ef"; };

  };

  class TestMultipleRequestFieldsResponse : public ros::Msg
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

    const char * getType(){ return TESTMULTIPLEREQUESTFIELDS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TestMultipleRequestFields {
    public:
    typedef TestMultipleRequestFieldsRequest Request;
    typedef TestMultipleRequestFieldsResponse Response;
  };

}
#endif
