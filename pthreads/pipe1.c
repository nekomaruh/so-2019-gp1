#include <stdio.h>
#include <stdlib.h>

int main() {
  fprintf(stderr, "Pipe 1 sending numbers to pipe 2\n");
  for (int i = 2; i < 101; i++) {
    printf("%d\n", i);
  }
  fprintf(stderr, "Sending end\n");
  printf("%d\n",-1);
}


