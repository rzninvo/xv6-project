#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int pid[10], creationtime[10], runtime[10], waittime[10], sleepingtime[10], terminationtime[10];
    int creationtimeavg = 0, runtimeavg = 0, waittimeavg = 0, sleepingtimeavg = 0, terminationtimeavg = 0;
    int priority = 0, queuenum = 0;
    changePolicy(1);
    for (int i = 0 ; i < 10; i++)
    {
        if (fork() == 0)
        {
            for (int j = 1; j <= 1000; j++)
            {
                printf(1, "\n Counting %d : %d\n", getpid(), j);
            }
            exit();
        }
    }
    for (int i = 0; i < 10; i++)
    {
         pid[i] = waitreg(&creationtime[i], &runtime[i], &waittime[i], &sleepingtime[i]
                , &terminationtime[i], &priority, &queuenum);
            creationtimeavg += creationtime[i];
            runtimeavg += runtime[i];
            waittimeavg += waittime[i];
            sleepingtimeavg += sleepingtime[i];
            terminationtimeavg += terminationtime[i];
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        printf(1, "\n pid= %d\n creationtime= %d\n runtime= %d\n waittime= %d\n sleepingtime= %d\n terminationtime= %d\n", 
                pid[i], creationtime[i], runtime[i], waittime[i], 
                    sleepingtime[i], terminationtime[i]);
    }
    printf(1, "\n creationtime AVG = %d\n runtime AVG = %d\n waittime AVG = %d\n sleepingtime AVG = %d\n terminationtime AVG = %d\n", 
                creationtimeavg / 10, runtimeavg / 10, waittimeavg / 10, 
                    sleepingtimeavg / 10, terminationtimeavg / 10);
    exit();
    return 0;
}