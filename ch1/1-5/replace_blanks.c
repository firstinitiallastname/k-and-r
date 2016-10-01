/*
 * =====================================================================================
 *
 *       Filename:  countblanks.c
 *
 *    Description:  Program to count blanks in input
 *
 *        Version:  1.0
 *        Created:  03/26/2015 08:50:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main()
{
	char c, c_last = 0;
	long int count = 0;
	while ((c = getchar()) != EOF)
	{
		if ((' ' == c) && (' ' == c_last))
		{
		}
		else
		{
			putchar(c);
		}
		c_last = c;

		
	}
}
