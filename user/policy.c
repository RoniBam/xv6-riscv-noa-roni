//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/syscall.h>
#include "kernel/types.h"
#include "user/user.h"



int main(int argc, char *argv[]) {
    int policy_code;
    // Check that the user provided an argument
    if (argc < 2) {
        printf("Usage: policy <policy_code>\n");
    }
    // Parse the policy code from the command-line argument
    policy_code = atoi(argv[1]);
    // Call the set_policy() system call with the given policy code
    int ret = set_policy(policy_code);

    if (ret == 0) {
        printf("Scheduling policy set to %d\n", policy_code);
    } else {
        printf("Error setting scheduling policy: %ld\n", ret);
    }

    return 0;
}
