#include "main.h"

/**
* execute - executes the commands
* @cmd: run commands
* Return: 0 on Success or -1 if is exit or 1 if any other error
*/

int execute(char **cmd)
{
	pid_t child_pid;
	int status;

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);

	return (0);
}


/**
* main - entry point of simple shell
* @argc: number of arguments
* @argv: list of command line arguments
* Return: always 0 and -1 on error
*/

int main(int argc, char **argv)
{
	int feedback;
	char **splits;
	size_t bufsize = BUFFSIZE;
	int pipe = 0;
	char *buffer;

	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	buffer = (char *)malloc(bufsize * sizeof(char));

	if (buffer == NULL)
	{
		perror("Buffer allocation error");
		exit(1);
	}

	do {
		if (isatty(fileno(stdin)))
		{
			pipe = 1;
			_puts("cisfun#: ");
		}
		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		splits = stringSplit(buffer);
		feedback = execute(splits);
	} while (pipe && feedback != -1);

	return (0);
}
