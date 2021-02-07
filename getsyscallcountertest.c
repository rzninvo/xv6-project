#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (fork()){
        if (fork()){
            if(fork()){
                if(fork()){
                    getchildren();
                    getparentID();
                    int *num;
                    *num = atoi(argv[1]);
                    printf(1,"this is proccess %d and the system call %d was called %d times\n"
                        , getpid(), *num, getsyscallcounter(*num));   
                    wait();
                    exit();
                }
                else
                {
                    exit();
                }
            }
            else
            {
                exit();
            }
        }
        else
        {
            exit();
        }           
    }
    else
    {
        exit();
    }
    
    return 0;
}