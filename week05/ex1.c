#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *myThread(void *arg) {
  printf(">> Hello from thread № %d\n", arg);
  pthread_exit(NULL);
}

void parallel() {
  pthread_t thread[7];
  for (int i = 0; i < 7; i++) {
    pthread_create(&thread[i], NULL, myThread, (void *)i);
  }
  for (int i = 0; i < 7; i++) {
    pthread_join(thread[i], NULL);
  }
}

void sequential() {
  pthread_t thread[7];
  for (int i = 0; i < 7; i++) {
    pthread_create(&thread[i], NULL, myThread, (void *)i);
    pthread_join(thread[i], NULL);
  }
}

int main() {
  printf("Parallel execution:\n");
  parallel();
  printf("Sequential execution:\n");
  sequential();
  return 0;
}
