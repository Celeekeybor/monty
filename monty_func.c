#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathfile
 * @pile: point  top of the pile
 */
void read_file(char *filename, stack_t **pile)
{
	char *column;
	size_t val = 0;
	int queue_no = 1;
	instruct_func s;
	int scan;
	int take;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((take = getline(&var_global.buffer, &val, var_global.file)) != -1)
	{
		column = parse_line(var_global.buffer, pile, queue_no);
		if (column == NULL || column[0] == '#')
		{
			queue_no++;
			continue;
		}
		s = get_op_func(column);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", queue_no, column);
			exit(EXIT_FAILURE);
		}
		s(pile, queue_no);
		queue_no++;
	}
	free(var_global.buffer);
	scan = fclose(var_global.file);
	if (scan == -1)
		exit(-1);
}

/**
 * get_op_func -  check opcode and function
 * @str: opcode
 * Return: true or false
 */
instruct_func get_op_func(char *str)
{
	int val;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	val = 0;
	while (instruct[val].f != NULL && strcmp(instruct[val].opcode, str) != 0)
	{
		val++;
	}

	return (instruct[val].f);
}

/**
 * isnumber - checks if it is a number
 * @str: string to be checked
 * Return: true or false
 */
int isnumber(char *str)
{
	unsigned int val;

	if (str == NULL)
		return (0);
	val = 0;
	while (str[val])
	{
		if (str[0] == '-')
		{
			val++;
			continue;
		}
		if (!isdigit(str[val]))
			return (0);
		val++;
	}
	return (1);
}

/**
 * parse_line - parses a column
 * @column: the column to be parsed
 * @pile: pointer to the head of the pile
 * @number: the current column number
 * Return: zero
 */
char *parse_line(char *column, stack_t **pile, unsigned int number)
{
	char *op_code, *push, *arg;
	(void)pile;

	push = "push";
	op_code = strtok(column, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
