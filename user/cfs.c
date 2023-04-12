#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/proc_stat.h"
#include "user/user.h"

int main () {
    int high_pid = fork();
    if (high_pid != 0){
        set_cfs_priority(0);
        sleep(100);
    }
    else{
        set_cfs_priority(1);
        sleep(50);
        int low_pid = fork();
        if (low_pid == 0){
            set_cfs_priority(2);
            sleep(30);
        }
        for (int i=0; i< 1000000 ; i++){
            if (i % 100000 == 0){
                sleep(1);
            }
        }
    }

     int mypid = getpid();
                int priority = 100;
                int rtime =  0;
                int retime =  0;
                int stime =  0;
                get_cfs_stats(mypid,(uint64)&priority,(uint64)&rtime,(uint64)&retime,(uint64)&stime);
                printf("my cfs priority %d\n", priority);
                printf("my running time %d\n", rtime);
                printf("my sleep time %d\n", stime);
                printf("my runnable time %d\n", retime); 
         

    return 0;
}

    