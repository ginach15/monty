#ifndef HEADER_H
#define HEADER_H
/* standard libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO alx project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;

} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;

	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct mystruct_s - storing a variable here
 * @optoks: lines of opcode stored here
 * Description: this is where I am storing a variable
 * so that I can use it in multiple functions
 */
typedef struct mystruct_s

{

	char **optoks;

} mystruct;
/* the one global variable I am allowed to use */
mystruct var;
/* function that finds which function to call */
void get_op_func(stack_t **, unsigned int);
/* functions that print value(s) from stack */
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
/* functions that manipulate the stack */
void op_push(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
/* functions that do math on values in the stack and pops first element */
void op_add(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
/* function that doesn't do anything to stack */
void op_nop(stack_t **stack, unsigned int line_number);
/* other helper functions */
int isint(char *s);
char **split_string(char *line, char *delim);
#endif
