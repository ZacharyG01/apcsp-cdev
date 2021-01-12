#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 1.56;
  float e = 9.1;

  printf("The value of d is %f and its address is %p\n", d, &d);
  printf("The value of e is %f and its address is %p\n", e, &e);
  
  float* ptrtod = &d;
  float* ptrtoe = &e;
  float tmp = d;
  *ptrtod = e;
  *ptrtoe = tmp;

 printf("The value of d is %f and the value of e is %f\n", d, e);
}
