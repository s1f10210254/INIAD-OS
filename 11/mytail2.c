#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
int main(int argc, char* argv[]){
    int er, i, count, fd = -1;
    struct stat fileinfo;
    char* map =NULL;

    if (argc !=2 && argc !=4){
        fprintf(stderr, "Usage: mytail2(-n <count>) <file>\n");
        return 1;
    }
    int n =3;
    char *fname =argv[1];
    if(argv ==4){
        n =atoi(argv[2]);
        fname =argv[3];
    }
    fd =open(fname,O_RDONLY);
    if (fd <0) goto error;

    er =fstat(fd, &fileinfo);
    if (er <0) goto error;

    /* Map the whole file onto memory address
       (fileinfo->st_size contains the file size) */

    map =(char*)mmap(NULL,fileinfo.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map ==NULL) goto error;
    int i;
    int cout =0;
    for (i =fileinfo.st_size-1; i >=0; i--){
        if (map[i] =='\n'){
            cout++;
            if (cout >n){
                i++;
                break;
            }
        }
    }
    for(int j =1; j <fileinfo.st_size;j++){
        printf("%c",map[j]);
    }
    munmap(map,fileinfo.st_size);
    close(fd);
    return 0;
error:
    if (map) munmap(map,fileinfo.st_size);
    if (fd >=0) close(fd);
    fprintf(stderr,"ERROR\n");
    return 1;
}