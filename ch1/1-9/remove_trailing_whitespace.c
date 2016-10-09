/* 
 * Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines 
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

#define Assert_msg(invariant, msg) \
		if (invariant) {\
			printf(msg);\
			while(1) \
			{\
				;\
			}\
		}

int getline(char line[], int maxline); /* gets one line of data */
int trim_trailing_whitespace(char line[]); /* crops any trailing whitespace. Returns length */
int is_whitespace(char check); /* Return 0 if not whitespace */

/* Print each line without trailing whitespace, remove blanks: */
int main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = getline(line, MAXLINE)) > 0)
	{

#if DEBUG
		printf ("got line %s", line);
#endif

		if (trim_trailing_whitespace(line) > 0)
		{
			printf("%s", line);
		}
	}
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (
		i = 0; 
		i < lim - 1 &&
			(c = getchar()) != EOF &&
			c != '\n';
		++i)
	{
		s[i] = c;
	}

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/*  trim to last non-whitespace character.  Assume that line is null-terminated.  Return null-terminated and with correct line ending*/
int trim_trailing_whitespace(char line[])
{
	int trim_point;
	int cur = 0;
	char next_char;
	
	// Find last char
	while ((next_char = line[cur++]))
	{
#ifdef DEBUG
			printf ("Next char \'%c\'\n", next_char);
#endif

		if (!is_whitespace(next_char))
		{
			// Place after the last non-whitespace character seen
			trim_point = cur;
		}
	}

#ifdef DEBUG
		printf ("Line is %s, trim point is %d, cur is %d line[cur-2] is %x\n", line, trim_point, cur, line[cur-2]);
#endif

	// Place lineending:
	if (line[cur-2] == '\n')
	{
		line[trim_point++] = '\n';
	}

	line[trim_point++] = '\0';
	
	// Trim point is n
	return trim_point;
}

int is_whitespace(char check)
{
	switch(check)
	{
		case '\n':
		case '\t':
		case '\r':
		case ' ':
			return 1;
		default:
			return 0;
	}
}
