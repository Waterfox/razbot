#ifndef _ROS_geometry_msgs_Vector3_h
#define _ROS_geometry_msgs_Vector3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace geometry_msgs
{

  class Vector3 : public ros::Msg
  {
    public:
      float x;
      float y;
      float z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Vector3"; };
    const char * getMD5(){ return "4a842b65f413084dc2b10fb484ea7f17"; };

  };

}
#endif