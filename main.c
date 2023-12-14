#include "monty.h"
/**
 * main- reads and check the arguments into the program
 * @argc: the argument counts
 * @argv: the argument type checked
 * Return: 0 if successful
*/

int main(int argc, char *argv[])
{
	FILE *open_file;
	stack_t *stack;
	char line[LINE_SIZE];
	char *opcode;
	instruction_t *op_commands;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	open_file = fopen(argv[1], "r");

	if (!open_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = stack_build();

	while (fgets(line, sizeof(line), open_file))
	{
		opcode = strtok(line, " ");
		if (!opcode)
			continue;
		op_commands = implement_opcodes(opcode);

		if (!op_commands)
		{
			fprintf(stderr, "Unknown opcode: %s\n", opcode);
			exit(EXIT_FAILURE);
		}
		op_commands->f(&stack, 1);
	}
	fclose(open_file);
	return (0);
}
