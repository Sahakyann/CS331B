#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    printf("exit function 1\n");
}

void func2(void) {
    printf("exit function 2\n");
}

int main() {
    // these will work in the reverse order of registration, suggesting that it is stored in a stack
    atexit(func1);
    atexit(func2);

    printf("Start\n");
    printf("Exit\n");
    exit(0);
    printf("test\n");
    //exit(x);
    return 0;
}
