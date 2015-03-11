#ifndef _ROS_SERVICE_SendBytes_h
#define _ROS_SERVICE_SendBytes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosbridge_library
{

static const char SENDBYTES[] = "rosbridge_library/SendBytes";

  class SendBytesRequest : public ros::Msg
  {
    public:
      int64_t count;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_count.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_count.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_count.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_count.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->count = u_count.real;
      offset += sizeof(this->count);
     return offset;
    }

    const char * getType(){ return SENDBYTES; };
    const char * getMD5(){ return "8dbac33d2eb67bfeeedd516d65fec846"; };

  };

  class SendBytesResponse : public ros::Msg
  {
    public:
      const char* data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      memcpy(outbuffer + offset, &length_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_data;
      memcpy(&length_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
     return offset;
    }

    const char * getType(){ return SENDBYTES; };
    const char * getMD5(){ return "992ce8a1687cec8c8bd883ec73ca41d1"; };

  };

  class SendBytes {
    public:
    typedef SendBytesRequest Request;
    typedef SendBytesResponse Response;
  };

}
#endif
