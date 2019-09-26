#include "monty.h"
/**
* op_rotr - function that changes the top value
 * with the next one, just values not address
* @stack: double linkes list that allocate data
* @line_number: line of file that have been read
*/
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copystack = *stack;

	UNUSED(line_number);
	if ((*stack)->next == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	while (copystack->next != NULL)
	{
		copystack = copystack->next;
	}
	copystack->prev->next = NULL;
	copystack->prev = NULL;
	copystack->next = (*stack);
	if ((*stack) != NULL)
		(*stack)->prev = copystack;
	(*stack) = copystack;
}
