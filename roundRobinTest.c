#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    changePolicy(3);
    for (int i = 0 ; i < 10; i++)
    {
        if (!fork())
        {
            for (int j = 1; j <= 1000; j++)
            {
                printf(1, "%d : %d", getpid(), j);
            }
            exit();
        }
        else
        {
            int *creationtime, *runtime, *waittime, *sleepingtime, *terminationtime;
            waitreg(creationtime, runtime, waittime, sleepingtime, terminationtime);
            printf(1, "%d:%d:%d:%d:%d", 
                *creationtime, *runtime, *waittime, *sleepingtime, *terminationtime);
        }
    }
    return 0;
}