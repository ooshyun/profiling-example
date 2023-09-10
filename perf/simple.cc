#include <stdio.h>
#include <unistd.h>

#define ITERATION_COUNTER  100000000

static char array[1000][1000];

void func1() {
  int i, j;

  for (i = 0; i < 1000; i++)
    for (j = 0; j < 1000; j++)
       array[j][i]++;
}

void func2() {
  int i, j;

  for (i = 0; i < 1000; i++)
    for (j = 0; j < 1000; j++)
       array[i][j]++;
}

void wait() {
  for (int i = 0; i < ITERATION_COUNTER; i++);
}

int main(int argc, char **argv) {
  for (int i = 0; i < 4; i++) {
    printf("Step %d\n", i);
    fflush(stdout);

    for (int i = 0; i < ITERATION_COUNTER/2; i++);

    wait();
  }

  func1();
  func2();

  return 0;
}
