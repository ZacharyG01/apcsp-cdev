#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %d bytes\n", a, sizeof(a));

  char b = 'a';

  printf("char b value: %d and size: %d bytes\n", b, sizeof(b));

  float c = 3.1;
  
  printf("float c value: %f and size %d bytes\n", c, sizeof(c));

  unsigned int d = 5;

  printf("unsigned int value: %d and size: %d bytes\n", d, sizeof(d));

  long int e = 1000000;

  printf("long int value: %d and size: %d bytes\n", e, sizeof(e));
}

