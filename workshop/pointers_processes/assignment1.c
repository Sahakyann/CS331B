#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int x = 10;
	int *p = &x;
	printf("%d pointer value\n",*p);
       	printf("%d variable value\n",x);
	*p = 15;
        printf("%d pointer value\n",*p);
        printf("%d variable value\n",x);
	return 0;	
}
