#ifndef _ROS_sensor_msgs_Imu_h
#define _ROS_sensor_msgs_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace sensor_msgs
{

  class Imu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Quaternion orientation;
      float orientation_covariance[9];
      geometry_msgs::Vector3 angular_velocity;
      float angular_velocity_covariance[9];
      geometry_msgs::Vector3 linear_acceleration;
      float linear_acceleration_covariance[9];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_covariance[i]);
      }
      offset += this->angular_velocity.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity_covariance[i]);
      }
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_acceleration_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_covariance[i]));
      }
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity_covariance[i]));
      }
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_acceleration_covariance[i]));
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Imu"; };
    const char * getMD5(){ return "6a62c6daae103f4ff57a132d6f95cec2"; };

  };

}
#endif