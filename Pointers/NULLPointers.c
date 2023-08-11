/*
It is always a good practice to assign a NULL value to a pointer variable in case you do not have an exact address to be assigned. This is done at the time of variable declaration. A pointer that is assigned NULL is called a null pointer.
*/

#include <stdio.h>

int main () {

  int  *ptr = NULL;

  printf("The value of ptr is : %x\n", ptr  );

  //To check for a null pointer, you can use an 'if' statement as follows −
  if(ptr)     /* succeeds if p is not null */
  if(!ptr)    /* succeeds if p is null */

  return 0;
}