#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

int main () {

  FILE * pf;
  int errnum;
  pf = fopen ("unexist.txt", "rb");

  if (pf == NULL) {
  
    errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errno);
    perror("Error printed by perror"); //displays the string you pass to it, followed by a colon, a space, and then the textual representation of the current errno value.
    fprintf(stderr, "Error opening file: %s\n", strerror( errnum )); //returns a pointer to the textual representation of the current errno value.
    
  } else {
  
    fclose (pf);
  }
  
  return 0;
}