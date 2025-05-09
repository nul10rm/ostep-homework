#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "error occured");
        return 0;
    }
    else if (rc == 0) { // child
        printf("hello\n");
    }
    else { //parent 
        for (int i = 0; i < 999999; i++) {} // for delay
        printf("goodbye\n");
    }

    return 0;
}

// make a delay to parent process