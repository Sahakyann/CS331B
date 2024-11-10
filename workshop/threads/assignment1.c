#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void * start_thread (void *m)
{
	pthread_t tid = pthread_self();
	printf("Thread %lu is running...\n",tid);
	printf("%s\n",(char*)m);
	return m;	
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	int ret1,ret2;
	char* message1 = "This is the message for the first thread";
	char* message2 = "This is the message for the second thread";
	
	ret1 = pthread_create(&t1,NULL,start_thread,(void*)message1);
	if(ret1){
		errno = ret1;
		perror("pthread_create");
		return -1;
	}

	ret2 = pthread_create(&t2,NULL,start_thread,(void*)message2);
        if(ret2){
                errno = ret2;
                perror("pthread_create");
                return -1;
        
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}
