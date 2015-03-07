#ifndef _ROS_SERVICE_TestNestedService_h
#define _ROS_SERVICE_TestNestedService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Float64.h"

namespace rosbridge_library
{

static const char TESTNESTEDSERVICE[] = "rosbridge_library/TestNestedService";

  class TestNestedServiceRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TESTNESTEDSERVICE; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class TestNestedServiceResponse : public ros::Msg
  {
    public:
      std_msgs::Float64 data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TESTNESTEDSERVICE; };
    const char * getMD5(){ return "8d62201b2d01a4931eec14d19d9c5317"; };

  };

  class TestNestedService {
    public:
    typedef TestNestedServiceRequest Request;
    typedef TestNestedServiceResponse Response;
  };

}
#endif
