#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "error occured");
        return 0;
    }
    else if (rc == 0) {
        printf("x value at child proc: %d\n", x);
    }
    else {
        printf("x value at parent proc: %d\n", x);
    }

    return 0;
}

// answer: same