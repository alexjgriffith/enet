/**
 @file  stub.h
 @brief ENet stub header for system specific functions
*/
#ifndef __ENET_STUB_H__
#define __ENET_STUB_H__

#ifdef _WIN32
#include <stdint.h>
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#ifdef MSG_MAXIOVLEN
#define ENET_BUFFER_MAXIMUM MSG_MAXIOVLEN
#endif

typedef void *ENetSocket;

#define ENET_SOCKET_NULL NULL

#define ENET_HOST_TO_NET_16(value) (htons(value)) /**< macro that converts host to net byte-order of a 16-bit value */
#define ENET_HOST_TO_NET_32(value) (htonl(value)) /**< macro that converts host to net byte-order of a 32-bit value */

#define ENET_NET_TO_HOST_16(value) (ntohs(value)) /**< macro that converts net to host byte-order of a 16-bit value */
#define ENET_NET_TO_HOST_32(value) (ntohl(value)) /**< macro that converts net to host byte-order of a 32-bit value */

typedef struct
{
        void *data;
        size_t dataLength;
} ENetBuffer;

#define ENET_CALLBACK

#define ENET_API extern

typedef void ENetSocketSet;

typedef struct _ENetAddress
{
   uint8_t host[16];
   uint16_t port;
   uint8_t wildcard;
} ENetAddress;

#define enet_host_equal(host_a, host_b) (memcmp(&host_a, &host_b,16) == 0)

#endif /* __ENET_STUB_H__ */
