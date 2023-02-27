#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 20

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t mutex;
sem_t full;
sem_t empty;

pthread_t tid;

void insert(int item)
{
    sem_wait(&empty); // Blocks producer when buffer is full
    sem_wait(&mutex); // Critical Code Lock

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    printf("in: %d, inserted: %d\n", in, item);
    sleep(1);

    sem_post(&mutex); // Critical Code Release
    sem_post(&full);  // Buffer space is occupied
}

int remove_item()
{
    int item;
    sem_wait(&full);  // Blocks consumer when buffer is full
    sem_wait(&mutex); // Critical Code Lock

    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    printf("out: %d, removed: %d\n", out, item);
    sleep(1);

    sem_post(&mutex); // Critical Code Release
    sem_post(&empty); // Buffer Space is available

    return item;
}

void *producer(void *param)
{
    int item;
    while (1)
    {
        item = rand() % BUFFER_SIZE;
        insert(item);
    }
}

void *consumer(void *param)
{
    int item;
    while (1)
    {
        item = remove_item();
    }
}

int main(int argc, char *argv[])
{
    printf("Producer/Consumer Synchronization Problem using Semaphores\n");
    int producers = 2;
    int consumers = 1;
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    for (i = 0; i < producers; i++)
        pthread_create(&tid, NULL, producer, NULL);

    for (i = 0; i < consumers; i++)
        pthread_create(&tid, NULL, consumer, NULL);

    pthread_join(tid, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}