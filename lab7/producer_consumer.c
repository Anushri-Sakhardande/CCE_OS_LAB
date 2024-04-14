#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//initialize capacity,buffer
const  int capacity =5; 
int produced_item = 0;
int consumed_item = -1;
int *buffer;

//general semaphores 
int empty=capacity,full=0;
//binary semaphores
int mutex=1;
int in =1, out=1;

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}


void *producer(void *arg) {
    int i=10;
    do{
        //produce data 
        produced_item++; 
        wait(&empty);
        wait(&mutex);
        //put into buffer
        buffer[in] = produced_item;
        printf("Produced: %d\n", produced_item);
        in = (in + 1) % capacity;
        signal(&mutex);
        signal(&full);
        i--;
        usleep(rand() % 1000000);
    }while(i);
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i=10;
    do{
        wait(&full);
        wait(&mutex);
        //use consumed data
        consumed_item = buffer[out];
        printf("Consumed: %d\n", consumed_item);
        out = (out + 1) % capacity;
        signal(&mutex);
        signal(&empty);
        i--;
        usleep(rand() % 1000000);
    }while(i);
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    buffer = (int*)malloc(sizeof(int)*capacity);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    return 0;
}
