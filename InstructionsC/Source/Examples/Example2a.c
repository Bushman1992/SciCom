/****************************************************************************
*                                                                          *
* File    : main.c  part of: example2a                                     *
*                                                                          *
* Purpose : Simple program that calculates the coins in which a certain    *
*           amount of money can be broken down.                            *
*                                                                          *
* History : Date      Reason                                               *
*           21/01/10  Created by Joris Remmers                             *
*                                                                          *
****************************************************************************/

#include <stdio.h>

void Example2a()
{
	int coins[7] = { 200, 100, 50, 20, 10, 5, 1 }; //Only 5,10,20 and 50 cent coins, 1 and 2 euro coins
	int count[7] = { 0 };	                 //Counter for each type of coin

	int amount;                     //total amount of money
	int current;                         //current amount

	char buf[10];
	char *p;
	long int val;

	printf("Enter the amount in Eurocents : ");

	if (fgets(buf, sizeof(buf), stdin) != NULL)
	{
		val = strtol(buf, &p, 10);
		if (buf[0] != '\n' && (*p == '\n' || *p == '\0'))
			amount = val;
		else
			amount = 0;
	}

	current = amount;                    //set total to current

	int i = 0;

	while (current > 0)
	{
		if (current >= coins[i])
		{
			count[i] = count[i] + 1;
			current = current - coins[i];
		}
		else
		{
			i = i + 1;
		}
	}

	printf("The sum of %i cents, can be paid using the following coins\n", amount);

	for (i = 0; i < 7; i++)
	{
		printf("%i coins of %i cent\n", count[i], coins[i]);
	}

}
