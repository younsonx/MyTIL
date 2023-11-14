#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char row_no;
	int seat_no, pin;
	char book;
	struct node* next, * prev;
}node;

node *hn = NULL;

void create()
{
	node* nn, * cn;
	int j = 1;
	int k = 2;
	char c = 'A';

	do
	{
		int i = 1;
		do
		{
			k = (k * k) / 10 + 100 - k / 2;
			nn = (struct node*)malloc(sizeof(node));
			nn->next = nn->prev = NULL;
			nn->row_no = c;
			nn->seat_no = i;
			nn->pin = k;
			nn->book = 'a';
			if (hn == NULL)
			{
				hn = nn;
				nn->next = nn->prev = hn;
			}
			else
			{
				cn = hn;

				while (cn->next != hn)
					cn = cn->next;

				cn->next = nn;
				nn->prev = cn;
				nn->next = hn;
				hn->prev = nn;
			}
			i++;
		} while (i <= 7);
		j++;
		c++;
	} while (j <= 10);
}

void display()
{
	node* cn;
	cn = hn;
	printf("------------------------------------------------------------------\n");
	printf("|                            Platinum                            |\n");
	while (cn->next != hn)
	{
		if ((cn->prev)->row_no != cn->row_no)
			printf("| ");
		printf("%c ", cn->row_no);
		printf("%d ", cn->seat_no);
		if (cn->book == 'a')
			printf("\033[32;40m -> a  \033[0m");  // green text with black background
		else
			printf("\033[1;31;43m -> b  \033[0m");  // red text
		if ((cn->next)->row_no != cn->row_no)
			printf("|\n");
		if (cn->row_no == 'C' && cn->seat_no == 7)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("|                             gold                               |\n");
		}
		if (cn->row_no == 'H' && cn->seat_no == 7)
		{
			printf("----------------------------------------------------------------------\n");
			printf("|                            Silver                              |\n");
		}
		cn = cn->next;
	}
	printf("%c", cn->row_no);
	printf("%d", cn->seat_no);
	if (cn->book == 'a')
		printf("\033[32;40m -> a  \033[0m");
	else
		printf("\033[1;31;43m -> b  \033[0m");
	printf("|\n");

	printf("------------------------------------------------------------------\n\n");
	printf("\033[1;33;49mPLATINUM-> 150              GOLD-> 100                  SILVER->60\033[0m\n");
}

void display1(node *tmp[20], int n)
{
	if (n != 1)
	{
		printf("------------------------------------------------------------------\n");
		printf("THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n");
		for (int i = 1; i < n; i++)
		{
			printf("%c %d ", tmp[i]->row_no, tmp[i]->seat_no);
			printf("   PIN : %d \n", tmp[i]->pin);
		}
		printf("!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n");
		printf("PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n");
		printf("------------------------------------------------------------------\n");
	}
}

void book_seat()
{
	node* cn, * temp[20];
	int n, z, flag;
	char row;
	int seat;
	int ch1;
	do
	{
		z = 1;
		printf("\nEnter No Of Tickets u Want To Buy: ");
		scanf("%d", &n);

		printf("\nEnter Seat Numbers: \n");

		for (int i = 1; i <= n; i++)
		{
			printf("NO ");
			printf("%d", i);
			printf(" = ");
			scanf(" %c", &row);
			scanf("%d", &seat);
			cn = hn;
			while (cn->next != hn)
			{
				if (cn->row_no == row && cn->seat_no == seat)
				{
					if (cn->book == 'a')
					{
						cn->book = 'b';
						temp[z] = cn;
						z++;
					}
					else
					{
						printf("INVALID CHOISE!\n");
						printf("%c", cn->row_no);
						printf("%d", cn->seat_no);
						printf(" Seat is alredy reserved \n");

					}
				}
				cn = cn->next;
			}
			if (cn->row_no == row && cn->seat_no == seat)
			{
				if (cn->book == 'a')
				{
					cn->book = 'b';
					temp[z] = cn;
					z++;
				}
				else
				{
					printf("INVALID CHOISE!\n");
					printf("%c", cn->row_no);
					printf("%d", cn->seat_no);
					printf(" Seat is alredy reserved\n");
				}
			}
		}
		display1(temp, z);
		printf("\n\nPRESS 1 To check Seat Status\n");
		printf("PRESS 2 To book other seat\n");
		printf("PRESS 3 To Exit BOOKING PORTAL\n");
		printf("\ninput: ");
		char temp;
		// scanf("%c",&temp);
		scanf("%d", &ch1);
		if (ch1 == 1);
		// display();
	} while (ch1 == 2);
}

int main()
{
	int ch;
	int c = 0;
	printf("\n\n\n");
	printf("                 WELCOME TO MOVIE TICKET BOOKING \n");
	printf("                         ONLINE  \n\n");
	create();
	display();

	do
	{
		printf("\n\n\n");
		printf("PRESS 1-> BOOK TICKETS\n");
		printf("\ninput: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			book_seat();
			display();
			break;
		}
	}
	while (c != 2);
	printf("\n\n\n");
	return 0;
}
