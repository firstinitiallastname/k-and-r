/*
 * =====================================================================================
 *
 *       Filename:  word_liner.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2015 04:45:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

typedef enum { IN_WORD, OUT_WORD} word_state;

int main()
{
	word_state state = OUT_WORD;
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n' || c == ' ' || c == '\t')
		{
			state = OUT_WORD;
		}
		else if (OUT_WORD == state)
		{
			printf("\n%c",c);
			state = IN_WORD;
		}
		else
		{
			printf("%c", c);
		}
	}
	printf("\n");
}
