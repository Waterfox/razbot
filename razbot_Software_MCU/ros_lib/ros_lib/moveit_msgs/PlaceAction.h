#ifndef _ROS_moveit_msgs_PlaceAction_h
#define _ROS_moveit_msgs_PlaceAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlaceActionGoal.h"
#include "moveit_msgs/PlaceActionResult.h"
#include "moveit_msgs/PlaceActionFeedback.h"

namespace moveit_msgs
{

  class PlaceAction : public ros::Msg
  {
    public:
      moveit_msgs::PlaceActionGoal action_goal;
      moveit_msgs::PlaceActionResult action_result;
      moveit_msgs::PlaceActionFeedback action_feedback;

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

    const char * getType(){ return "moveit_msgs/PlaceAction"; };
    const char * getMD5(){ return "28cb4b6b7c2a211726c2c78386a9da69"; };

  };

}
#endif