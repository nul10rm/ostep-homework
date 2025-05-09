#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
   
    int fd = open("./dummies/h2_", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "error occured");
        return 0;
    }
    else if (rc == 0) {
        printf("hi! Im your child\n");
        write(fd, "HI\n", 3);
    }
    else {
        printf("hello, Im your parent\n");
        write(fd, "HELLO\n", 6);
    }

    return 0;
}

// answer: both two write executed well.
