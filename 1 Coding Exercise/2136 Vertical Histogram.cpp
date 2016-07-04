#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	char input[73];
	int counts[26] = {0}, max_count = 0;

	for (int i=0; i < 4; i++)
	{
		fgets(input, 73, stdin);

		for (int j=0; input[j] != '\0'; j++)
			if (input[j] >= 'A' && input[j] <= 'Z')
			{
				counts[input[j] - 'A'] += 1;

				if (counts[input[j] - 'A'] > max_count)
					max_count = counts[input[j] - 'A'];
			}
	}

	for (int i=max_count; i > 0; i--)
	{
		for (int j=0; j < 26; j++)
			if (counts[j] >= i)
				printf("* ");
			else
				printf("  ");

		printf("\n");
	}

	for (int i=0; i < 26; i++)
		printf("%c ", 'A' + i);

	return 0;
}
