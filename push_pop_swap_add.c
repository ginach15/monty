#include "monty.h"

/**
 * op_push - adds a value to the top of a stack
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	if (var.optoks[1] == NULL || isint(var.optoks[1]) != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(var.optoks[1]);
	new->prev = NULL;
	temp = *stack;

	if (temp == NULL)
		new->next = NULL;
	else
	{
		new->next = temp;
		temp->prev = new;
	}
	*stack = new;
}

/**
 * op_pop - removes a value from the top of a stack
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if ((current == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}
/**
 * op_swap - swaps the first two values in the stack
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (node2->next == NULL)
	{
		node1->prev = node2;
		node2->next = node1;
		node1->next = NULL;
		node2->prev = NULL;

		*stack = node2;
	}
	else
	{
		node1->next = node2->next;
		node2->next->prev = node1;
		node1->prev = node2;
		node2->next = node1;
		node2->prev = NULL;
		*stack = node2;
	}
}
/**
 * op_add - adds the first two values in the stack
 * stores the result in the second element of the stack then pops first element
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */
void op_add(stack_t **stack, unsigned int line_number)

{

	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	node2->n += node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
