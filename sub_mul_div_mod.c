#include "monty.h"
/**
 * op_sub - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2->n -= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
/**
 * op_mul - multiplies the second and first elements of the stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)

	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2->n *= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
/**
 * op_div -  divides the second element of stack by first element of stack
 * @stack- pointer to the stack
 * @line_number: line where opcode appears
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node2->n /= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
/**
 * op_mod - computes remainder of division of top second element by first
 * element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node2->n %= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
