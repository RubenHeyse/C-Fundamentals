#include <stdio.h>

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card;

// Same format as "enum week today;", but initialises the Enum type at the same time as declaring.

int main() 
{
    card = club;
	printf("Size of enum variable = %d bytes", sizeof(card));	
	return 0;
}