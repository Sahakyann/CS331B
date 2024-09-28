#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char **str_arr;
	str_arr = malloc(3*sizeof(char*));
	if(!str_arr){
		printf("malloc failed");
		exit(1);
	}
	
	printf("Enter 3 strings: ");
	for(int i = 0;i<3;i++){
		str_arr[i] = malloc(50 * sizeof(char));
		if(!str_arr[i]){
			printf("string malloc failed");
			exit(2);
		}
		
		scanf("%50s",str_arr[i]);
	}

	str_arr = realloc(str_arr,5*sizeof(char*));
	
	printf("Enter 2 more strings: ");
	for(int i = 3;i<5;i++){
                str_arr[i] = malloc(50 * sizeof(char));
                if(!str_arr[i]){
                        printf("string malloc failed");
                        exit(3);
                }

                scanf("%50s",str_arr[i]);
        }
	
	
	printf("Entered Strings: ");
	for(int i = 0;i<5;i++){
		printf("%s ",str_arr[i]);
		free(str_arr[i]);
		str_arr[i] = NULL;
	}
	free(str_arr);
	str_arr = NULL;
	printf("\n");
	return 0;
		
}
