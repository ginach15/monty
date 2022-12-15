#include "monty.h"

/**
 * op_pall - prints each stack element on a new line
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */

void op_pall(stack_t **stack, unsigned int line_number)

{

	stack_t *current = *stack;

	(void)line_number;

	for (; current != NULL; current = current->next)

		printf("%i\n", current->n);

}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */

void op_pint(stack_t **stack, unsigned int line_number)

{

	stack_t *current = *stack;

	if ((*stack == NULL) || (stack == NULL))

	{

		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

		exit(EXIT_FAILURE);

	}

	else

		printf("%i\n", current->n);

}

/**
 * op_nop - does nothing
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */

void op_nop(stack_t **stack, unsigned int line_number)

{

	(void)stack;

	(void)line_number;

}

/**
 * op_pchar - prints the character at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */

void op_pchar(stack_t **stack, unsigned int line_number)

{

	stack_t *current = *stack;

	if ((stack == NULL) || (current == NULL))

	{

		fprintf(stderr, "L%u: can't pchar, stack empty\n",

				line_number);

		exit(EXIT_FAILURE);

	}

	if ((current->n > 32) && (current->n < 127))

		printf("%c\n", current->n);

	else

	{

		fprintf(stderr, "L%u: can't pchar, value out of range\n",

				line_number);

		exit(EXIT_FAILURE);

	}

}
/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */

void op_pstr(stack_t **stack, unsigned int line_number)

{

	stack_t *current = *stack;

	(void)line_number;

	for (; current != NULL; current = current->next)

	{

		if ((current->n > 32) && (current->n < 127))

			printf("%c", current->n);

		else

			break;

	}

	printf("\n");

}

