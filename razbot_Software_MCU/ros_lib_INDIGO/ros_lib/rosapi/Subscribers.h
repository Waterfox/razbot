#ifndef _ROS_SERVICE_Subscribers_h
#define _ROS_SERVICE_Subscribers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char SUBSCRIBERS[] = "rosapi/Subscribers";

  class SubscribersRequest : public ros::Msg
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

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class SubscribersResponse : public ros::Msg
  {
    public:
      uint8_t subscribers_length;
      char* st_subscribers;
      char* * subscribers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = subscribers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < subscribers_length; i++){
      uint32_t length_subscribersi = strlen(this->subscribers[i]);
      memcpy(outbuffer + offset, &length_subscribersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->subscribers[i], length_subscribersi);
      offset += length_subscribersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t subscribers_lengthT = *(inbuffer + offset++);
      if(subscribers_lengthT > subscribers_length)
        this->subscribers = (char**)realloc(this->subscribers, subscribers_lengthT * sizeof(char*));
      offset += 3;
      subscribers_length = subscribers_lengthT;
      for( uint8_t i = 0; i < subscribers_length; i++){
      uint32_t length_st_subscribers;
      memcpy(&length_st_subscribers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_subscribers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_subscribers-1]=0;
      this->st_subscribers = (char *)(inbuffer + offset-1);
      offset += length_st_subscribers;
        memcpy( &(this->subscribers[i]), &(this->st_subscribers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "22418cab5ba9531d8c2b738b4e56153b"; };

  };

  class Subscribers {
    public:
    typedef SubscribersRequest Request;
    typedef SubscribersResponse Response;
  };

}
#endif
