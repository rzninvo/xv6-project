#include "types.h"
#include "stat.h"
#include "user.h"

struct {
    int pid, priority, creationtime, runtime, waittime, sleepingtime, terminationtime;
}pdata[30];

int main()
{
    int creationtimeavg = 0, runtimeavg = 0, waittimeavg = 0, sleepingtimeavg = 0, terminationtimeavg = 0;
    changePolicy(1);
    for (int i = 0 ; i < 30; i++)
    {
        if (fork() == 0)
        {
            int child = i;
            setPriority(getpid(), (child / 5) + 1);
            for (int j = 1; j <= 250; j++)
            {
                printf(1, "\n Counting %d : %d\n", child, j);
            }
            exit();
        }
    }
    for (int i = 0; i < 30; i++)
    {
        pdata[i].pid = waitreg(&pdata[i].creationtime, &pdata[i].runtime, &pdata[i].waittime
            , &pdata[i].sleepingtime, &pdata[i].terminationtime, &pdata[i].priority);
        creationtimeavg += pdata[i].creationtime;
        runtimeavg += pdata[i].runtime;
        waittimeavg += pdata[i].waittime;
        sleepingtimeavg += pdata[i].sleepingtime;
        terminationtimeavg += pdata[i].terminationtime;
    }
    for (int i = 0 ; i < 29; i++)
    {
        for (int j = 0 ; j < 29 - i; j++)
        {
            struct {
                int pid, priority, creationtime, runtime, waittime, sleepingtime, terminationtime;
            }temp;
            if (pdata[j].priority > pdata[j+1].priority)
            {   
                temp.pid = pdata[j+1].pid;
                temp.creationtime = pdata[j+1].creationtime;
                temp.priority = pdata[j+1].priority;
                temp.runtime = pdata[j+1].runtime;
                temp.waittime = pdata[j+1].waittime;
                temp.sleepingtime = pdata[j+1].sleepingtime;
                temp.terminationtime = pdata[j+1].terminationtime;

                pdata[j+1].pid = pdata[j].pid;
                pdata[j+1].creationtime = pdata[j].creationtime;
                pdata[j+1].priority = pdata[j].priority;
                pdata[j+1].runtime = pdata[j].runtime;
                pdata[j+1].waittime = pdata[j].waittime;
                pdata[j+1].sleepingtime = pdata[j].sleepingtime;
                pdata[j+1].terminationtime = pdata[j].terminationtime;

                pdata[j].pid = temp.pid;
                pdata[j].creationtime = temp.creationtime;
                pdata[j].priority = temp.priority;
                pdata[j].runtime = temp.runtime;
                pdata[j].waittime = temp.waittime;
                pdata[j].sleepingtime = temp.sleepingtime;
                pdata[j].terminationtime = temp.terminationtime;
            }
        }
    }
    for (int i = 0 ; i < 30 ; i++)
    {
        printf(1, "\n pid= %d\n priority= %d\n creationtime= %d\n runtime= %d\n waittime= %d\n sleepingtime= %d\n terminationtime= %d\n", 
                pdata[i].pid, pdata[i].priority, pdata[i].creationtime, pdata[i].runtime, pdata[i].waittime, 
                    pdata[i].sleepingtime, pdata[i].terminationtime);
    }
    int num = 0;
    int cavg = 0, ravg = 0, wavg = 0, savg = 0, tavg = 0;
    for (int i = 0; i < 6; i++)
    {
        cavg = 0;
        ravg = 0;
        wavg = 0;
        savg = 0;
        tavg = 0;
        for (int j = 0; j < 5; j++)
        {
            cavg +=  pdata[num + j].creationtime;
            ravg +=  pdata[num + j].runtime;
            wavg +=  pdata[num + j].waittime;
            savg +=  pdata[num + j].sleepingtime;
            tavg +=  pdata[num + j].terminationtime;
        }
        printf(1, "\n priority= %d\n creationtime AVG = %d\n runtime AVG = %d\n waittime AVG = %d\n sleepingtime AVG = %d\n terminationtime AVG = %d\n", 
                i + 1, cavg / 5, ravg / 5, wavg / 5, 
                    savg / 5, tavg / 5);
        num += 5;
    }
    printf(1, "\n creationtime AVG = %d\n runtime AVG = %d\n waittime AVG = %d\n sleepingtime AVG = %d\n terminationtime AVG = %d\n", 
                creationtimeavg / 30, runtimeavg / 30, waittimeavg / 30, 
                    sleepingtimeavg / 30, terminationtimeavg / 30);
    return 0;
}