#include <stdio.h>
#include <pthread.h>
#include <Windows.h>
#define MAX_THREADS 4


long soma = 0;
long respond = 0;
long request = 0;

void* cliente(void* i){

	long aux = (long) i;
	long local;

        while(1){
		while(respond != aux ){request = aux;}

        local = soma;
        Sleep(1000);
		soma = local + 1;
		printf("Thread(%ld)",aux);
        printf(" soma = %ld\n", soma);

		respond = 0;
		}
}

void* servidor(void * i){

	while(1){
		while(request == 0){}
		respond = request;
		while(respond != 0){}
		request = 0;
	}
}

int main(void){

    long i,j;
	pthread_t Tcliente[MAX_THREADS],Tservidor;
	pthread_create(&Tservidor, NULL, servidor, NULL);
	for(i = 1; i <= MAX_THREADS; i++){
		pthread_create(&Tcliente[i-1], NULL, cliente, (void*) i);
	}
    for(j=0; j< MAX_THREADS; j++) {
    pthread_join(Tcliente[j],NULL);
  }

	return 0;
}
