#include "lib.h"
#define BUF_SIZE 1024
/**
 * main - Factorize as many numbers as possible
 * @argc: Number of arguments
 * @argv: Pointer to arguments
 * Return: int value
 */
int main(int argc, char **argv)
{
	FILE *fip;
	char *buf = calloc(BUF_SIZE, sizeof(char));
	size_t s_buf = 255;
	ssize_t lines = 0;
	if (argc != 2)
		exit(EXIT_FAILURE);
	fip = fopen(argv[1], "r");
	if (fip == NULL)
		exit(EXIT_FAILURE);
	lines = getline(&buf, &s_buf, fip);
	while (lines != -1)
	{
		factor(buf);
		lines = getline(&buf, &s_buf, fip);
	}

	return (0);
}
/**
 * factor - Factorize as many numbers as possible
 * @buf: string to be converted to number
 * Return: void
 */
void factor(char *buf)
{
	unsigned long long int num = atoll(buf), i = 2;
	int x = 0;
	while (i < num)
	{
		if (num % i == 0)
			break;
		else
			i++;
	}
	while (buf[x] != '\n')
	{	
		putc(buf[x],stdout);
	x++;
	}	
	printf("=%lld*%lld\n", num / i, i);
}