#ifndef _ROS_sensor_msgs_CameraInfo_h
#define _ROS_sensor_msgs_CameraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/RegionOfInterest.h"

namespace sensor_msgs
{

  class CameraInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t height;
      uint32_t width;
      const char* distortion_model;
      uint8_t D_length;
      float st_D;
      float * D;
      float K[9];
      float R[9];
      float P[12];
      uint32_t binning_x;
      uint32_t binning_y;
      sensor_msgs::RegionOfInterest roi;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_distortion_model = strlen(this->distortion_model);
      memcpy(outbuffer + offset, &length_distortion_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->distortion_model, length_distortion_model);
      offset += length_distortion_model;
      *(outbuffer + offset++) = D_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < D_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->D[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->K[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->R[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->P[i]);
      }
      *(outbuffer + offset + 0) = (this->binning_x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_x);
      *(outbuffer + offset + 0) = (this->binning_y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_y);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t length_distortion_model;
      memcpy(&length_distortion_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_distortion_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_distortion_model-1]=0;
      this->distortion_model = (char *)(inbuffer + offset-1);
      offset += length_distortion_model;
      uint8_t D_lengthT = *(inbuffer + offset++);
      if(D_lengthT > D_length)
        this->D = (float*)realloc(this->D, D_lengthT * sizeof(float));
      offset += 3;
      D_length = D_lengthT;
      for( uint8_t i = 0; i < D_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_D));
        memcpy( &(this->D[i]), &(this->st_D), sizeof(float));
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->K[i]));
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->R[i]));
      }
      for( uint8_t i = 0; i < 12; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->P[i]));
      }
      this->binning_x =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_x);
      this->binning_y =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_y);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/CameraInfo"; };
    const char * getMD5(){ return "c9a58c1b0b154e0e6da7578cb991d214"; };

  };

}
#endif