#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    pid_t pid = fork();

    if (pid > 0){
        //親プロセス
        int ret;
        wait(&ret);
    }
    else{
        //pid == 0 子プロセス
        execve(arggv[1], ...);
    }

    return 0;
}
