#include "Example2Lib.h"

//----------------------------------------------------------
//  Read total amount of money
//  
//  Returns: amount (int)
//----------------------------------------------------------

int read( void )

{
	int amount;

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

	return amount;
}

//----------------------------------------------------------
//  Splits an amount in a number of coins
//  
//  Arg. amount     total amount of money
//       count      array that counts the number of coins used
//       coins      array with values of specific coins
//----------------------------------------------------------

void split

	( int     amount ,
	  int*    count  ,
	  int*    coins  )

{	
	int i = 0;

  	while( amount > 0 )
  	{ 
   		if ( amount >= coins[i] )
    	{
      		count[i] = count[i] + 1;
      		amount   = amount - coins[i];
    	}
    	else
    	{
      		i = i+1;
    	}
  	}
}


//----------------------------------------------------------
//  Writes a report of the algorithm
//  
//  Arg. amount     total amount of money
//       count      array that counts the number of coins used
//       coins      array with values of specific coins
//       n          number of different coin types
//----------------------------------------------------------

void report

	( int     amount ,
	  int*    count  ,
	  int*    coins  ,
	  int     n      )

{
	int i;

	printf("The sum of %i cents, can be paid using the following coins\n",amount);

  	for ( i = 0 ; i < n ; i++ )
  	{
  	  	printf("%i coins of %i cent\n",count[i],coins[i]);
  	}
}
