#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int i = 10;
	char c = 'c';
	double d = 99;
	short s = 32000;
	printf("int i sizeof(i) = %lu, address %p\n",sizeof(i),&i);
        printf("char c sizeof(c) = %lu, address %p\n",sizeof(c),&c);
        printf("double d sizeof(i) = %lu, address %p\n",sizeof(d),&d);
        printf("short s sizeof(i) = %lu, address %p\n",sizeof(s),&s);
	return 0;
}
