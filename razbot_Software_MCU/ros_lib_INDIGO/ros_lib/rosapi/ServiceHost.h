#ifndef _ROS_SERVICE_ServiceHost_h
#define _ROS_SERVICE_ServiceHost_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char SERVICEHOST[] = "rosapi/ServiceHost";

  class ServiceHostRequest : public ros::Msg
  {
    public:
      const char* service;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_service = strlen(this->service);
      memcpy(outbuffer + offset, &length_service, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->service, length_service);
      offset += length_service;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service;
      memcpy(&length_service, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service-1]=0;
      this->service = (char *)(inbuffer + offset-1);
      offset += length_service;
     return offset;
    }

    const char * getType(){ return SERVICEHOST; };
    const char * getMD5(){ return "1cbcfa13b08f6d36710b9af8741e6112"; };

  };

  class ServiceHostResponse : public ros::Msg
  {
    public:
      const char* host;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_host = strlen(this->host);
      memcpy(outbuffer + offset, &length_host, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->host, length_host);
      offset += length_host;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_host;
      memcpy(&length_host, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_host; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_host-1]=0;
      this->host = (char *)(inbuffer + offset-1);
      offset += length_host;
     return offset;
    }

    const char * getType(){ return SERVICEHOST; };
    const char * getMD5(){ return "092ff9f63242a37704ce411703ec5eaf"; };

  };

  class ServiceHost {
    public:
    typedef ServiceHostRequest Request;
    typedef ServiceHostResponse Response;
  };

}
#endif
