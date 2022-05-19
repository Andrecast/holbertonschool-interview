#include <unistd.h>
#include <stdlib.h>

/**
 * multiplicar - multiply two strings of digits, with leading 0s truncated
 *
 * @num1: first number
 * @len1: length of first number
 * @num2: second number
 * @len2: length of second number
 *
 * Return: 98 on error or 0 on success
 */
int multipli(char num1[], long int len1, char num2[], long int len2)
{
	long int i1, i2, conti;
	int cont;
	char *printnum, *start;

	printnum = malloc(len1 + len2 + 1);
	if (printnum == NULL)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	for (i1 = 0; i1 < len1 + len2 + 3; i1++)
		printnum[i1] = 0;
	for (i1 = len1 - 1; i1 >= 0; i1--)
		for (i2 = len2 - 1; i2 >= 0; i2--)
		{
			printnum[i1 + i2 + 1] += ((num1[i1] - '0') *
						  (num2[i2] - '0'));
			for (conti = i1 + i2 + 1; printnum[conti] > 9;
			     conti--)
			{
				cont = printnum[conti] / 10;
				printnum[conti - 1] += cont;
				printnum[conti] %= 10;
			}
		}
	for (i1 = len1 + len2 - 1; i1 >= 0; i1--)
		printnum[i1] += '0';
	for (start = printnum; *start == '0' && start[1] != 0; start++)
		len1--;
	write(1, start, len1 + len2);
	write(1, "\n", 1);
	free(printnum);
	return (0);
}

/**
 * _error - write "Error" line and return 98
 *
 * Return: 98
 */
int _error(void)
{
	write(1, "Error\n", 6);
	return (98);
}

/**
 * main - multiply two numbers strings
 *
 * @argc: number of arguments
 * @argv: command name, first number, second number
 *
 * Return: 98 if error, 0 if success
 */
int main(int argc, char *argv[])
{
	char *n1, *n2;
	long int len1, len2;

	if (argc != 3)
		return (_error());
	len1 = 0;
	for (n1 = argv[1]; *n1 != 0; n1++, len1++)
		if (*n1 < '0' || *n1 > '9')
			return (_error());
	len2 = 0;
	for (n2 = argv[2]; *n2 != 0; n2++, len2++)
		if (*n2 < '0' || *n2 > '9')
			return (_error());
	if (len1 == 0 || len2 == 0)
		return (_error());
	for (n1 = argv[1]; *n1 == '0' && n1[1] != 0; len1--)
		n1++;
	for (n2 = argv[2]; *n2 == '0' && n2[1] != 0; len2--)
		n2++;
	return (multiplic(n1, len1, n2, len2));
}
