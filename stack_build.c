#include "monty.h"
/**
 * stack_build- builds a new stack
 * Return: the stack
*/
stack_t *stack_build()
{
	stack_t *stack = malloc(sizeof(stack_t));

	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack->prev = NULL;
	stack->next = NULL;

	return (stack);
}
