// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "myfuncs.h"

int shop[ARRAY_SIZE];
pthread_mutex_t mutexes[ARRAY_SIZE];
int stop_flag = 0;

int main() {
  srand(time(NULL));

  for (int i = 0; i < ARRAY_SIZE; ++i) {
    shop[i] = 9000 + rand() % 2000;
    pthread_mutex_init(&mutexes[i], NULL);
  }

  pthread_t consumer_threads[CONSUMER_NUM];
  Consumer consumers[CONSUMER_NUM];

  for (int i = 0; i < CONSUMER_NUM; ++i) {
    consumers[i].id = i + 1;
    consumers[i].need = 80000 + rand() % 20000;
    pthread_create(&consumer_threads[i], NULL, ConsumerThread,
                   &consumers[i]);
  }

  pthread_t supplier_thread;
  pthread_create(&supplier_thread, NULL, SupplierThread, NULL);

  for (int i = 0; i < CONSUMER_NUM; ++i) {
    pthread_join(consumer_threads[i], NULL);
  }

  stop_flag = 1;
  pthread_join(supplier_thread, NULL);

  for (int i = 0; i < ARRAY_SIZE; ++i) {
    pthread_mutex_destroy(&mutexes[i]);
  }

  printf("Simulation of life is finished!!!\n");
  return 0;
  
}
