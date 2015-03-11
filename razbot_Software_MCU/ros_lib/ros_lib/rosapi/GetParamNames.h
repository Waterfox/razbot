#ifndef _ROS_SERVICE_GetParamNames_h
#define _ROS_SERVICE_GetParamNames_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char GETPARAMNAMES[] = "rosapi/GetParamNames";

  class GetParamNamesRequest : public ros::Msg
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

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetParamNamesResponse : public ros::Msg
  {
    public:
      uint8_t names_length;
      char* st_names;
      char* * names;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      memcpy(outbuffer + offset, &length_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t names_lengthT = *(inbuffer + offset++);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      offset += 3;
      names_length = names_lengthT;
      for( uint8_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      memcpy(&length_st_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "dc7ae3609524b18034e49294a4ce670e"; };

  };

  class GetParamNames {
    public:
    typedef GetParamNamesRequest Request;
    typedef GetParamNamesResponse Response;
  };

}
#endif
