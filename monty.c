#include "monty.h"
global_var var_global;
/**
 * main - driver function monty 
 * @elem1: first element
 * @elem2: second element
 * Return: zero
 */
int main(int elem1, char **elem2)
{
	stack_t *stack;

	stack = NULL;
	if (elem1 != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(elem2[1], &stack);
	free_dlistint(stack);
	return (0);
}
