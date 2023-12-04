#include <stdio.h>
#include <stdlib.h>

typedef struct mych
{
	char ch;
	int pos;
} mych;

int main()
{
	int k, jul, met;
	mych rain[118];

	for (met = 0; met < 118; met++)
	{
		rain[met].pos = rand() % 26 - 26;
		rain[met].ch = rand() % 25 + 65;
	}

	for (k = 0; k < 200; k++)
	{
		system("cls");
		for (met = 0; met < 118; met++)
		{
			if (rain[met].pos < 26) rain[met].pos++;
			else rain[met].pos = -1;
		}

		for (jul = 0; jul < 26; jul++)
		{
			for (met = 0; met < 118; met++)
			{
				if (rain[met].pos == jul) printf("%c", rain[met].ch);
				else printf(" ");
			}
			printf("\n");
		}
		
	}

	return 0;
}
