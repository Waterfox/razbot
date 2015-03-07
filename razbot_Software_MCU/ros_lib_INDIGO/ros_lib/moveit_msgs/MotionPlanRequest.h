#ifndef _ROS_moveit_msgs_MotionPlanRequest_h
#define _ROS_moveit_msgs_MotionPlanRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/WorkspaceParameters.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/Constraints.h"
#include "moveit_msgs/TrajectoryConstraints.h"

namespace moveit_msgs
{

  class MotionPlanRequest : public ros::Msg
  {
    public:
      moveit_msgs::WorkspaceParameters workspace_parameters;
      moveit_msgs::RobotState start_state;
      uint8_t goal_constraints_length;
      moveit_msgs::Constraints st_goal_constraints;
      moveit_msgs::Constraints * goal_constraints;
      moveit_msgs::Constraints path_constraints;
      moveit_msgs::TrajectoryConstraints trajectory_constraints;
      const char* planner_id;
      const char* group_name;
      int32_t num_planning_attempts;
      float allowed_planning_time;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->workspace_parameters.serialize(outbuffer + offset);
      offset += this->start_state.serialize(outbuffer + offset);
      *(outbuffer + offset++) = goal_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < goal_constraints_length; i++){
      offset += this->goal_constraints[i].serialize(outbuffer + offset);
      }
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->trajectory_constraints.serialize(outbuffer + offset);
      uint32_t length_planner_id = strlen(this->planner_id);
      memcpy(outbuffer + offset, &length_planner_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_planner_id);
      offset += length_planner_id;
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_num_planning_attempts;
      u_num_planning_attempts.real = this->num_planning_attempts;
      *(outbuffer + offset + 0) = (u_num_planning_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_planning_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_planning_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_planning_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_planning_attempts);
      offset += serializeAvrFloat64(outbuffer + offset, this->allowed_planning_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->workspace_parameters.deserialize(inbuffer + offset);
      offset += this->start_state.deserialize(inbuffer + offset);
      uint8_t goal_constraints_lengthT = *(inbuffer + offset++);
      if(goal_constraints_lengthT > goal_constraints_length)
        this->goal_constraints = (moveit_msgs::Constraints*)realloc(this->goal_constraints, goal_constraints_lengthT * sizeof(moveit_msgs::Constraints));
      offset += 3;
      goal_constraints_length = goal_constraints_lengthT;
      for( uint8_t i = 0; i < goal_constraints_length; i++){
      offset += this->st_goal_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->goal_constraints[i]), &(this->st_goal_constraints), sizeof(moveit_msgs::Constraints));
      }
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->trajectory_constraints.deserialize(inbuffer + offset);
      uint32_t length_planner_id;
      memcpy(&length_planner_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_id-1]=0;
      this->planner_id = (char *)(inbuffer + offset-1);
      offset += length_planner_id;
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_num_planning_attempts;
      u_num_planning_attempts.base = 0;
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_planning_attempts = u_num_planning_attempts.real;
      offset += sizeof(this->num_planning_attempts);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->allowed_planning_time));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionPlanRequest"; };
    const char * getMD5(){ return "7cd790e04c3a55f6742ec387a72a02d6"; };

  };

}
#endif