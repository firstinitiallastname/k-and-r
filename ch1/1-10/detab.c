/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space the next tab stop.  Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TAB_STOP 4 /* tab stop defined for testing */

void detab(char from[], char to[], int tab_stop); /* Write detabbed version of from to to at tab_stop spacing */
int getline(char line[], int limit); /* read line into array, up to max.  Return length */

/* Detab each input line */
int main()
{
	char line[MAXLINE]; /* current input line */
	char detab_line[4*MAXLINE]; /* input line detabbed.  Don't want any overflows */

	while (getline(line, MAXLINE) > 0)
	{
		detab(line, detab_line, TAB_STOP);
		printf("%s", line);
	}
}

int getline(char line[], int limit)
{
	int c, i;

	for (
		i = 0;
		i < limit - 1 &&
			(c = getchar()) != EOF &&
			c != '\n';
		++i)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

void detab(char from[], char to[], int tab_stop)
{
	/* track read and write points separately */
	int read_point = 0;
	int write_point = 0;
	
	// Over the entire piece:
	char read_char;
	while((read_char = from[read_point++]))
	{
		if (read_char == '\t')
		{
			// Add spaces up to next tabstop;
			while((write_point - 1) % tab_stop)
			{
				to[write_point++] = ' ';
			}
		}
		else
		{
			to[write_point++] = read_char;
		}
	}

	to[write_point] = '\0';
}
