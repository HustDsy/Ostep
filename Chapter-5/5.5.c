//
// Created by dsy on 2021/4/20.
//
//
// Created by dsy on 2021/4/20.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//wait在子进程中的话，返回-1
int main(int argc,char*argv[]){
    int rc=fork();
    int wc=wait(NULL);
    if(rc<0){
        fprintf(stderr,"failed to creat a child");
    }else if(rc==0){
        printf("child %d\n",getpid());
    }else{
        printf("goodbye\n");
    }
    printf("pid:%d wc:%d rc:%d\n", (int)getpid(), wc, rc);
    return 0;
}
