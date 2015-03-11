#ifndef _ROS_move_base_msgs_MoveBaseActionFeedback_h
#define _ROS_move_base_msgs_MoveBaseActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "move_base_msgs/MoveBaseFeedback.h"

namespace move_base_msgs
{

  class MoveBaseActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      move_base_msgs::MoveBaseFeedback feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "move_base_msgs/MoveBaseActionFeedback"; };
    const char * getMD5(){ return "7d1870ff6e0decea702b943b5af0b42e"; };

  };

}
#endif