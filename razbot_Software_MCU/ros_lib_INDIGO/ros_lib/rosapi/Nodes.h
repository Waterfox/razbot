#ifndef _ROS_SERVICE_Nodes_h
#define _ROS_SERVICE_Nodes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char NODES[] = "rosapi/Nodes";

  class NodesRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NodesResponse : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      char* st_nodes;
      char* * nodes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = nodes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < nodes_length; i++){
      uint32_t length_nodesi = strlen(this->nodes[i]);
      memcpy(outbuffer + offset, &length_nodesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_nodesi);
      offset += length_nodesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t nodes_lengthT = *(inbuffer + offset++);
      if(nodes_lengthT > nodes_length)
        this->nodes = (char**)realloc(this->nodes, nodes_lengthT * sizeof(char*));
      offset += 3;
      nodes_length = nodes_lengthT;
      for( uint8_t i = 0; i < nodes_length; i++){
      uint32_t length_st_nodes;
      memcpy(&length_st_nodes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_nodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_nodes-1]=0;
      this->st_nodes = (char *)(inbuffer + offset-1);
      offset += length_st_nodes;
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "3d07bfda1268b4f76b16b7ba8a82665d"; };

  };

  class Nodes {
    public:
    typedef NodesRequest Request;
    typedef NodesResponse Response;
  };

}
#endif
