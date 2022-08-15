/**
 * @file DDP-MP4.C
 * @author Dana Justine D. Pacatang
 * @brief Operations of single/singly-linked list
 * @date 2022-06-18
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure

typedef struct Node
{
    char studNo[12];
    char studName[24];
    char crsYr[10];
    float GWA;
    struct Node *next;
} Node;

// Function to display the end message every menu option

void endMessage(int option, int ctr)
{
    switch(option)
    {
        case 1: // createList()
            if (ctr == 1)
                printf("\n%d record created. Enter option 2 to view records.\n", ctr);
            else
                printf("\n%d records created. Enter option 2 to view records.\n", ctr);
            
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            break;
        case 2: // displayList()
            printf("Record displayed.\n");
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            break;
        case 3: // addTail()
            printf("\nRecord added at the end. Enter option 2 to view record.\n");
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            break;
        case 4: // delNode()
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            break;
        case 0: // Exit program
            printf("\nExiting...\nPress any key to continue...");
			getch();
            break;
        case -1: // Case default in main
            printf("\nInput is not among the given options.\n");
			printf("Press any key to continue....");
            break;
    }
}

// Function to enter information

void enterInfo(Node** newNode)
{
	char temp;

    // Student number
    printf("Student Number: ");
    scanf("%s", &(*newNode)->studNo);
    fflush(stdin);

    // Student name
    printf("Student Name: ");
    gets((*newNode)->studName);
	fflush(stdin);

    // Course and year
    printf("Course and Year: ");
    gets((*newNode)->crsYr);
	fflush(stdin);

    // GWA
    printf("GWA: ");
    scanf("%f", &(*newNode)->GWA);
    fflush(stdin);
}

// Function to create a linked list

Node* createList(Node* START)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
	char resp, temp;
	int option = 1, ctr = 1;

	START = newNode;
	
	do
	{
    	printf("\nStudent Record No. %d\n", ctr);

        enterInfo(&newNode);

        // Add another record
    	printf("\nAdd another record [Y/N]? ");
    	scanf("%c", &resp);
    	if (toupper(resp) == 'Y')
       	{
			ctr++;
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
        }
   	}
	while(toupper(resp) == 'Y');

   	newNode->next = NULL; // Signifies end of list
   	newNode = NULL; // Disconnects newNode pointer

    endMessage(option, ctr);

	return START;
}

// Function to traverse and display the list

void displayList(Node* START)
{
    Node* current = START;
	int option = 2, ctr = 1;

    // Traverses the list while printing data
   	if (current == NULL)
		printf("There are no records. Enter option 1 to create a record.\n\n");
   	else
     	do
        {
	 		printf("Student Record No. %d\n", ctr);
            printf("Student Number: %s\n", current->studNo);
	 		printf("Student Name: %s\n", current->studName);
            printf("Course and Year: %s\n", current->crsYr);
            printf("GWA: %0.2f\n\n", current->GWA);
	 		current = current->next;
	 		ctr++;
     	}
        while (current != NULL);
    
	// Disconnects current pointer
    current = NULL;

    endMessage(option, 0);
}

// Function to add a new node at the tail

Node* addTail(Node* START)
{
    Node* END = START;
	Node* newNode = (Node*)malloc(sizeof(Node));
    char temp;
    int option = 3;

	enterInfo(&newNode);

	newNode->next = NULL;

	// If list is empty
	if (START == NULL)
	{
		START = newNode;
	}
	// if list is not empty
	else
	{
		// Finding the end of the list
		while (END->next != NULL)
		{
	    	END = END->next;
		}
	
		// Attaching newNode at the end
		END->next = newNode;
		newNode = NULL;
		END = NULL;
	}

    endMessage(option, 0);
	
	return START;
}

// Function to delete a node by value

Node* delNode(Node* START)
{
    Node* previous = NULL;
	Node* delNode = START;
	int option = 4, flag = 0;
    char deleteVal[12];

	printf("\nEnter student number of student to be deleted: ");
    scanf("%s", &deleteVal);
	
	// If list is empty
	if (START == NULL)
	{
		printf("\nDeletion failed because there are no records. Enter option 1 to create a record.\n");
	}
	// If list is not empty
	else
	{
		// Finding deleteVal
		while (flag != 1 && delNode != NULL)
		{
			if (strcmp(deleteVal, delNode->studNo) == 0)
				flag = 1;
			else
			{
				previous = delNode;
				delNode = delNode->next;
			}
		}
		if (flag == 0)
			printf("\nDeletion failed because %s is not in any record.\n", deleteVal);
		else
		{
			// Deleting node by value
			if (delNode == START)
			{
				START = START->next;
				delNode->next = NULL;
			}
			else 
			{
				previous->next = delNode->next;
				delNode->next = NULL;
			}
			free(delNode);
            previous = delNode = NULL;
		    printf("\nStudent %s has been deleted.\n", deleteVal);
		}
	}

    endMessage(option, 0);

	return START;
}

// Main function

int main()
{
	// Variables

	int option = 0, isChoosing = 1;
	Node* START = NULL;
	
	// Options

	const char* options[] = {"", "\nCREATING A STUDENT RECORD",
            "\nDisplaying student record...\n", 
            "\nADDING A RECORD AT THE END",
            "\nDELETING STUDENT RECORD",
        };
	
	// Menu

	while (isChoosing == 1)
    {
		system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a student record\n");
		printf("2: Display student records\n");
		printf("3: Add a record at the end\n");
		printf("4: Delete a student record\n");
		printf("0: EXIT\n");

		printf("\nEnter your option: ");
        scanf("%d", &option);
		
		switch(option)
        {
			case 1:
				printf("%s\n", options[option]);
				START = createList(START);
				option = 0;
				break;
			case 2:
				printf("%s\n", options[option]);
				displayList(START);
				option = 0;
				break;
			case 3:
				printf("%s\n", options[option]);
				START = addTail(START);
				option = 0;
				break;
			case 4:
				printf("%s\n", options[option]);
				START = delNode(START);
				option = 0;
				break;
			case 0:
				isChoosing = 0;
                endMessage(0, 0);
				break;
			default:
                endMessage(-1, 0);
				option = 0;
				getch();
				system("cls");
				break;
		}
	}
	return 0;
}
