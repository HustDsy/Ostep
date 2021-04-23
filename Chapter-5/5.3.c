//
// Created by dsy on 2021/4/20.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char*argv[]){
    int rc=vfork();
    if(rc<0){
        fprintf(stderr,"failed to creat a child");
    }else if(rc==0){
        printf("hello\n");
        exit(1);
    }else{
        printf("goodbye\n");
    }
    return 0;
}
