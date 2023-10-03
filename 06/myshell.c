#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
    char s[256];
    char* cmd[128];

    while (gets(s) != NULL)
    {
        for (int i =0;; i++){
            cmd[i] = strtok((i ==0) ? s : NULL, " \n\r\t");
            if (cmd[i] == NULL){
                break;
            }
        }
        pid_t pid = fork();
        if(pid >0){
            //親プロセス
        }
        else{
            //子プロセス
            execvp(cmd[0], cmd);
            return -1;
        }
    }
    
}