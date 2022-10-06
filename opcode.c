#include <string.h>
#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * opcode - function in charge of running builtins
 * @stack: given by msin
 * @str: string to compare
 * @line_cnt: amount of line
 * Return: Nothinf
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct  = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return;
		}
		i++;
	}
	fprintf(stderr,"L%d: unknown instruction %s\n", line_cnt, str);
	status = EXIT_FAILURE;
}
