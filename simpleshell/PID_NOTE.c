#include <unistd.h>
#include <stdio.h>
/**
 * main - Prints the PID
 * return(1) - Returns an int
 */
int main(void)
{
	int get_PID;

	get_PID = getpid();
	printf("%d\n", get_PID);
	return (1);
}
