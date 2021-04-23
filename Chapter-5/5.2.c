//
// Created by dsy on 2021/4/19.
//


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc,char*argv[])
{
    int fd = open("../Chapter-5/output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        close(fd);
        fprintf(stderr, "fork failed");
        exit(1);
    } else if (rc == 0) {
        char * s = "child write something!\n";
        write(fd, s, strlen(s));
    } else {
        char * s = "parent write something\n";
        write(fd, s, strlen(s));
        wait(NULL);
        close(fd);
    }
    return 0;
}