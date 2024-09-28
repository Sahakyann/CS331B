#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void * my_realloc();
void * my_malloc();
void my_free();

typedef struct malloc_header {
    size_t size;
} malloc_header;


int main() {
	int *a;
	int *b;
	//a = malloc(5*sizeof(int));
	b = my_malloc(5*sizeof(int));
	malloc_header *header = (malloc_header*)b - 1;
	printf("my_malloc, allocated size: %d, allocated address: %p\n",(int)header->size,b); 

	int *c = my_realloc(b,10*sizeof(int));
	printf("my_realloc, allocated size: %d, allocated address: %p\n",(int)((malloc_header*)c-1)->size,c);
	for(int i = 0;i<10;i++){
		c[i] = i;
		printf("%d",c[i]);
	}

	free((malloc_header*)c-1);
	c = NULL;
	b = NULL;
}


void * my_malloc(size_t size) {
  
    malloc_header *header = (malloc_header *)malloc(sizeof(malloc_header) + size);
    if (!header) return NULL;

    header->size = size;
    return (void *)(header + 1);
}

void * my_realloc(void *ptr,size_t size){

	if(!ptr){
	       	return my_malloc(size);
	}

	if(size == 0){
	       free(ptr);
	       return NULL;
	}

	int old_size = (int)(((malloc_header*)ptr - 1)->size);  /*malloc_usable_size()*/
	void *new_ptr;

	if(size > old_size){
		printf("provided size is larger than ptr size, old = %d, new = %d\n", old_size, (int)size);
				
	}else if(size < old_size){
		printf("provided size is smaller than ptr size, old = %d, new = %d\n", old_size,(int)size);
	}

	new_ptr = my_malloc(size);
	if(!new_ptr){
                   return NULL;
        }

        memcpy(new_ptr, ptr, old_size < size ? old_size : size);
	free((malloc_header*)ptr-1);
	
	return new_ptr;
}

void my_free(void *ptr) {
    if (ptr) {
        malloc_header *header = (malloc_header *)ptr - 1;
        free(header);
    }
}
