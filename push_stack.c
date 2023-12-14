#include "monty.h"
/**
 * push_stack- adds an integer to the stack
 * @stack: where to add the integer
 * @n: integer to push
 * Return: nothing
*/
void push_stack(stack_t **stack, int n)
{
	stack_t *node_new = malloc(sizeof(stack_t));

	if (!node_new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node_new->n = n;
	node_new->prev = NULL;
	node_new->next = *stack;

	if (*stack)
		(*stack)->prev = node_new;
	*stack = node_new;
}
