#ifndef _ROS_SERVICE_Publishers_h
#define _ROS_SERVICE_Publishers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char PUBLISHERS[] = "rosapi/Publishers";

  class PublishersRequest : public ros::Msg
  {
    public:
      const char* topic;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      memcpy(outbuffer + offset, &length_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      memcpy(&length_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class PublishersResponse : public ros::Msg
  {
    public:
      uint8_t publishers_length;
      char* st_publishers;
      char* * publishers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = publishers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < publishers_length; i++){
      uint32_t length_publishersi = strlen(this->publishers[i]);
      memcpy(outbuffer + offset, &length_publishersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->publishers[i], length_publishersi);
      offset += length_publishersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t publishers_lengthT = *(inbuffer + offset++);
      if(publishers_lengthT > publishers_length)
        this->publishers = (char**)realloc(this->publishers, publishers_lengthT * sizeof(char*));
      offset += 3;
      publishers_length = publishers_lengthT;
      for( uint8_t i = 0; i < publishers_length; i++){
      uint32_t length_st_publishers;
      memcpy(&length_st_publishers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_publishers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_publishers-1]=0;
      this->st_publishers = (char *)(inbuffer + offset-1);
      offset += length_st_publishers;
        memcpy( &(this->publishers[i]), &(this->st_publishers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "167d8030c4ca4018261dff8ae5083dc8"; };

  };

  class Publishers {
    public:
    typedef PublishersRequest Request;
    typedef PublishersResponse Response;
  };

}
#endif
