/*
 * Exercise 1-19
 * Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input one line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

void reverse(char s[]); /* reverse string in place */
int getline(char s[], int limit); /* read line into array, up to max.  Return length */

/* Reverse each input line */
int main()
{
	char line[MAXLINE]; /* current input line */
	while (getline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
}

int getline(char s[], int limit)
{
	int c, i;

	for (
		i = 0;
		i < limit - 1 &&
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

void reverse(char s[])
{
	// find end
	int end = 0;
	
	while (s[end])
	{
		end++;
	}

	// we don't care about the terminator:
	end--;

	int start = 0;
	char temp;

	while (start < end)
	{
		temp = s[end];
		s[end] = s[start];
		s[start] = temp;
		start++;
		end--;
	}

}
