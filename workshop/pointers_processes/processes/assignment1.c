#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

void out(void){
	printf("ID of the Exiting Process: %jd\n", (intmax_t)getpid());
}

int main() {
	int i = fork();
	
	if(i == 0){
		printf("Child Process:\n");
		atexit(out);
	}else{
		printf("Parent Process:\n");
		atexit(out);
	}
	return 0;
}
