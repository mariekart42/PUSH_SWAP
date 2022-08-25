#include "push_swap.h"

//calling in a function "return" ends only the function
// calling in a function "exit" ends the whole programm

int prinz()
{
	printf("before\n");
	// exit(EXIT_SUCCESS);
	return(0);
	printf("after\n");
}

int main()
{
	printf("something\n");
	prinz();
	printf("Actual this??\n");
}