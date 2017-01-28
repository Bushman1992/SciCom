#include <stdio.h>

int main(void)
{
	float  x = 1.0;
	float  d = 0.1;

	while (x > 0.0)
	{
		x = x - d;
		printf("%1.2f\n", x);
	}
	printf("Press any key to terminate\n");
	getchar();
}