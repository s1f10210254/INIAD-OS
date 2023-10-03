#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

void *client_thread(void *arg){

    char buf[1024];
    int clientfd =(int)(intptr_t)arg;
    int len,i,wlen;
    int er;

    char hostname[128];
    char portname[128];

    struct sockaddr_storage addr;
    socklen_t socklen =sizeof(addr);

    er =getpeername(clientfd,(struct sockaddr *)&addr, &socklen);
    if(er !=0) goto error;

    er =getnameinfo((struct sockaddr *)&addr, socklen,hostname,sizeof(hostname),portname,sizeof(portname),NI_NAMEREQD);
    if(er !=0) goto error;

    len =sprintf(buf,"Yur address is %s at port %s\n",hostname,portname);

    close(clientfd);
    return NULL;
}