//
//  toralize.h
//  toralizer
//
//  Created by Murad Nurmukhamedov on 1/6/25.
//

#ifndef toralize_h
#define toralize_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PROXY       "127.0.0.1"
#define PROXYPORT   9050

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct proxy_request {
    int8 vn;
    int8 cd;
    int16 dstport;
    int32 dstip;
    unsigned char userid[8];
};
typedef struct proxy_request Req;

struct proxy_response {
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;
};
typedef struct proxy_response Res;

int toralize(int argc, char *argv[]);

#endif /* toralize_h */
