#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void * start_thread (void *m)
{
        pthread_t tid = pthread_self();
       // printf("Thread %lu is running...\n",tid);
        for(int i = 1;i<6;i++){
		printf("%d thread_ID = %lu\n",i,tid);
	}
        pthread_exit(NULL);
}

int main()
{
        pthread_t t1;
        pthread_t t2;
	pthread_t t3;
        int ret1,ret2,ret3;

        ret1 = pthread_create(&t1,NULL,start_thread,NULL);
        if(ret1){
                errno = ret1;
                perror("pthread_create");
                return -1;
        }

        ret2 = pthread_create(&t2,NULL,start_thread,NULL);
        if(ret2){
                errno = ret2;
                perror("pthread_create");
                return -1;

        }

	ret3 = pthread_create(&t3,NULL,start_thread,NULL);
        if(ret3){
                errno = ret3;
                perror("pthread_create");
                return -1;

        }

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
	pthread_join(t3,NULL);
        return 0;
}


