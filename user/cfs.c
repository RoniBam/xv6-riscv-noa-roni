#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/proc_stat.h"
#include "user/user.h"

int main () {
    set_cfs_priority(7);
    for (int i=0; i< 1000000 ; i++){
            if (i % 100000 == 0){
                sleep(1);
        }
    
            }

              int mypid = getpid();
                printf("my pid %d\n",mypid);
                printf("in main %p",get_cfs_stats(mypid));
                //struct proc_stats *s = get_cfs_stats(mypid);
                //uint64 s =  get_cfs_stats(mypid);
                //printf("result of get stats %d\n",&s->cfs_priority);
               /*printf("my cfs priority %d\n", s->cfs_priority);
                printf("my running time %d\n", s->rtime);
                printf("my sleep time %d\n", s->stime);
                printf("my runnable time %d\n", s->retime); */

  /*  int high_pid = fork();
    if (high_pid != 0){
        set_cfs_priority(0);
    }
    else{
        set_cfs_priority(1);
        int low_pid = fork();
        if (low_pid == 0){
            set_cfs_priority(2);
        }
        for (int i=0; i< 1000000 ; i++){
            if (i % 100000 == 0){
                sleep(1);
        }
          int mypid = getpid();
                printf("my pid %d\n",mypid);
                struct proc_stats *s = get_cfs_stats(mypid);
                printf("my cfs priority %d\n", s->cfs_priority);
                printf("my running time %d\n", s->rtime);
                printf("my sleep time %d\n", s->stime);
                printf("my runnable time %d\n", s->retime);
            }
    } */

    return 0;
}

    