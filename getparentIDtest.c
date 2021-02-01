#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    printf(1,"this is proccess %d and the parent id is %d\n", getpid(), getparentID());
    return 0;
}