#include "monty.h"

/**
 * op_rotl - rotates the stack to the left
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *tail;
	(void)line_number;
	if (current == NULL)
		return;
	if (current->next != NULL)
	{
		tail = current;
		current->next->prev = NULL;
		*stack = current->next;

		while (current->next != NULL)
			current = current->next;
		tail->next = NULL;
		current->next = tail;
		tail->prev = current;
	}
}
/**
 * op_rotr - rotates the stack to the right
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *current = *stack;

	(void)line_number;
	if (current == NULL)
		return;
	if (current->next != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		head = current;
		head->prev->next = NULL;
		head->prev = NULL;
		current = *stack;
		head->next = current;
		current->prev = head;
		*stack = head;
	}
}
