#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * <sys /types.h> - This is not necessary because the the pid_t is included in the #include <unistd.h> already so i can use it without this libary included
 * main - Basics of a shell
 * return - Return 0
 */
int main(void)
{
	pid_t pid;

	// Create a child process
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// Child process
		printf("Child process is running\n");
		sleep(3);
		printf("Child process is done\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Parent process
		printf("Parent process is waiting for the child to finish...\n");
		wait(NULL);
		printf("Parent process is done\n");
	}

	return (0);
}
