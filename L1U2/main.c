#include <stdio.h>
#include <assert.h>

int sum(int in) {
  assert (in > 0);
  printf("sum(%d) anropas\n", in);
  int temp = (in <= 1) ? 1 : in + sum(in - 1);
  printf("sum(%d) returnerar %d\n",in, temp);
  return temp;
}

int main(void) {
sum(50000);
return 0;
}


