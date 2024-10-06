#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

struct header{
	char a;
	int b;
	double c;

};

struct header_m{
	int b;
	double c;
	//char d;
        char a;
};

struct header_c{
	char a;
        double c;
	int b;	
};


int main() {
	struct header h;
	h.a = 'c';
	h.b = 123;
	h.c = 12456789;

	printf("Size of struct: %lu bytes\n", sizeof(h));

        printf("struct char a sizeof(c) = %lu, address %p\n",sizeof(h.a),&h.a);
        printf("struct int b sizeof(i) = %lu, address %p\n",sizeof(h.b),&h.b);
       	printf("struct double c sizeof(i) = %lu, address %p\n",sizeof(h.c),&h.c);
	
	printf("Offset of a: %lu bytes\n", (size_t)&h.a - (size_t)&h);
        printf("Offset of b: %lu bytes\n", (size_t)&h.b - (size_t)&h);
        printf("Offset of c: %lu bytes\n", (size_t)&h.c - (size_t)&h);

	printf("***************************************************************\n");

	struct header_m h1;
        h1.a = 'd';
        h1.b = 456;
        h1.c = 1245678910;
	//h1.d = 'd';

        printf("Size of struct: %lu bytes\n", sizeof(h1));

        printf("char a sizeof(c) = %lu, address %p\n",sizeof(h1.a),&h1.a);
        printf("int b sizeof(i) = %lu, address %p\n",sizeof(h1.b),&h1.b);
        printf("double c sizeof(i) = %lu, address %p\n",sizeof(h1.c),&h1.c);
       // printf("char d sizeof(d) = %lu, address %p\n",sizeof(h1.d),&h1.d);

        printf("Offset of a: %lu bytes\n", (size_t)&h1.a - (size_t)&h1);
        printf("Offset of b: %lu bytes\n", (size_t)&h1.b - (size_t)&h1);
        printf("Offset of c: %lu bytes\n", (size_t)&h1.c - (size_t)&h1);
       // printf("Offset of d: %lu bytes\n", (size_t)&h1.d - (size_t)&h1);

	printf("***************************************************************\n");

        struct header_c h2;
        h2.a = 'd';
        h2.b = 456;
        h2.c = 1245678910;

        printf("Size of struct: %lu bytes\n", sizeof(h2));

        printf("char a sizeof(c) = %lu, address %p\n",sizeof(h2.a),&h2.a);
        printf("int b sizeof(i) = %lu, address %p\n",sizeof(h2.b),&h2.b);
        printf("double c sizeof(i) = %lu, address %p\n",sizeof(h2.c),&h2.c);

        printf("Offset of a: %lu bytes\n", (size_t)&h2.a - (size_t)&h2);
        printf("Offset of b: %lu bytes\n", (size_t)&h2.b - (size_t)&h2);
        printf("Offset of c: %lu bytes\n", (size_t)&h2.c - (size_t)&h2);

	return 0;
}
