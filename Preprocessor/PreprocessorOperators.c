#define  message_for(a, b)  \ //The macro continuation operator (\) is used to continue a macro that is too long for a single line
   printf(#a " and " #b ": We love you!\n")

//===========================================

#include <stdio.h>

#define  message_for(a, b)  \
   printf(#a " and " #b ": We love you!\n") //# converts a macro parameter into a string constant

int main(void) {
   message_for(Carole, Debra);
   return 0;
}

//===========================================

#include <stdio.h>
//The token-pasting operator (##) within a macro definition combines two arguments. It permits two separate tokens in the macro definition to be joined into a single token
#define tokenpaster(n) printf ("token" #n " = %d", token##n)

int main(void) {
   int token34 = 40;
   tokenpaster(34);
   return 0;
}

//===========================================

#include <stdio.h>

/*
The preprocessor defined operator is used in constant expressions to determine if an identifier is defined using #define. If the specified identifier is defined, the value is true (non-zero). If the symbol is not defined, the value is false (zero)
*/

#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

int main(void) {
   printf("Here is the message: %s\n", MESSAGE);  
   return 0;
}