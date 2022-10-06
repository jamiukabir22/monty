#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"
/**
 * pint - prints the top data
 * @stack: given by main
 * @line_cnt: amount of ines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
Footer
© 2022
