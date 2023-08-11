/*
  type arrayName [ arraySize ];
  double balance[10];
  double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
  double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
*/

#include <stdio.h>
 
int main () {

  int n[ 10 ]; /* n is an array of 10 integers */
  int i,j;

  /* initialize elements of array n to 0 */         
  for ( i = 0; i < 10; i++ ) {
    n[ i ] = i + 100; /* set element at location i to i + 100 */
  }
  
  /* output each array element's value */
  for (j = 0; j < 10; j++ ) {
    printf("Element[%d] = %d\n", j, n[j] );
  }

  return 0;
}