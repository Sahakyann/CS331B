#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int x = 10;
	int *p = &x;
	int **ptp = &p;
	printf("Variable Value = %d\n Pointer Value = %d\n Pointer to Pointer Value = %d\n",x,*p,**ptp);
        return 0;	
}
