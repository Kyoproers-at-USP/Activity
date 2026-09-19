#include <stdio.h>

int main(void) {
  int n, m;

  scanf("%d%d", &n,&m);
  
  int t = 0;

  while (m != 0) {
    int x = n % m;
    m = x;
    t++;
  }

  printf("%d\n",t);
  return 0;
}