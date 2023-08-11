#include <stdio.h>

int main() {

   printf("File :%s\n", __FILE__ ); //This contains the current filename as a string literal.
   printf("Date :%s\n", __DATE__ ); //The current date as a character literal in "MMM DD YYYY" format.
   printf("Time :%s\n", __TIME__ ); //The current time as a character literal in "HH:MM:SS" format.
   printf("Line :%d\n", __LINE__ ); //This contains the current line number as a decimal constant.
   printf("ANSI :%d\n", __STDC__ ); //Defined as 1 when the compiler complies with the ANSI standard.

}