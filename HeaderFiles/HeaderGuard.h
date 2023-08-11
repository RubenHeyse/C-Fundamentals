// If a header file happens to be included twice, the compiler will process its contents twice and it will result in an error. The standard way to prevent this is to enclose the entire real contents of the file in a conditional, like this

#ifndef HEADER_FILE
#define HEADER_FILE

// the entire header file 

#endif