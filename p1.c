//REALIZZAZIONE CON THREAD E MUTEX

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

void *stemp(void *args);
void *sumid(void *args);
void *senergy(void *args);

int temperatura = 0;
int umidita = 0;
int energia = 0;

pthread_mutex_t mutex;

int main() {
	pthread_t tt, tu, te;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tt, NULL, stemp, NULL);
	pthread_create(&tu, NULL, sumid, NULL);
	pthread_create(&te, NULL, senergy, NULL);

	while(1){
		pthread_mutex_lock(&mutex);
		if(temperatura == -1 && umidita == -1 && energia == -1) {
			break;
		}
		printf("Temperatura: %d\nUmidita': %d\nEnergia: %d\n", temperatura, umidita, energia);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
	pthread_mutex_destroy(&mutex);
}

void *stemp(void *args){
	time_t start_time;

	srand((unsigned int)pthread_self());

	start_time = time(NULL);
	
	while((time(NULL) - start_time) < 20){
		pthread_mutex_lock(&mutex);
		temperatura = (rand()%30)+10;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	printf("TempSens - Finish!\n");
	fflush(stdout);
	
	pthread_mutex_lock(&mutex);
	temperatura = -1;
	pthread_mutex_unlock(&mutex);
}

void *sumid(void *args){
	time_t start_time;

	srand((unsigned int)pthread_self());

	start_time = time(NULL);
	
	while((time(NULL) - start_time) < 20){
		pthread_mutex_lock(&mutex);
		umidita = (rand()%100)+1;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	printf("TempSens - Finish!\n");
	fflush(stdout);
	
	pthread_mutex_lock(&mutex);
	umidita = -1;
	pthread_mutex_unlock(&mutex);
}

void *senergy(void *args){
	time_t start_time;

	srand((unsigned int)pthread_self());

	start_time = time(NULL);
	
	while((time(NULL) - start_time) < 20){
		pthread_mutex_lock(&mutex);
		energia = (rand()%3000)+1;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	printf("TempSens - Finish!\n");
	fflush(stdout);
	
	pthread_mutex_lock(&mutex);
	energia = -1;
	pthread_mutex_unlock(&mutex);
}



















