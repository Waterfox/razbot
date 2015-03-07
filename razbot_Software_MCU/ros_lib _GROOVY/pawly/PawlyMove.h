#ifndef _ROS_pawly_PawlyMove_h
#define _ROS_pawly_PawlyMove_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pawly
{

  class PawlyMove : public ros::Msg
  {
    public:
      int16_t left_throttle;
      int16_t right_throttle;
      int16_t velocity;
      float radians;
      int16_t joystick_x;
      int16_t joystick_y;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.real = this->left_throttle;
      *(outbuffer + offset + 0) = (u_left_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.real = this->right_throttle;
      *(outbuffer + offset + 0) = (u_right_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_radians;
      u_radians.real = this->radians;
      *(outbuffer + offset + 0) = (u_radians.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radians.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radians.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radians.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radians);
      union {
        int16_t real;
        uint16_t base;
      } u_joystick_x;
      u_joystick_x.real = this->joystick_x;
      *(outbuffer + offset + 0) = (u_joystick_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joystick_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->joystick_x);
      union {
        int16_t real;
        uint16_t base;
      } u_joystick_y;
      u_joystick_y.real = this->joystick_y;
      *(outbuffer + offset + 0) = (u_joystick_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joystick_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->joystick_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.base = 0;
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_throttle = u_left_throttle.real;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.base = 0;
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_throttle = u_right_throttle.real;
      offset += sizeof(this->right_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_radians;
      u_radians.base = 0;
      u_radians.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radians.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radians.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radians.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radians = u_radians.real;
      offset += sizeof(this->radians);
      union {
        int16_t real;
        uint16_t base;
      } u_joystick_x;
      u_joystick_x.base = 0;
      u_joystick_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_joystick_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->joystick_x = u_joystick_x.real;
      offset += sizeof(this->joystick_x);
      union {
        int16_t real;
        uint16_t base;
      } u_joystick_y;
      u_joystick_y.base = 0;
      u_joystick_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_joystick_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->joystick_y = u_joystick_y.real;
      offset += sizeof(this->joystick_y);
     return offset;
    }

    const char * getType(){ return "pawly/PawlyMove"; };
    const char * getMD5(){ return "8150261c37df94dd6f372cd9ffda04fe"; };

  };

}
#endif