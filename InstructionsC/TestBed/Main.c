#include <stdio.h>

int main(void)
{
	int quit = 0;
	char buf[10];
	char *p;
	long int val;

	// Main loop
	while (quit == 0)
	{
		// Print the options in the console
		printf("Select one of the following options:\n");
		printf("1a: Round-off error\n");
		printf("2a: Coin break-down\n");
		printf("2b: Coin break-down with library\n");
		printf("q: Quit application\n");
		printf("\nEnter selection: ");


		if (fgets(buf, sizeof(buf), stdin) != NULL)
		{
			val = strtol(buf, &p, 10);

			system("cls");

			if (val == 1 && *p == 'a')
				Example1a();
			else if (val == 2 && *p == 'a')
				Example2a();
			else if (val == 2 && *p == 'b')
				Example2b();
			else if (buf[0] != '\n' && *p == 'q') 
			{
				quit = 1;
				continue;
			}
			else 
			{
				printf("Invalid input\n\n");
				continue;
			}
			printf("\nPress Enter to continue...\n");
			getchar();
		}
		// Clear the console window
		system("cls");
	}
	return 0;
}