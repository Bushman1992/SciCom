#include <stdio.h>

int main(void)
{
	int quit = 0;
	char in[10];
	// Main loop
	while (quit == 0)
	{
		// Print the options in the console
		printf("Select one of the following options:\n");
		printf("a: Round-off error\n");
		printf("b: Round-off error extended\n");
		printf("q: Quit application\n");
		fgets(in, 10, stdin);

		//printf("%s \n", in);
		system("cls");

		switch (in[0])
		{
		case 'a':
			Example1a();
			getchar();
			break;
		case 'b':
			Example2();
			getchar();
			break;
		case 'q':
			quit = 1;
			break;
		}
		// Clear the console window
		system("cls");
	}
	return 0;
}