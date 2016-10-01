/*  Exercise 1-13 */
/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging
 */
#include <stdio.h>

#define MAX_WORD_LENGTH 55 
#define MAX_HIST_WIDTH 80
#define MAX_HIST_HEIGHT 60
#define HIST_VERTICAL 1

int main ()
{
	unsigned int word_counts[MAX_WORD_LENGTH] = {0};
	unsigned int cur_word_length = 0;

	char c = 0;

	// Accumulate results:
	while ((c = getchar()) != EOF)
	{
		if (((c > 'a') && (c < 'z')) || 
			((c > 'A') && (c < 'z')))
		{
			cur_word_length++;
		}
		else
		{
			if (cur_word_length > 0)
			{
				if (cur_word_length > MAX_WORD_LENGTH)
				{
					word_counts[MAX_WORD_LENGTH-1]++;
				}
				else
				{
					word_counts[cur_word_length-1]++;
				}
				
				cur_word_length = 0;
			}
		}
	}

	// Get scaling factor for max width = 80:
	unsigned int max_word_count = 0;
	unsigned int largest_word;
	for (unsigned int i = 0; i < MAX_WORD_LENGTH; ++i)
	{
		if (word_counts[i] > max_word_count)
		{
			max_word_count = word_counts[i];
		}

		if (word_counts[i] != 0)
		{
			largest_word = i+1;
		}
	}

	unsigned int scale_factor;
#if HIST_VERTICAL
	if (max_word_count > MAX_HIST_HEIGHT)
	{
		scale_factor = max_word_count / MAX_HIST_HEIGHT;
	}
#else
	if (max_word_count > MAX_HIST_WIDTH)
	{
		scale_factor = max_word_count / MAX_HIST_WIDTH;
	}
#endif
	else 
	{
		scale_factor = 1;
	}

	printf ("scale factor is %d\n", scale_factor);
	
#if HIST_VERTICAL
	// Highest *s:
	unsigned int max_dots = max_word_count/scale_factor;
	for (unsigned int dot_number = max_dots; dot_number > 0; --dot_number)
	{
		//Print Left axis:
		if (dot_number % 10 == 0)
		{
			printf ("%d Words\t|", dot_number);
		}
		else
		{
			printf ("\t\t|");
		}

		for (unsigned int word_size = 0; word_size < largest_word; ++word_size)
		{
			// We do this in too many places:
			unsigned int dots_to_print = 0;
			if (word_counts[word_size] == 0)
			{
				dots_to_print = 0;
			}
			else if (word_counts[word_size]/scale_factor == 0)
			{
				dots_to_print = 1;
			}
			else
			{
				dots_to_print = word_counts[word_size]/scale_factor;
			}

			if (dot_number <= dots_to_print)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
#else
	// Print Header:
	printf("Word Size:\t| Count:\n");
	// A line for every word size:
	for (unsigned int i = 0; i < largest_word; ++i)
	{
		// Print Left Axis bar:
		printf("%d Letters: \t|", i+1);
		
		unsigned int dots_to_print = 0;
		// Determine how many *s to print:
		if (word_counts[i] == 0)
		{
			dots_to_print = 0;
		}
		else if (word_counts[i]/scale_factor == 0)
		{
			dots_to_print = 1;
		}
		else
		{
			dots_to_print = word_counts[i]/scale_factor;
		}

		for (unsigned int j = 0; j < dots_to_print; j++)
		{
			printf("*");
		}

		printf("\n");
	}
#endif

	return 0;
	
}
