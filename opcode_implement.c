#include "monty.h"
instruction_t op_commands[] = {
	{ "push", push },
	{ "pall", pall },
};
/**
 * implement_opcodes- reading monty files and implementing them
 * @opcode: type of instruction
 * Return: the opcode instrucion
*/
instruction_t *implement_opcodes(char *opcode)
{
	unsigned int i;

	for (i = 0; i < sizeof(op_commands) / sizeof(op_commands[0]); i++)
	{
		if (strncmp(op_commands[i].opcode, opcode,
		strlen(op_commands[i].opcode)) == 0)
		{
			return (&op_commands[i]);
		}
	}
	return (NULL);
}
/**
 * push- adds an element to the stack
 * @stack: this is the stack where element is to be added
 * @line_number: the line where instruction is held
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *val = strtok(NULL, " ");
	int n;

	if (!val)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(val);

	push_stack(stack, n);
}

/**
 * pall- prints all the value from top
 * @stack: stack to print
 * @line_number: number of line to count
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
	line_number++;
}
/**
 * empty_stack- checks if stack is empty
 * @stack: the list to be checked
 * Return: false stack
*/
int empty_stack(stack_t *stack)
{
	return (!stack);
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
