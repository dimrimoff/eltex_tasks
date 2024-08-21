// Copyright <dimrimoff>

#ifndef MYFUNCS_H
#define MYFUNCS_H

#define ARRAY_SIZE 5
#define SUPPLY_AMOUNT 5000
#define CONSUMER_NUM 3

typedef struct {
  int id;
  int need;
} Consumer;

void *ConsumerThread (void *);

void *SupplierThread (void *);

#endif
