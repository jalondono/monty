#include"monty.h"
/**
*main - Main program
*@argc: counter of arguments
*@argv: vector of argument
*Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int main(int argc, char **argv)
{

	FILE *fd;
	char *buff = NULL, *token = NULL;
	size_t buffsize = BUFFSIZE;
	stack_t *stack = NULL;
	instruction_t *f = NULL;
	unsigned int line_number = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE:montyfile\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error:Can'topenfile%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &buffsize, fd) != -1)
	{
		line_number++;
		token = strtok(buff, DELIMITER);

		f = get_op(token);

		if (!f->opcode)
		{
			fprintf(stderr, "L%d:unknowninstruction%s\n", line_number, token);
			free(buff);
			exit(EXIT_FAILURE);
		}
		f->f(&stack, line_number);
		free(f);
	}
	free(buff);
	free_stacklist(stack);
	fclose(fd);
	return (EXIT_SUCCESS);
}
