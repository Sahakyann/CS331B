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
	int *arr_new;       
       
	if(!arr){
                printf("malloc() failed");
                exit(1);
        }


        printf("\nEnter %d integers: ",n);
        for(int i = 0; i < n;i++){
                scanf("%d",&arr[i]);
                printf(" ");
        }
	printf("\nPointer before realloc: %p\n",arr);

	arr_new = realloc(arr,n*sizeof(int)/2);
	printf("Pointer after realloc: %p\n",arr_new);
	

	printf("Array after realloc:");

	for(int i = 0; i <= n/2;i++){
                printf(" %d",arr_new[i]);
        }
	printf("\nOriginal pointer after realloc: %p\n",arr);
	
	int *arr_large = realloc(arr_new,40960000);
	printf("\nLarge realloc resulting pointer: %p\n",arr_large);

        free(arr_large);
        arr = NULL;
	arr_new = NULL;
	arr_large = NULL;
        return 0;
}

