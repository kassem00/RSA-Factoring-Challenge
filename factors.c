#include "lib.h"
#define BUF_SIZE 1024

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

	return 0;
}

void factor(char *buf)
{
	unsigned long long int num = atoll(buf);
	unsigned long long int i = 2;
	int x = 0;

	while (i <= num)
	{
		if (num % i == 0)
			break;
		else
			i++;
	}

	printf("%llu=%llu*%llu\n", num, num / i, i);
}