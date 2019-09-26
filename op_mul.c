#include "monty.h"
/**
* op_mul - function that mul top next value
* with the previous one
* @stack: double linkes list that allocate data
* @line_number: line of file that have been read
*/
void op_mul(stack_t **stack, unsigned int line_number)
{
	int copynumstack1, copynumstack2, mul;


	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	copynumstack1 = (*stack)->n;
	copynumstack2 = (*stack)->next->n;
	mul = copynumstack2 * copynumstack1;

	op_pop(stack, line_number);
	(*stack)->n = mul;
}

