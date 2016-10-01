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
	char c;
	while ((c = getchar()) != EOF)
	{
		if ( '\t' == c)
		{
			putchar('\\');
			putchar('t');
		}
		else if ('\b' == c)
		{
			putchar('\\');
			putchar('b');
		}
		else if ('\\' == c)
		{
			putchar ('\\');
			putchar ('\\');
		}
		else 
		{
			putchar(c);
		}
		
	}
}
