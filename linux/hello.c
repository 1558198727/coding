#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t pid;
    pid=fork();

    if(pid<0){
        fprintf(stderr,"Fork Failed");
        exit(-1);
    }else if(pid == 0){
         printf("This is child\n");
         execlp("/bin/ls","ls",NULL);
    }else{

        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }

return 0;
}

