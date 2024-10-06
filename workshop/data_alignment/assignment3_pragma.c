#include <stdio.h>

#pragma pack(1)
struct DataHolder {
    char a;
    int b;
    double c;
};

#pragma pack(2)
struct DataHolder2 {
    char a;
    int b;
    double c;
};

#pragma pack(4)
struct DataHolder4 {
    char a;
    int b;
    double c;
    char d;
};

#pragma pack(16)
struct DataHolder16 {
    char a;
    int b;
    double c;
    long e;
    char d;
  //  long f;
};


int main() {
    struct DataHolder pack;

    printf("Size of struct pack(1): %lu bytes\n", sizeof(pack));
    printf("Address of a: %p\n", &pack.a);
    printf("Address of b: %p\n", &pack.b);
    printf("Address of c: %p\n", &pack.c);

    printf("*********************************************************\n");
    struct DataHolder2 pack2;

    printf("Size of struct pack(2): %lu bytes\n", sizeof(pack2));
    printf("Address of a: %p\n", &pack2.a);
    printf("Address of b: %p\n", &pack2.b);
    printf("Address of c: %p\n", &pack2.c);
    
    printf("*********************************************************\n");
    struct DataHolder4 pack4;

    printf("Size of struct pack(4): %lu bytes\n", sizeof(pack4));
    printf("Address of a: %p\n", &pack4.a);
    printf("Address of b: %p\n", &pack4.b);
    printf("Address of c: %p\n", &pack4.c);

    printf("*********************************************************\n");
    struct DataHolder16 pack16;

    printf("Size of struct pack(16): %lu bytes\n", sizeof(pack16));
    printf("Address of a: %p\n", &pack16.a);
    printf("Address of b: %p\n", &pack16.b);
    printf("Address of c: %p\n", &pack16.c);
    printf("Address of e: %p, sizeof long=%lu\n", &pack16.e,sizeof(pack16.e));
    printf("Address of d: %p\n", &pack16.d);

    return 0;
}
