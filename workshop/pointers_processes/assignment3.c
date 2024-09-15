#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void swap(int *a, int *b){
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
}

int main() {
	int a = 5;
	int b = 10;
	printf("a = %d,b = %d\n",a,b);
	swap(&a,&b);
        printf("a = %d,b = %d\n",a,b);
	return 0;
}
