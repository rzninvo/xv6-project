#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    if (fork())
        if (fork())
            if(fork())
                if(fork());
    printf(1,"this is proccess %d and the system call %d was called %d times\n"
            , getpid(), 1, getsyscallcounter(1));   
    return 0;
}