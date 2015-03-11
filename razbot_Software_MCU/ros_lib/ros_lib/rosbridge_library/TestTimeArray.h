#ifndef _ROS_rosbridge_library_TestTimeArray_h
#define _ROS_rosbridge_library_TestTimeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rosbridge_library
{

  class TestTimeArray : public ros::Msg
  {
    public:
      uint8_t times_length;
      ros::Time st_times;
      ros::Time * times;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = times_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < times_length; i++){
      *(outbuffer + offset + 0) = (this->times[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->times[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->times[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->times[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->times[i].sec);
      *(outbuffer + offset + 0) = (this->times[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->times[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->times[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->times[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->times[i].nsec);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t times_lengthT = *(inbuffer + offset++);
      if(times_lengthT > times_length)
        this->times = (ros::Time*)realloc(this->times, times_lengthT * sizeof(ros::Time));
      offset += 3;
      times_length = times_lengthT;
      for( uint8_t i = 0; i < times_length; i++){
      this->st_times.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_times.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_times.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_times.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_times.sec);
      this->st_times.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_times.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_times.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_times.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_times.nsec);
        memcpy( &(this->times[i]), &(this->st_times), sizeof(ros::Time));
      }
     return offset;
    }

    const char * getType(){ return "rosbridge_library/TestTimeArray"; };
    const char * getMD5(){ return "237b97d24fd33588beee4cd8978b149d"; };

  };

}
#endif