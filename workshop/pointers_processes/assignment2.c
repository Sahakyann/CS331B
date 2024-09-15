#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int arr[] = {2,4,6,8,10};
	int length = sizeof(arr)/sizeof(int);
	int *x = arr;  
	
	for(int i = 0;i<length;i++){
                printf("Array %d-th address = %p, Value = %d\n",i,&arr[i],arr[i]);
        }
	printf("----------------------------------------------\n");
	for(int i = 0;i<length;i++){
		++*x;
		printf("Pointer %d-th address = %p, Value = %d\n",i,x,*x);
		x++;
	}
	return 0;
}
