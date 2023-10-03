#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[])
{
    int src , dst;
    char buf[BUF_SIZE];
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: filecopy <src> <dest>\n");
        return 1;
    }

    src = open(argv[1], O_RDONLY);
    if (src < 0) goto error;
    
    dst = open(argv[2], O_WRONLY, 0777);
    if (!dst) goto error;

    for (;;) {
        size_t cnt;

        cnt = read(src, buf, sizeof(buf));
        if (cnt <= 0) break;

        //dstにbufにあるcntバイトのデータを書き込む
        for(i=0; i < cnt; ){
            dst = write(dst, buf + 1,sizeof(buf)-i);
            i += dst;
        }
        
    }

    close(dst);
    close(src);
    return 0;

 error:
    if (dst) close(dst);
    if (src) close(src);
    fprintf(stderr, "ERROR\n");
    return 1;
}