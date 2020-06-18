#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>

int main(void)
{
    pid_t child;
    child = fork();
    char buffer[128];
    bzero(buffer, 32);
    int ptr;
    int status;

    ptr = 0;
    status = 0;
    if (child == 0)
    {
        prctl(1, 1);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(&buffer);
        return (0);
    }
    while (ptr = ptrace(PTRACE_PEEKUSR, child, 44, 0) != 11)
    {
        wait(&status);
        if ((status & 127) == 0 || (((status & 127) + 1) / 2) > 0)
        {
            puts("child is exiting...");
            return (0);
        }
    }
    puts("no exec() for you");
    kill(child, 9);
    return (0);
}