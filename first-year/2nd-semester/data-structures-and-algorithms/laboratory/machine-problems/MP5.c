/**
 * @file DDP-MP4.C
 * @author Dana Justine D. Pacatang
 * @brief Operations of double/doubly-linked list
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
    struct Node *prev, *next;
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
        case 3: // addAfterGivenNode()
            printf("Press any key to continue...\n");
			getch();
            system("cls");
            break;
        case 4: // delBeforeNode()
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
    char temp, courseYear[10];
	float ave = 0;

    // Student number
    printf("Student Number: ");
    scanf(" %[^\n]%*c", (*newNode)->studNo);
	fflush(stdin);

    // Student name
    printf("Student Name: ");
    scanf(" %[^\n]%*c", (*newNode)->studName);
	fflush(stdin);

    // Course and year
    printf("Course and Year: ");
    scanf(" %[^\n]%*c", (*newNode)->crsYr);
	fflush(stdin);

    // GWA
    printf("GWA: ");
    scanf("%f", &ave);
	fflush(stdin);
	(*newNode)->GWA = ave;
}

// Function to create a linked list

void createList(Node** HEAD, Node** TAIL)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
	char resp, temp;
	int option = 1, ctr = 1;

    *HEAD = newNode;
    *TAIL = newNode;
    (*HEAD)->prev = NULL;
    (*HEAD)->next = NULL;
	
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
            newNode->next->prev = newNode;
            newNode = newNode->next;
            *TAIL = newNode;
        }
   	}
	while(toupper(resp) == 'Y');

    (*TAIL)->next = NULL;
    newNode = NULL; // Disconnects NewNode pointer

    endMessage(option, ctr);
}

// Function to traverse and display the list

void displayList(Node** HEAD)
{
    Node* travNode = *HEAD;
	int option = 2, ctr = 1;
	float ave = 0;

	// If list is empty
	if (travNode == NULL)
		printf("There are no records. Enter option 1 to create a record.\n");
	// If list is not empty
	else
		do
		{
			printf("Student Record No. %d\n", ctr);
            printf("Student Number: %s\n", travNode->studNo);
	 		printf("Student Name: %s\n", travNode->studName);
            printf("Course and Year: %s\n", travNode->crsYr);
			ave = travNode->GWA;
            printf("GWA: %0.2f\n\n", ave);
			travNode = travNode->next;
			ctr++;
		}
		while (travNode != NULL);

    endMessage(option, 0);
}

// Function to add a new node after a value

void addAfterGivenNode(Node** HEAD, Node** TAIL)
{
	char afterVal[12];
    Node* current = *HEAD;
	Node* newNode = (Node*)malloc(sizeof(Node));
	int option = 3, flag = 0;

	enterInfo(&newNode);

	newNode->prev = NULL;
	newNode->next = NULL;

	printf("\nEnter student number where student %s will be inserted after: ", newNode->studNo);
    scanf("%s", &afterVal);

	// If list is empty
	if (current == NULL)
		printf("\nInsertion failed because there are no records. Enter option 1 to create a record.\n");
	// if list is not empty
	else
	{
		// Finding afterVal
		while(flag == 0 && current != NULL)
		{
			if (strcmp(current->studNo, afterVal) == 0)
				flag = 1;
			else
				current = current->next;
		}
		// If afterVal does not exist in the list
		if (flag == 0)
			printf("\nInsertion failed because %s is not in any record.\n", afterVal);
		// Adding after given a node
		else
		{
			// If afterVal is at the tail
			if (current == *TAIL)
			{
				newNode->prev = *TAIL;
				(*TAIL)->next = newNode;
				*TAIL = newNode;
				printf("\n%s added after %s. Enter option 2 to view record.\n", newNode->studNo, afterVal);
			}
			// If afterVal is not at the tail
			else
			{
				newNode->next = current->next;
				newNode->prev = current;
				current->next = newNode;
				current->next->prev = newNode;
				printf("\n%s added after %s. Enter option 2 to view record.\n", newNode->studNo, afterVal);
			}
			current = newNode = NULL;
		}

	endMessage(option, 0);
	}
}

// Function to delete a node before a value

void delBeforeNode(Node** HEAD)
{
	Node *current = *HEAD, *previous = *HEAD;
	char deleteVal[12];
    int option = 4;

	printf("\nEnter student number to delete student before it: ");
    scanf("%s", &deleteVal);

	// If list is empty
	if (current == NULL)
		printf("\nDeletion failed because there are no records. Enter option 1 to create a record.\n");
	// If list only has one node
	else if (current->next == NULL)
	{
		printf("\nDeletion failed because there is only one record.\n");
	}
	else
	{
		// Finding deleteVal
        while (strcmp(deleteVal, current->studNo) != 0)
		{
			current = current->next;
			// If deleteVal is not in the list
			if (current == NULL)
			{
				printf("\nDeletion failed because %s is not in any record.\n", deleteVal);
				printf("Press any key to continue...\n");
				getch();
				system("cls");
				return;
			}
		}
		// If deleteVal is the second node
        if (current == (*HEAD)->next)
		{
            *HEAD = current;
			previous->next = NULL;
			current->prev = NULL;
            free(previous);
			previous = NULL;
			current = NULL;
			printf("\nRecord before %s has been deleted.\n", deleteVal);
        }
        // If deleteVal is the first node
        else if (current == *HEAD)
		{
            printf("\nDeletion failed because there are no records before %s to delete.\n", deleteVal);
        }
        // If deleteVal is not the first nor second node
        else
		{
            previous = current->prev;
			previous->prev->next = current;
			current->prev = previous->prev;
			previous->prev = NULL;
			previous->next = NULL;
            free(previous);
			previous = NULL;
			current = NULL;
			printf("\nRecord before %s has been deleted.\n", deleteVal);
        }
	}

    endMessage(option, 0);
}

// Main function

int main()
{
	// Variables

	int option = 0;
	int isChoosing = 1;
	Node* HEAD = NULL;
    Node* TAIL = NULL;
	
	// Options

	const char* options[] = {"", "\nCREATING A STUDENT RECORD",
            "\nDisplaying student record...\n", 
			"\nADDING A RECORD AFTER ANOTHER RECORD\n", 
            "\nDELETING RECORD BEFORE A GIVEN A STUDENT NUMBER",
        };
	
	// Menu

	while (isChoosing == 1)
    {
		system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a student record\n");
		printf("2: Display student records\n");
		printf("3: Add a record after a given student number\n");
		printf("4: Delete a record before a given student number\n");
		printf("0: EXIT\n");

		printf("\nEnter your option: ");
        scanf("%d", &option);
		
		switch(option)
        {
			case 1:
				printf("%s\n", options[option]);
				createList(&HEAD, &TAIL);
				option = 0;
				break;
			case 2:
				printf("%s\n", options[option]);
				displayList(&HEAD);
				option = 0;
				break;
			case 3:
				printf("%s\n", options[option]);
				addAfterGivenNode(&HEAD, &TAIL);
				option = 0;
				break;
			case 4:
				printf("%s\n", options[option]);
				delBeforeNode(&HEAD);
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
