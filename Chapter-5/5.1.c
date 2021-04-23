//
// Created by dsy on 2021/4/19.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char*argv[]){
    int x=10;
    int rc=fork();
    if(rc<0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        printf("hello,I am child (pid:%d),x is %d\n",(int)getpid(),x);
    }else{
        printf("hello,I am parent (pid:%d),x is %d\n",(int)getpid(),x);
    }
}