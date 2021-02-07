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
                char children[200] = " ";
                getchildren(children);
                printf(1,"%s\n", children);
            }
    return 0;
}