#ifndef _ROS_rosapi_TypeDef_h
#define _ROS_rosapi_TypeDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

  class TypeDef : public ros::Msg
  {
    public:
      const char* type;
      uint8_t fieldnames_length;
      char* st_fieldnames;
      char* * fieldnames;
      uint8_t fieldtypes_length;
      char* st_fieldtypes;
      char* * fieldtypes;
      uint8_t fieldarraylen_length;
      int32_t st_fieldarraylen;
      int32_t * fieldarraylen;
      uint8_t examples_length;
      char* st_examples;
      char* * examples;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset++) = fieldnames_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fieldnames_length; i++){
      uint32_t length_fieldnamesi = strlen(this->fieldnames[i]);
      memcpy(outbuffer + offset, &length_fieldnamesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fieldnames[i], length_fieldnamesi);
      offset += length_fieldnamesi;
      }
      *(outbuffer + offset++) = fieldtypes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fieldtypes_length; i++){
      uint32_t length_fieldtypesi = strlen(this->fieldtypes[i]);
      memcpy(outbuffer + offset, &length_fieldtypesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fieldtypes[i], length_fieldtypesi);
      offset += length_fieldtypesi;
      }
      *(outbuffer + offset++) = fieldarraylen_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fieldarraylen_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_fieldarrayleni;
      u_fieldarrayleni.real = this->fieldarraylen[i];
      *(outbuffer + offset + 0) = (u_fieldarrayleni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fieldarrayleni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fieldarrayleni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fieldarrayleni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fieldarraylen[i]);
      }
      *(outbuffer + offset++) = examples_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < examples_length; i++){
      uint32_t length_examplesi = strlen(this->examples[i]);
      memcpy(outbuffer + offset, &length_examplesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->examples[i], length_examplesi);
      offset += length_examplesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint8_t fieldnames_lengthT = *(inbuffer + offset++);
      if(fieldnames_lengthT > fieldnames_length)
        this->fieldnames = (char**)realloc(this->fieldnames, fieldnames_lengthT * sizeof(char*));
      offset += 3;
      fieldnames_length = fieldnames_lengthT;
      for( uint8_t i = 0; i < fieldnames_length; i++){
      uint32_t length_st_fieldnames;
      memcpy(&length_st_fieldnames, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fieldnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fieldnames-1]=0;
      this->st_fieldnames = (char *)(inbuffer + offset-1);
      offset += length_st_fieldnames;
        memcpy( &(this->fieldnames[i]), &(this->st_fieldnames), sizeof(char*));
      }
      uint8_t fieldtypes_lengthT = *(inbuffer + offset++);
      if(fieldtypes_lengthT > fieldtypes_length)
        this->fieldtypes = (char**)realloc(this->fieldtypes, fieldtypes_lengthT * sizeof(char*));
      offset += 3;
      fieldtypes_length = fieldtypes_lengthT;
      for( uint8_t i = 0; i < fieldtypes_length; i++){
      uint32_t length_st_fieldtypes;
      memcpy(&length_st_fieldtypes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fieldtypes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fieldtypes-1]=0;
      this->st_fieldtypes = (char *)(inbuffer + offset-1);
      offset += length_st_fieldtypes;
        memcpy( &(this->fieldtypes[i]), &(this->st_fieldtypes), sizeof(char*));
      }
      uint8_t fieldarraylen_lengthT = *(inbuffer + offset++);
      if(fieldarraylen_lengthT > fieldarraylen_length)
        this->fieldarraylen = (int32_t*)realloc(this->fieldarraylen, fieldarraylen_lengthT * sizeof(int32_t));
      offset += 3;
      fieldarraylen_length = fieldarraylen_lengthT;
      for( uint8_t i = 0; i < fieldarraylen_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_fieldarraylen;
      u_st_fieldarraylen.base = 0;
      u_st_fieldarraylen.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fieldarraylen.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fieldarraylen.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fieldarraylen.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fieldarraylen = u_st_fieldarraylen.real;
      offset += sizeof(this->st_fieldarraylen);
        memcpy( &(this->fieldarraylen[i]), &(this->st_fieldarraylen), sizeof(int32_t));
      }
      uint8_t examples_lengthT = *(inbuffer + offset++);
      if(examples_lengthT > examples_length)
        this->examples = (char**)realloc(this->examples, examples_lengthT * sizeof(char*));
      offset += 3;
      examples_length = examples_lengthT;
      for( uint8_t i = 0; i < examples_length; i++){
      uint32_t length_st_examples;
      memcpy(&length_st_examples, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_examples; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_examples-1]=0;
      this->st_examples = (char *)(inbuffer + offset-1);
      offset += length_st_examples;
        memcpy( &(this->examples[i]), &(this->st_examples), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "rosapi/TypeDef"; };
    const char * getMD5(){ return "bd8529b0edb168fde8dd58032743f1f7"; };

  };

}
#endif