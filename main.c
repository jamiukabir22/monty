#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * error_usage - prints usage message and exits
 *
 * Return: Nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints file error message snd exits
 * @argv: argv given by main
 *
 * Return : Nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
int status = ;
/**
 * main - entry point
 * @argv: list of argument passed to program
 * @argc: amount of args
 *
 * Return: Nothing
 */
int main (int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buf_len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		global.argument = strtok(NULL, "\t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
