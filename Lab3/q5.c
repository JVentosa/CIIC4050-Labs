#include <pthread.h>

#include <semaphore.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

int in = 0;

int out = 0;

pthread_t tid;

pthread_cond_t nEmpty;

pthread_cond_t nFull;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void insert(int item)

{

    while ((out - in + BUFFER_SIZE) % BUFFER_SIZE == BUFFER_SIZE)

        pthread_cond_wait(&nFull, &mutex); // Block Producer, release mutex since buffer is full.

    // Loop through buffer inserting items

    buffer[in] = item;

    in = (in + 1) % BUFFER_SIZE;

    printf("in: %d, inserted: %d\n", in, item);

    sleep(1);

    pthread_cond_signal(&nEmpty); // Wake Consumer since buffer has at least one item to consume.
}

int remove_item()

{

    int item;

    while ((out - in + BUFFER_SIZE) % BUFFER_SIZE == 0)

        pthread_cond_wait(&nEmpty, &mutex); // Block Consumer, release mutex since buffer is empty.

    // Loop through buffer removing items

    item = buffer[out];

    out = (out + 1) % BUFFER_SIZE;

    printf("out: %d, removed: %d\n", out, item);

    sleep(1);

    pthread_cond_signal(&nFull); // Wake Producer, buffer has at least one space to produce.

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

    printf("Producer/Consumer Synchronization Problem using Monitors\n");

    int producers = 2;

    int consumers = 1;

    int i;

    pthread_cond_init(&nEmpty, NULL);

    pthread_cond_init(&nFull, NULL);

    for (i = 0; i < producers; i++)

        pthread_create(&tid, NULL, producer, NULL);

    for (i = 0; i < consumers; i++)

        pthread_create(&tid, NULL, consumer, NULL);

    pthread_join(tid, NULL);

    pthread_cond_destroy(&nFull);

    pthread_cond_destroy(&nEmpty);
}