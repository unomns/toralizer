//
//  toralize.c
//  toralizer
//
//  Created by Murad Nurmukhamedov on 1/6/25.
//

#include "toralizer.h"

int toralize(int argc, char *argv[]) {
    char *host;
    int port, s;
    struct sockaddr_in sock;
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        
        return -1;
    }
    
    host = argv[1];
    port = atoi(argv[2]);
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");
        
        return -1;
    }
    
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);
    
    if (connect(s, (struct sockaddr *)&sock, sizeof(sock)) != 0) {
        close(s);
        perror("connect");
        
        return -1;
    }
    
    printf("Connected to proxy\n");
    close(s);
    
    return 0;
}
