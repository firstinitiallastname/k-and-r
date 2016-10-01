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

int main()
{
	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr-20)
	{
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}


