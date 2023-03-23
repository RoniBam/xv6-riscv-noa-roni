#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (){
    printf("%d\n",memsize());
    char* str = malloc(20000);
    printf("%d\n",memsize());
    free(str);
    printf("%d\n",memsize());
    return 0;
}