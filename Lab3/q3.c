#include <pthread.h>

#include <semaphore.h>

#include <stdio.h>

#include <stdlib.h>

#define BUFFER_SIZE 20

int count = 0, in = 0, out = 0;

int buffer[BUFFER_SIZE];

pthread_t tid;

pthread_mutex_t mutex;

void insert(int item)
{

    while (count == BUFFER_SIZE)
        ;

    buffer[in] = item;

    in = (in + 1) % BUFFER_SIZE;

    count++;

    // sleep(1);
}

int remove_item()
{

    int item;

    while (count == 0)
        ;

    item = buffer[out];

    out = (out + 1) % BUFFER_SIZE;

    count--;

    // sleep(1);

    return item;
}

void *producer(void *param)
{

    int item;

    while (1)
    {

        item = rand() % BUFFER_SIZE;

        while (count >= BUFFER_SIZE)
            ;

        pthread_mutex_lock(&mutex);

        insert(item);

        pthread_mutex_unlock(&mutex);

        printf("in: %d inserted: %d\n", in, item);
    }
}

void *consumer(void *param)
{

    int item;

    while (1)
    {

        while (count <= 0)
        {

            pthread_mutex_lock(&mutex);

            item *remove_item();

            pthread_mutex_unlock(&mutex);

            printf("out: %d removed: %d\n", out, item);
        }
    }
}

int main(int argc, char *argv[])

{

    int producers = 2;

    int consumers = 1;

    int i;

    for (i = 0; i < producers; i++)

        pthread_create(&tid, NULL, producer, NULL);

    for (i = 0; i < consumers; i++)

        pthread_create(&tid, NULL, consumer, NULL);

    pthread_join(tid, NULL);
}