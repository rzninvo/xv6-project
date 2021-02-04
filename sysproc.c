#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_getparentID(void)
{
  return getparentID();
}

int sys_getchildren(void)
{
  return getchildren();
}

int sys_getsyscallcounter(void)
{
  int num;
  if(argint(0, &num) < 0)
    return -1;
  return getsyscallcounter(num);
}

int sys_setPriority(void)
{
  int pid, priority;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &priority) < 0)
    return -1;
  return setPriority(pid, priority);
}

int sys_setQueuenum(void)
{
  int pid, queuenum;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &queuenum) < 0)
    return -1;
  return setQueuenum(pid, queuenum);
}

int sys_changePolicy(void)
{
  int policy;
  if(argint(0, &policy) < 0)
    return -1;
  return changePolicy(policy);
}
int sys_waitreg(void)
{
  int *creationtime, *runtime, *waittime, *sleepingtime, *terminationtime, *priority, *queuenum;
  if(argptr(0, (void*)&creationtime, sizeof(creationtime)) < 0)
    return -1;
  if(argptr(1, (void*)&runtime, sizeof(runtime)) < 0)
    return -1;
  if(argptr(2, (void*)&waittime, sizeof(waittime)) < 0)
    return -1;
  if(argptr(3, (void*)&sleepingtime, sizeof(sleepingtime)) < 0)
    return -1;
  if(argptr(4, (void*)&terminationtime, sizeof(terminationtime)) < 0)
    return -1;
  if(argptr(5, (void*)&priority, sizeof(priority)) < 0)
    return -1;
  if(argptr(6, (void*)&queuenum, sizeof(queuenum)) < 0)
    return -1;
  return waitreg(creationtime, runtime, waittime, sleepingtime, terminationtime, priority, queuenum);
}