#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fibonacci.h"

#define MAXBUFSIZE 1024
const int STDOUT = 1;

int n = 15;

int main() {
    char buffer[MAXBUFSIZE];
    int pipefd[2];
    pipe(pipefd);
    ssize_t pid = fork();
    if (pid == 0) { // дочерний процесс
        long long int fibb_value = fibb(n);
        ssize_t len = snprintf(buffer, sizeof(buffer), "Число Фиббоначи %d = %d\n", n, fibb_value);
        close(pipefd[0]);
        write(pipefd[1], buffer, MAXBUFSIZE);
        close(pipefd[1]);
        _exit(0);
    } 
    else if (pid > 0) { // родительский процесс
        int status;
        close(pipefd[1]);
        wait(&status);
        ssize_t len = read(pipefd[0], buffer, MAXBUFSIZE);
        write(STDOUT, buffer, strlen(buffer));
        close(pipefd[0]);
    } 
    else { // ошибка
        printf("Error creating a child process!\n");
    }
    return 0;
}#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fact.h>
#define MAXBUFSIZE 1024

const int STDIO = 1;
// const size_t MAXBUFSIZE = 1024; // including '\0'

int n=10;

int main()
{
  
