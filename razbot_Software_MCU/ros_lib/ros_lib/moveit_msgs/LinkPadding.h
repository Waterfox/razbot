#ifndef _ROS_moveit_msgs_LinkPadding_h
#define _ROS_moveit_msgs_LinkPadding_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class LinkPadding : public ros::Msg
  {
    public:
      const char* link_name;
      float padding;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->padding);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->padding));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/LinkPadding"; };
    const char * getMD5(){ return "b3ea75670df55c696fedee97774d5947"; };

  };

}
#endif