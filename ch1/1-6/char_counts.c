/* Exercise 1-14 */
/* Write a program to print a histogram of the frequencies of different characters in its input
 */

#include <stdio.h>
#include <stdint.h>

int main()
{
	unsigned int char_counts[256] = {0};
	unsigned int invalid_count = 0;

	uint8_t c = 0;

	unsigned int num_chars = 0;

	// Accumulate data:
	while (((int8_t)(c =  getchar()))!= EOF)
	{
		if (c >= 128)
		{
			invalid_count++;
		}
		else
		{
			char_counts[c]++;
		}
		
		num_chars++;
	}

	// Normalize for viewing:
	unsigned int char_count_max = 0;
	

	for (uint8_t i = 0; i < 128; ++i)
	{
		if (char_counts[i] > char_count_max)
		{
			char_count_max = char_counts[i];
		}
	}

	unsigned int scale_factor;

	if (char_count_max > 80)
	{
		scale_factor = char_count_max / 80;
	}
	else
	{
		scale_factor = 1;
	}

	// Print header:
	printf("Character: | Count:\n");
	
	// Print each row:
	for (unsigned char i = 0; i < 128; ++i)
	{
		// Print only reasonable values:
		if (char_counts[i] != 0)
		{
			// Print left bar
			switch(i)
			{
				case '\0':
					printf("\\0");
					break;
				case '\a':
					printf("\\a");
					break;
				case '\b':
					printf("\\b");
					break;
				case '\t':
					printf("\\t");
					break;
				case '\f':
					printf("\\f");
					break;
				case '\n':
					printf("\\n");
					break;
				case '\r':
					printf("dataaa\\r");
					break;
				default:
					printf("%c ", (char) i);
			}

			// Pipe:
			printf("         |");
			
			// Find number of dots:
			unsigned int dots_to_print = 0;

			if (char_counts[i] / scale_factor == 0)
			{
				dots_to_print = 1;
			}
			else
			{
				dots_to_print = char_counts[i] / scale_factor;
			}

			for (unsigned int j = 0; j < dots_to_print; ++j)
			{
				printf("*");
			}

			printf("\n");
		}

	}
	printf ("invalid characters: %d\n", invalid_count);

	return 0;
}

