#include "monty.h"
/**
 * pint- prints a value on top
 * @stack: the stack to be checked
 * @line_number: number of the instruction in line
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (empty_stack(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * free_stack- frees a stack
 * @stack: a list of elements pushed
 * Return: nothing
*/
void free_stack(stack_t *stack)
{
	if (stack != NULL)
	{
		free(stack);
	}
}
