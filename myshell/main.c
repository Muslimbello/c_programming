#include "main.h"
/**
 * main - Main entry point for our program
 * @argc: Argument count to the main
 * @argv: Pointer to array of argument values
 *
 * Return: O Always success
 */

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	char *buff = NULL;
	size_t count = 0;
	ssize_t nread = 0;
	pid_t child_pid;
	int status;
	char *token;
	char **array;
	int i;
	char name[] = "Myshell$";
	int len_name = strlen(name);

	while (1)
	{
		write(STDERR_FILENO, name, len_name);
		nread = getline(&buff, &count, stdin);
		token = strtok(buff, " \n");

		array = malloc(sizeof(char *) * 1024);

		if (nread == -1)
		{
			perror("Exit shell");
			exit(1);
		}
		i = 0;
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		array[i] = NULL;
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Failed to create.");
			exit(41);
		}

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("couldn't execute");
				exit(1);
			}
		}
		else
		{
			/* Wait for the child process to execute before terminating the parent process */
			wait(&status);
		}
	}
	free(buff);
	return (0);
}
// #include "main.h"

// /**
//  * main - Getline function
//  * @argc: Argument count
//  * @argv: Array of argument values
//  *
//  * Return: 0 on success
//  */

// int main(int argc, char **argv)
// {
// 	(void)argc, (void)argv;
// 	char *buf = NULL, *token;
// 	size_t count = 0;
// 	ssize_t nread;
// 	pid_t child_pid;
// 	int i, status;
// 	char **array;

// 	while (1)
// 	{
// 		write(STDOUT_FILENO, "MyShell$ ", 9);

// 		nread = getline(&buf, &count, stdin);

// 		if (nread == -1)
// 		{
// 			perror("Exiting shell");
// 			exit(1);
// 		}

// 		token = strtok(buf, " \n");

// 		array = malloc(sizeof(char *) * 1024);
// 		i = 0;

// 		while (token)
// 		{
// 			array[i] = token;
// 			token = strtok(NULL, " \n");
// 			i++;
// 		}

// 		array[i] = NULL;

// 		child_pid = fork();

// 		if (child_pid == -1)
// 		{
// 			perror("Failed to create.");
// 			exit(41);
// 		}

// 		if (child_pid == 0)
// 		{
// 			if (execve(array[0], array, NULL) == -1)
// 			{
// 				perror("Failed to execute");
// 				exit(97);
// 			}
// 		}
// 		else
// 		{
// 			wait(&status);
// 		}
// 	}
// 	free(buf);
// 	return (0);
// }