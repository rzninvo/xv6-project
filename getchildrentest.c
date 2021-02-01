#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    if (fork())
        if (fork())
            if(fork())
            {
                printf(1, "This is proccess %d and children are", getpid());
                char* children = getchildren();
                int i = 0;
                while (1)
                {
                    if (children[i] != 'z')
                        printf(1, children[i]);
                    else
                        break;
                }
            }
    return 0;
}