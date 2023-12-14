#include "monty.h"
/**
 * pop_stack- removes an element from the stack
 * @stack: the stack to be popped
 * Return: removed element
*/
int pop_stack(stack_t **stack)
{
	stack_t *node;
	int n;

	if (empty_stack(*stack))
	{
		fprintf(stderr, "Error: Empty stack\n");
		exit(EXIT_FAILURE);
	}
	node = *stack;
	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	n = node->n;

	free(node);
	return (n);
}
