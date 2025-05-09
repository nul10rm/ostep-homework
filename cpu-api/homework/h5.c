#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) { 
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "error occured");
        return 0;
    }
    else if (rc == 0) { // child
        int wt = wait(NULL);
        printf("Im child process. (PID: %d)\n", (int)getpid());
        printf("wait return val: %d\n", wt);
    }
    else { //parent 
        int wt = wait(NULL);
        printf("wait return value: %d (PID: %d)\n", wt, (int)getpid());
    }

    return 0;
}

// `wait` returns child process's PID
// returns -1 when calls wait(NULL) in child process