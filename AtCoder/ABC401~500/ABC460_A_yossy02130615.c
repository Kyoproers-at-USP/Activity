#include <stdio.h>

int main(void) {
  int N, M;


  if (scanf("%d %d", &N, &M) != 2) {
    return 1;
  }

  int t = 0;


  while (M != 0) {
    int x = N % M;
    M = x;
    t++;
  }