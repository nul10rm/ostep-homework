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
        printf("Im child process. (PID: %d)\n", (int)getpid());
    }
    else { //parent 
        int stat;
        int wt = waitpid(rc, &stat, 0);
        printf("wait return value: %d (PID: %d)\n", wt, (int)getpid());
    }

    return 0;
}

// no changes at any execution
// It can be useful when forks many child process.
// and you can know how child process terminated (killed or normally terminated) by signal.