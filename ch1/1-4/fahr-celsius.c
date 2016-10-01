/*
 * =====================================================================================
 *
 *       Filename:  fahr-celsius.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2015 09:07:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/* Print fahrenheit-celsius conversion table */
#define LOWER 0
#define UPPER 300
#define STEP 20


int main()
{
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr+STEP)
	{
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}
