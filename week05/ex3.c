#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 32
int ITEMS = 0;
pthread_cond_t BUFFER_IS_EMPTY, BUFFER_IS_FULL;

void *producer(void *n) {
  for (;;) {
    if (ITEMS == BUFFER_SIZE) {
      printf("[+] Producer sleep [+]\n");
      sleep(1);
    }

    printf("[+] Item produced [+]\n");
    ITEMS++;
    if (ITEMS == 1) {
      printf("[+] Time to wake up consumer [+]\n");
      pthread_cond_signal(&BUFFER_IS_FULL);
    }
  }
}

void *consumer(void *n) {
  for (;;) {
    if (ITEMS == 0) {
      printf("[+] Consumer sleep [+]\n");
      sleep(1);
    }

    printf("[+] Item consumed [+]\n");
    ITEMS--;
    if (ITEMS == BUFFER_SIZE - 1) {
      printf("[+] Time to wake up producer [+]\n");
      pthread_cond_signal(&BUFFER_IS_EMPTY);
    }
  }
}

int main() {
  pthread_t CONSUMER, PRODUCER;
  pthread_cond_init(&BUFFER_IS_EMPTY, 0);
  pthread_cond_init(&BUFFER_IS_FULL, 0);

  pthread_create(&CONSUMER, NULL, consumer, NULL);
  pthread_create(&PRODUCER, NULL, producer, NULL);

  pthread_join(CONSUMER, 0);
  pthread_join(PRODUCER, 0);

  return 0;
}
