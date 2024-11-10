#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>


void *start_thread(void *arg) {
    pthread_t tid = pthread_self();
    printf("Thread %lu is running\n", tid);
    int num = *((int*)arg);
    int square = num * num;
    printf("Square of %d is %d\n",num,square);
    pthread_exit(NULL);
}

int main() {
    pthread_t *threads;
    int ret;
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("malloc() failed");
        exit(1);
    }

    threads = malloc(size * sizeof(pthread_t));

    printf("\nEnter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int j = 0; j < size; j++){
   	ret = pthread_create(&threads[j],NULL,start_thread,&arr[j]);
	if(ret)
	{
		errno = ret;
		perror("pthread_create()");
		return -1;
	}
	 
    }

    for(int k = 0;k < size;k++)
    {
    	pthread_join(threads[k],NULL);
    }

    free(arr);
    arr = NULL;

    return 0;
}

