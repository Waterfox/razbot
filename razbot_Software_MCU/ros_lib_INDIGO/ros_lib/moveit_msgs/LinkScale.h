#ifndef _ROS_moveit_msgs_LinkScale_h
#define _ROS_moveit_msgs_LinkScale_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class LinkScale : public ros::Msg
  {
    public:
      const char* link_name;
      float scale;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->scale));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/LinkScale"; };
    const char * getMD5(){ return "19faf226446bfb2f645a4da6f2a56166"; };

  };

}
#endif