#ifndef _ROS_sensor_msgs_Temperature_h
#define _ROS_sensor_msgs_Temperature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Temperature : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float temperature;
      float variance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->variance));
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Temperature"; };
    const char * getMD5(){ return "ff71b307acdbe7c871a5a6d7ed359100"; };

  };

}
#endif