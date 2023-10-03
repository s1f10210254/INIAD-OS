#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Usage: mywc <file>\n");
        return 1;
    }

    //argv[1] : ファイル名


    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        fprintf(stderr, "ERROR\n");
        return 1;
    }

    char buf[1024];
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
    for(;;){
        ssize_t len = read(fd, buf, sizeof(buf));
        if(len <=0){
        //len == 1:　ファイルの末尾に達した
        //len < 0　読み込みエラー
        break;
        }


        // buf[0] ~ [len-1]
        for(int i=0; i < len; i++){
            if (buf[i] == '\n'){
                line_count++;
            }   
        }
        ...  
    }
    
    close(fd);
    printf("%d %d %d %s\n", line_count,word_count,char_count, argv[1]);

    return 0;
}

