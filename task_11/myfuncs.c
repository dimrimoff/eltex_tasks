// Copyright 2024 <dimrimoff>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "myfuncs.h"

extern pthread_mutex_t mutexes[ARRAY_SIZE];
extern int shop[ARRAY_SIZE];
extern int stop_flag;

void *ConsumerThread(void *arg) {
  Consumer *consumer = (Consumer *)arg;

  while (consumer->need > 0) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
      if (pthread_mutex_trylock(&mutexes[i]) == 0) {
        int previous_need_value = consumer->need;
        if (consumer->need > 0) {
          int previous_shop_value = shop[i];
          if (consumer->need >= shop[i]) {
            consumer->need -= shop[i];
            shop[i] = 0;
          } else {
            shop[i] -= consumer->need;
            consumer->need = 0;
          }
          printf("Thread %d reduced its needs %d by accessing shop[%d]"
                 " whith %d goods. Remaining thread needs - %d, shop[%d]"
                 " goods - %d\n", consumer->id, previous_need_value,
                 i, previous_shop_value, consumer->need, i, shop[i]);
        }
        pthread_mutex_unlock(&mutexes[i]);
        sleep(2);
      }
    }
  }
  printf("Thread %d fully satisfied its needs!!!\n\n", consumer->id);
  return NULL;
}
        
void *SupplierThread(void *args) {
  while (!stop_flag) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
      pthread_mutex_trylock(&mutexes[i]);
      int previous_shop_value = shop[i];
      shop[i] += SUPPLY_AMOUNT;

      printf("Supplier thread increased shop[%d] by %d, old value - %d,"
             "new value - %d\n", i, SUPPLY_AMOUNT, previous_shop_value,
             shop[i]);
      pthread_mutex_unlock(&mutexes[i]);
      sleep(1);
    }
  }
  return NULL;
}
