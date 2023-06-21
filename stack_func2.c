#include "monty.h"
/**
 * _swap - swap top of line y second top line
 * @line: pointer to lists for monty line
 * @dash_no: number of line opcode occurs on
 */

void _swap(stack_t **line, unsigned int dash_no)
{
	stack_t *checker;
	int now;

	checker = *line;
	if (checker == NULL || checker->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, line too short\n", dash_no);
		exit(EXIT_FAILURE);
	}
	now = checker->n;
	checker->n = checker->next->n;
	checker->next->n = now;
}

/**
 * _add - add top of line y second top line
 * @line: point to monty lists
 * @dash_no: number of line opcode 
 */

void _add(stack_t **line, unsigned int dash_no)
{
	stack_t *now = *line;
	int val = 0, i = 0;

	if (now == NULL)
	{
		fprintf(stderr, "L%d: can't add, line too short\n", dash_no);
		exit(EXIT_FAILURE);
	}

	while (now)
	{
		now = now->next;
		i++;
	}

	if (line == NULL || (*line)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, line too short\n", dash_no);
		exit(EXIT_FAILURE);
	}
	val = (*line)->next->n + (*line)->n;
	_pop(line, dash_no);

	(*line)->n = val;
}

/**
 * _nop - nop top of line y second top line
 * @line: point to monty lists
 * @dash_no: number of line opcode 
 */

void _nop(__attribute__ ((unused))stack_t **line,
		__attribute__ ((unused)) unsigned int dash_no)
{
	;
}

/**
 * _pchar -  ASCII value  a number
 * @line: point to line to
 * @dash_no: current index
 *
 */
void _pchar(stack_t **line, unsigned int dash_no)
{
	int val;

	if (line == NULL || *line == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, line empty\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*line);
		exit(EXIT_FAILURE);
	}

	val = (*line)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*line);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - check if alphabet
 * @arg: argument
 * Return: true or false
 */
int _isalpha(int arg)
{
	if ((arg >= 97 && arg <= 122) || (arg >= 65 && arg <= 90))
		return (1);
	else
		return (0);
}
