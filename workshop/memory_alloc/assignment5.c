#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        int n;
        printf("Enter Number of Students: \n");
        scanf("%d", &n);
        
	int *arr = calloc(n,sizeof(int));
	if(!arr){
		printf("calloc failed");
		return 0;
	}


	int min = 100;
	int max = 0;
	printf("Enter the grades: \n");

	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i] > max){
			max = arr[i];
		}
		if(arr[i] < min){
			min = arr[i];
		}
	}

	printf("Highest grade: %d\n",max);
	printf("Lowest grade: %d\n",min);

	free(arr);
	arr = NULL;
	return 0;
}
