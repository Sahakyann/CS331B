#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);

        int *arr = calloc(n,sizeof(int));
	if(!arr){
		printf("calloc() failed");
		exit(1);
	}
	printf("Array after calloc:");
	for(int i = 0; i < n;i++){
                printf(" %d ",arr[i]);
        }

        int sum = 0;
        printf("\nEnter %d integers: ",n);
        for(int i = 0; i < n;i++){
                scanf("%d",&arr[i]);
                printf(" ");
                sum += arr[i];
        }
	
	if(n != 0) printf("\nAverage of the array: %d\n",sum/n);
	
	free(arr);
	arr = NULL;
        return 0;
}

