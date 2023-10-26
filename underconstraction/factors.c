#include "lib.h"
#define BUF_SIZE 1024
/**
 * factor - Factorize as many numbers as possible
 * @buf: string to be converted to number
 * Return: void
 */
void factor(char *buf)
{
	unsigned long long int num = atoll(buf),         i = 2;
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

/**
 * g_g_fun - spcafic getline from file
 * @line: string to be converted to number
 * @file: string to be converted to number
 * Return: void
 */
void g_g_fun(int line, char file[])
{
	FILE *fip;
	char *buf = calloc(BUF_SIZE, sizeof(char));
	int x = 0;
	size_t s_buf = 255;
	ssize_t lines = 0;
	fip = fopen(file, "r");
	if (fip == NULL)
		exit(EXIT_FAILURE);
	while ((lines = getline(&buf, &s_buf, fip)) != -1)
	{
		if(line == x)
			break;
		else
			x++;
	}
	factor(buf);
	fclose(fip);
}
