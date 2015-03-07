#ifndef _ROS_moveit_msgs_PickupAction_h
#define _ROS_moveit_msgs_PickupAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PickupActionGoal.h"
#include "moveit_msgs/PickupActionResult.h"
#include "moveit_msgs/PickupActionFeedback.h"

namespace moveit_msgs
{

  class PickupAction : public ros::Msg
  {
    public:
      moveit_msgs::PickupActionGoal action_goal;
      moveit_msgs::PickupActionResult action_result;
      moveit_msgs::PickupActionFeedback action_feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PickupAction"; };
    const char * getMD5(){ return "f5aa574f57e5d9cf7d466d5913039489"; };

  };

}
#endif