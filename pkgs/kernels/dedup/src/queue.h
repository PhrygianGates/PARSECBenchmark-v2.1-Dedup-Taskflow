#ifndef QUEUE_H
#define QUEUE_H

#include "util.h"
#include "config.h"

#ifdef PTHREADS
#include <pthread.h>
#endif //PTHREADS

struct queue {
  int head, tail;
  void ** data;
  int size;
  int threads;
  int end_count;
#ifdef PTHREADS
  pthread_mutex_t mutex;
  pthread_cond_t empty, full;
#endif //PTHREADS
};
void queue_signal_terminate(struct queue * que);
void queue_init(struct queue * que, int size, int threads);
int dequeue(struct queue * que, int * fetch_count, void ** to_buf);
int enqueue(struct queue * que, int * fetch_count, void ** from_buf);

#endif //QUEUE
