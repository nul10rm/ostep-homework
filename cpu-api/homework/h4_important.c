#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int execute_exec_family(int n) {
    char *args[3];
    
    args[0] = strdup("/bin/ls");
    args[1] = strdup("ls");
    args[2] = NULL;

    switch (n) {
        case 0:
        execl(args[0], args[1], NULL); // 두 번째 인자는 명령어의 이름마냥 넣어주면 됨
        case 1:
        execle(args[0], args[1], NULL, args);
        case 2:
        execlp(args[1], args[1], NULL); // 명령어 이름만 줘도 실행해줌
        case 3:
        execv(args[0], (char **)(args[2])); // 인자 리스트 넣어줘야 함
        case 4:
        execvp(args[1], (char **)(args[2]));
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    int loop = 0;
    
    while (loop < 5) {
        int rc = fork();
        
        if (rc < 0) {
            fprintf(stderr, "error occured");
            return 0;
        }
        else if (rc == 0) { // child
            execute_exec_family(loop);
        }
        else { //parent
            int wt = wait(NULL);
            printf("well done (%d).\n", loop + 1);
            loop++;
        }
    }
    

    return 0;
}
