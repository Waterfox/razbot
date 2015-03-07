#ifndef _ROS_sensor_msgs_Illuminance_h
#define _ROS_sensor_msgs_Illuminance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Illuminance : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float illuminance;
      float variance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->illuminance);
      offset += serializeAvrFloat64(outbuffer + offset, this->variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->illuminance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->variance));
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Illuminance"; };
    const char * getMD5(){ return "8cf5febb0952fca9d650c3d11a81a188"; };

  };

}
#endif