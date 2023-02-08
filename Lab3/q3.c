/*
Modify your producer-consumer implementation so that it uses semaphores to handle
race conditions instead of mutexes.
Use the pthread library implementation.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 20

int count = 0; // buffer size
int in = 0;
int out = 0;
int buffer[BUFFER_SIZE];
pthread_t tid;
sem_t semph; // mutex using Semaphore

void insert(int item)
{ // Inset item into ending of buffer while it is not full.
    while (count == BUFFER_SIZE)
        ;
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    sleep(1);
}

int remove_item()
{ // Removes last item off buffer while is it not empty.
    int item;
    while (count == 0)
        ;
    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    sleep(1);
    return item;
}

void *producer(void *param)
{
    int item;
    int i = 1;
    while (i <= 20)
    {
        sem_wait(&semph);
        if (count > BUFFER_SIZE)
        {
            exit(1);
        }
        item = rand() % BUFFER_SIZE;
        insert(item);
        sem_post(&semph);
        printf("in:  %d inserted: %d\n", in, item);
        i++;
    }
}

void *consumer(void *param)
{
    int item;
    while (1)
    {
        sem_wait(&semph);
        if (count < 0)
        {
            exit(1);
        }
        item = remove_item();
        sem_post(&semph);
        printf("out: %d removed:  %d\n", out, item);
    }
}

int main(int argc, char *argv[])
{
    int producers = atoi(argv[1]);
    int consumers = atoi(argv[2]);
    int i;
    sem_init(&semph, 0, 1); // Initialize sempahore
    for (i = 0; i < producers; i++)
    {
        pthread_create(&tid, NULL, producer, NULL); // Last argument: (void*) in
    }
    for (i = 0; i < consumers; i++)
    {
        pthread_create(&tid, NULL, consumer, NULL); // Last argument: (void*) out
    }
    pthread_join(tid, NULL);
    sem_destroy(&semph);
    return 0;
}
