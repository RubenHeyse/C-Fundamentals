#include <stdio.h>
#include <string.h>

/*
The C library function char *strstr(const char *haystack, const char *needle) function finds the first occurrence of the substring needle in the string haystack. The terminating '\0' characters are not compared.
*/

int main () {
  const char haystack[20] = "TutorialsPoint";
  const char needle[10] = "Point";
  char *ret;

  ret = strstr(haystack, needle);

  printf("The substring is: %s\n", ret);
  
  return(0);
}