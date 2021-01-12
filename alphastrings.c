#include <stdio.h>
#include <string.h>

int main()
{

  char stringA[] = "abcdefghijklmnopqrstuvwxyz";

  char stringB[] = "abcdefghijklmnopqrstuvwxyz";

  if (strcmp(stringA, stringB) == 0)
	printf("the strings are the same\n");
  else
	printf("the strings are not the same\n");
 
  for (int i = 0; i < strlen(stringB); i++)
  { 	
	stringB[i] -= 32;
  }
  printf("stringB: %s \n", stringB);

  if (strcmp(stringA, stringB) == 0)
	  printf("the new strings are the same\n");
  else
	  printf("the new strings are not the same\n");

  char stringC[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  printf("%s %s %s \n", stringA, stringB, stringC);

}

