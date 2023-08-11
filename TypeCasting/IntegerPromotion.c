#include <stdio.h>

//Integer promotion is the process by which values of integer type "smaller" than int or unsigned int are converted either to int or unsigned int. 

main() {

  int  i = 17;
  char c = 'c'; /* ascii value is 99 */
  int sum;

  sum = i + c;
  printf("Value of sum : %d\n", sum );
}