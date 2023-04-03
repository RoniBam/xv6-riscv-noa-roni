#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "proc_stat.h"

uint64
sys_exit(void)
{
  int n;
  char* m = "";
  argint(0, &n);
  argstr(1,m,32);
  exit(n,m);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  uint64 m;
  argaddr(0, &p);
  argaddr(1, &m);
  return wait(p,m);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_memsize(void){
  return myproc() -> sz;
}

uint64
sys_set_ps_priority(void){
  int pri;
  argint(0,&pri);
  set_ps_priority(pri);
  return 0;
}

uint64
sys_set_cfs_priority(void){
  int pri;
  argint(0,&pri);
  set_cfs_priority(pri);
  return 0;
}

void
sys_get_cfs_stats(void){
  int pid;
  uint64 priority;
  uint64 rtime;
  uint64 retime;
  uint64 stime;
  argint(0,&pid);
  argaddr(1,&priority);
  argaddr(2,&rtime);
  argaddr(3,&retime);
  argaddr(4,&stime);
  get_cfs_stats(pid,priority,rtime,retime,stime);
  //return get_cfs_stats(pid);
}

uint64
sys_set_policy(void){
  int policy;
  argint(0,&policy);
  return set_policy(policy);
 
  
}