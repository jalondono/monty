#include "monty.h"
/**
* op_pchar - f prints the char at the top of the stack
* @stack: double linkes list that allocate data
* @line_number: line of file that have been read
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *copystack = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", copystack->n);
}
