#ifndef _ROS_rosbridge_library_TestHeaderTwo_h
#define _ROS_rosbridge_library_TestHeaderTwo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rosbridge_library
{

  class TestHeaderTwo : public ros::Msg
  {
    public:
      std_msgs::Header header;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rosbridge_library/TestHeaderTwo"; };
    const char * getMD5(){ return "d7be0bb39af8fb9129d5a76e6b63a290"; };

  };

}
#endif