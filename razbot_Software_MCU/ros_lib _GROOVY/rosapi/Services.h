#ifndef _ROS_SERVICE_Services_h
#define _ROS_SERVICE_Services_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char SERVICES[] = "rosapi/Services";

  class ServicesRequest : public ros::Msg
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

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ServicesResponse : public ros::Msg
  {
    public:
      uint8_t services_length;
      char* st_services;
      char* * services;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = services_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < services_length; i++){
      uint32_t length_servicesi = strlen(this->services[i]);
      memcpy(outbuffer + offset, &length_servicesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->services[i], length_servicesi);
      offset += length_servicesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t services_lengthT = *(inbuffer + offset++);
      if(services_lengthT > services_length)
        this->services = (char**)realloc(this->services, services_lengthT * sizeof(char*));
      offset += 3;
      services_length = services_lengthT;
      for( uint8_t i = 0; i < services_length; i++){
      uint32_t length_st_services;
      memcpy(&length_st_services, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_services; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_services-1]=0;
      this->st_services = (char *)(inbuffer + offset-1);
      offset += length_st_services;
        memcpy( &(this->services[i]), &(this->st_services), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "e44a7e7bcb900acadbcc28b132378f0c"; };

  };

  class Services {
    public:
    typedef ServicesRequest Request;
    typedef ServicesResponse Response;
  };

}
#endif
