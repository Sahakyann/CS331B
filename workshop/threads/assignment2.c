#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct{
	int *arr;
	int start;
	int end;
}array_data;

void *start_thread(void *arg) {
    pthread_t tid = pthread_self();
    printf("Thread %lu is running\n", tid);

    array_data *data = (array_data *)arg;
    int sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += data->arr[i];
    }

    printf("Sum from index %d to %d is equal to: %d\n", data->start, data->end - 1, sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int ret1, ret2;
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("malloc() failed");
        exit(1);
    }

    printf("\nEnter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    array_data first_half = {arr, 0, size / 2};
    array_data second_half = {arr, size / 2, size};

    ret1 = pthread_create(&t1, NULL, start_thread, &first_half);
    if (ret1) {
        perror("pthread_create");
        return -1;
    }

    ret2 = pthread_create(&t2, NULL, start_thread, &second_half);
    if (ret2) {
        perror("pthread_create");
        return -1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    free(arr);
    arr = NULL;

    return 0;
}
