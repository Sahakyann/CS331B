#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter size: ");
	scanf("%d", &n);
	
	int *arr = malloc(n*sizeof(int));
	if(!arr){
		printf("malloc() failed");
		exit(1);
	}	
	int sum = 0;
	printf("Enter %d integers: ",n);
	for(int i = 0; i < n;i++){
		scanf("%d",&arr[i]);
		printf(" ");
		sum += arr[i];
	}

	printf("\nSum of the array: %d\n",sum);
	free(arr);
	arr = NULL;
	return 0;
}
