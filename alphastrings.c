#include <stdio.h>
#include <string.h>

int main() {

  char ABCString[30];
  for (int i = 0; i < 26; i++) { 
    ABCString[i] = 'a' + i;
  }

  char ABCString2[] = "abcdefghijklmnopqrstuvwxyz";

  char* myStrP = ABCString;
  char* myStrP2 = ABCString2;

  printf("two strings: %s %s\n", myStrP, myStrP2);

   if (strcmp(ABCString, ABCString2) == 0)
    printf("the strings are identical\n");
  else
    printf("the strings are different\n");

  for (int i = 0; i < 26; i++) { 
    ABCString[i] -= 32;
}

   if (strcmp(ABCString, ABCString2) == 0)
    printf("the strings are identical\n");
  else
    printf("the strings are different\n");

  char ABCString3[100];
  strcpy(ABCString3, ABCString);
  strcat(ABCString3, ABCString2);

  char* myStrP3 = ABCString3;

  printf("three strings:%s %s %s\n", myStrP, myStrP2, myStrP3);
}

