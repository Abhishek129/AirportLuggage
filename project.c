//Luggage managemnet system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct baggage
{
	char Name[50];
	char bagType[50];
	int bagWeight;
	struct baggage *next;
};

struct baggage *head;

void insert()
{
	int flag = 0;
	struct baggage *new;
	struct baggage *temp;
	new = (struct baggage *)malloc(sizeof(struct baggage));
	printf("ENTER LUGGAGE DETAILS: \n\n");
	printf("Enter Your Name: \n");
	getchar();
	gets(new->Name);
	do
	{
		printf("\n--------------------------------------------------------\n\tNOTE: SMALL=8kg, MEDIUM=19kg, LARGE=31kg\n--------------------------------------------------------\n");
		printf("\nEnter Bag Type (Large,Medium,Small): \n");
        // getchar();
		gets(new->bagType);

		if (strcmp(new->bagType, "Small") == 0 || strcmp(new->bagType, "Medium") == 0 || strcmp(new->bagType, "Large") == 0)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}

	} while (flag == 0);

    //small
	if (strcmp(new->bagType, "Small") == 0)
	{
		do
		{
			printf("\nEnter Bag Weight in 1 to 8 kg: \n");
			scanf("%d", &new->bagWeight);

		} while (new->bagWeight > 8 || new->bagWeight <= 0);
		printf("\n%s\nYour Luggage Has Succesfully Checked In\n\n", new->Name);
	}

    //medium1
	else if (strcmp(new->bagType, "Medium") == 0)
	{
		do
		{
			printf("\nEnter Bag Weight in 1 to 19 kg: \n");
			scanf("%d", &new->bagWeight);

		} while (new->bagWeight > 19 || new->bagWeight <= 0);
		printf("\n%s\nYour Luggage Has Succesfully Checked In\n\n", new->Name);
	}
    //large
	else if (strcmp(new->bagType, "Large") == 0)
	{
		do
		{
			printf("\nEnter Bag Weight in 1 to 31 kg: \n");
			scanf("%d", &new->bagWeight);

		} while (new->bagWeight > 31 || new->bagWeight <= 0);
		printf("\n%s\nYour Luggage Has Succesfully Checked In\n\n", new->Name);
	}

	new->next = NULL;
	temp = head;
	if (head == NULL)
	{
		head = new;
		new->next = head;
	}
	else
	{
		temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = head;
	}
}

void display()
{
	struct baggage *temp;
	temp = head;

	if (temp == NULL)
	{
		printf("No Luggage Available\n");
	}
	else
	{
		int counter = 1;
		printf("\n---------------------------------------------------------------------\n\tLuggage Will Arrive In The Below Displayed Order\n---------------------------------------------------------------------\n\n");
		while (temp->next != head)
		{
			printf("%d: \nLuggage Holder Name: %s\n", counter, temp->Name);
			printf("Luggage Type: %s\n", temp->bagType);
			printf("Luggage Weight: %dkg\n\n", temp->bagWeight);
			temp = temp->next;
			counter++;
		}
		printf("%d: \nLuggage Holder Name: %s\n", counter, temp->Name);
		printf("Luggage Type: %s\n", temp->bagType);
		printf("Luggage Weight: %dkg\n\n", temp->bagWeight);
		counter++;
	}
}

void manage()
{
	struct baggage *temp;
	char ch;

	do
	{
		if (head == NULL)
			printf("No Luggage Available\n");
		else if (head->next == head)
		{
			printf("\nLuggage of %s is arrived\n", head->Name);
			printf("Is it Yours (y/n)?\n\n");
			getchar();
			scanf("%c", &ch);

			if (ch == 'y' || ch == 'Y')
			{
				printf("Luggage of %s is taken\n", head->Name);
				printf("%s\nYour Luggage Has Succesfully Checked Out\n\n", head->Name);
				head = NULL;
			}
			else if (ch == 'n' || ch == 'N')
			{
				printf("Luggage of %s is skipped\n", head->Name);
				printf("If You Think Your Luggage Is Skipped, Then Wait Until It Arrives Again\n\n");
				temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = head;
				head = head->next;
			}
		}
		else
		{
			printf("\nLuggage of %s is arrived\n", head->Name);
			printf("Is it Yours (y/n)?\n\n");
			getchar();
			scanf("%c", &ch);

			if (ch == 'y' || ch == 'Y')
			{
				printf("Luggage of %s is taken\n", head->Name);
				printf("%s\nYour Luggage Has Succesfully Checked Out\n\n", head->Name);
				temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = head->next;
				head = temp->next;
			}
			else if (ch == 'n' || ch == 'N')
			{
				printf("Luggage of %s is skipped\n", head->Name);
				printf("If You Think Your Luggage Is Skipped, Then Wait Until It Arrives Again\n\n");
				printf("\n----------------------------------------\n\tLuggage Arriving Status\n----------------------------------------\n");
				temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = head;
				head = head->next;
			}
		}
		display();
	} while (head != NULL);
}

int main()
{
	int choice = 0;
	while (1)
	{
		printf("--------------------------------------\n\tEnter choice from below\n--------------------------------------\n");
		printf("(1) For Checking in Luggage Details\n");
		printf("(2) For Checking Your Arriving Luggage Order\n");
		printf("(3) For Reclaiming Luggage From The Receiving Site\n");
		printf("(4) For Exit\n");

		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			insert();
			break;

			case 2:
			display();
			break;

			case 3:
			manage();
			break;

			case 4:
			exit(0);

			default:
			printf("Invalid Option\n");
		}
	}	
	return 0;
}