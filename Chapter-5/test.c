//
// Created by dsy on 2021/4/9.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>


//fork的系统调用
void test_fork(){
    printf("hello word(pid:%d)\n",(int)getpid());
    int rc=fork();
    if(rc<0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        printf("hello,I am child (pid:%d)\n",(int)getpid());
    }else{
        printf("hello,I am parent of %d (pid:%d)\n",rc,(int)getpid());
    }
}

//wait的系统调用
void test_wait(){
    printf("hello word(pid:%d)\n",(int)getpid());
    int rc=fork();
    if(rc<0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        printf("hello,I am child (pid:%d)\n",(int)getpid());
    }else{
        int wc=wait(NULL);
        printf("hello,I am parent of %d (wc:%d) (pid:%d)\n",rc,wc,(int)getpid());
    }
}

//exec的系统调用
void test_exec(){
    printf("hello word(pid:%d)\n",(int)getpid());
    int rc=fork();
    if(rc<0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        printf("hello,I am child (pid:%d)\n",(int)getpid());
        char *myargs[3];
        myargs[0]=strdup("wc");
        myargs[1]=strdup("../Chapter-5/test.c");
        myargs[2]=NULL;
        execvp(myargs[0],myargs);
        printf("this shouldn't print out");
    }else{
        int wc=wait(NULL);
        printf("hello,I am parent of %d (wc:%d) (pid:%d)\n",rc,wc,(int)getpid());
    }
}

//exec的系统调用-重定向
void test_exec_output(){
    int rc=fork();
    if(rc<0){
        //fork failed
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        close(STDOUT_FILENO);
        open("../Chapter-5/output.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        char *myargs[3];
        myargs[0]=strdup("wc");
        myargs[1]=strdup("../Chapter-5/test.c");
        myargs[2]=NULL;
        execvp(myargs[0],myargs);
    }else{
        int wc=wait(NULL);
    }
}

int  main(int argc,char*argv[]){
    test_exec_output();
}