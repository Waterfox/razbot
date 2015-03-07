#ifndef _ROS_SERVICE_GetParam_h
#define _ROS_SERVICE_GetParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char GETPARAM[] = "rosapi/GetParam";

  class GetParamRequest : public ros::Msg
  {
    public:
      const char* name;
      const char* default;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_default = strlen(this->default);
      memcpy(outbuffer + offset, &length_default, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->default, length_default);
      offset += length_default;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_default;
      memcpy(&length_default, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_default; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_default-1]=0;
      this->default = (char *)(inbuffer + offset-1);
      offset += length_default;
     return offset;
    }

    const char * getType(){ return GETPARAM; };
    const char * getMD5(){ return "1cc3f281ee24ba9406c3e498e4da686f"; };

  };

  class GetParamResponse : public ros::Msg
  {
    public:
      const char* value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      memcpy(outbuffer + offset, &length_value, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_value;
      memcpy(&length_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    const char * getType(){ return GETPARAM; };
    const char * getMD5(){ return "64e58419496c7248b4ef25731f88b8c3"; };

  };

  class GetParam {
    public:
    typedef GetParamRequest Request;
    typedef GetParamResponse Response;
  };

}
#endif
