#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *main - entry point of the simple shell
 *Return: always successs
 */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t my_child;
	char *argv[2];
	int status;

	printf("#cisfun$ ");
	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';

		my_child = fork();
		if (my_child == -1)
		{
			perror("Error: fork failed");
			return (-1);
		}
		if (my_child == 0)
		{
			argv[0] = buffer;
			argv[1] = NULL;
			execve(argv[0], argv, NULL);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			printf("#cisfun$ ");
		}
	}
	free(buffer);
	return (0);
}
