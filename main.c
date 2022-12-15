#include "monty.h"
/**
 * main - interprets Monty ByteCodes files
 * @ac: number of arguments
 * @av: pointers to the arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	unsigned int lineno = 0;
	char *buffer = NULL, *sp = " \n";
	size_t buffer_size;
	FILE *stream;
	stack_t *head = NULL, *temp;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE); }
	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE); }
	while (getline(&buffer, &buffer_size, stream) != -1)
	{
		lineno++;
		var.optoks = split_string(buffer, sp);
		if (var.optoks[0] != NULL)
		{
			if (var.optoks[0][0] == '#')
			{
				free(var.optoks);
				continue; }
			else
				get_op_func(&head, lineno);
			free(var.optoks); }
		else
		{
			free(var.optoks);
			continue; } }
	free(buffer);
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp); }
	fclose(stream);
	return (0); }
