#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * add - adds the first two nodes of the stack
 * @stack: given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack|| !*stack || !((*stack)->next))
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
	status = EXIT_FAILURE;
	return;
	}
result = ((*stack)->next->n) + ((*stack)->n);
pop(stack, line_cnt); /*for top node */
(*stack)-> = result;
}
