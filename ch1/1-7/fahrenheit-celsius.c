/*
 * =====================================================================================
 *
 *       Filename:  fahrenheit-celsius.c
 *
 *    Description:  convert fahrenheit to celsius
 *
 *        Version:  1.0
 *        Created:  03/21/2015 02:09:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

float fahrenheit_to_celsius(float input_fahr);

/*  print Fahrenheit-Celsius table
 *		for fahr = 0, 20, ..., 300 */
int main()
{

	float fahr;
	int lower, upper, step;

	lower = 0;		/*  lower limit of temperature table  */
	upper = 300;	/*  upper limit */
	step = 20;		/*	step size   */

	fahr = lower;

	printf ("F\tC\n");
	while (fahr <= upper)
	{
		printf("%3.0f\t%6.1f\n", fahr, fahrenheit_to_celsius(fahr));
		fahr = fahr + step;
	}
}

float fahrenheit_to_celsius(float input_fahr)
{
	return (5.0/9.0) * (input_fahr -32.0);
}

