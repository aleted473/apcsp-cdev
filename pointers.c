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

  int d;
  int* ptrtod;

  ptrtod = &d;

  d = 10;
  printf("The value of d is %d\n", d);

  printf("The address of d is %p\n", (void*)&d);
	
  int e;
  int* ptrtoe;

  ptrtoe = &e;

  e = 15; 
  printf("The value of e is %d\n", e);

  printf("The address of e is %p\n", (void*)&e);

  e = *ptrtod;

  d = *ptrtoe;
  

}
