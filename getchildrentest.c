#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    if (fork())
        if (fork())
            if(fork())
            {
                printf(1, "This is proccess %d and children are ", getpid());
                int children = getchildren();
                while (children != 0)
                {
                    printf(1, "%d", children % 10);
                    children /= 10;
                    if (children != 0)
                        printf(1,"-");
                }
                printf(1,"\n");
                exit();
            }
    exit();
    return 0;
}