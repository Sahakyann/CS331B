#include <stdio.h>

struct DataHolder {
    char a;
    int b;
    double c;
};

int main() {
    struct DataHolder dh;
    dh.a = 'c';
    dh.b = 123;
    dh.c = 123456;
    printf("Size of struct: %lu\n", sizeof(dh));
    printf("Address of a: %p\n", &dh.a);
    printf("Address of b: %p\n", &dh.b);
    printf("Address of c: %p\n", &dh.c);

    return 0;
}
