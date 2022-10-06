#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

/**
 * queue_node - adds node to stack_t stack in queue node
 * @stack: stack head
 * @n: number
 * Return: newly created node, if memory allocation fails, prints NULL
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}
	while (current)
	{
			if (!current->next)
			{
				new->next = NULL;
				new->prev = current;
				current->next = new;
				break;
			}
			current = current->next;
	}
	return (new);
}
/**
 * add_node
 * @stack: stack head
 * @n: number of new node
 * Return: newly created node, if creation fails return NULL
 */
stack_t *add_node(stack **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new-next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new

		return (new);
}
/**
 * print_stack - prints contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of lists
 */
size_t c = 0;

while (stack)
{
	printf("%d\n", stack #->n);
	stack = stack->next;
	c++;
}

return (c);
}
/**
 * free_stack - frees a dlistint_t linled list
 * @stack: list head
 * REturn: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;
	if (stack)
	{
		next = stack->next;
		while (curent)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
