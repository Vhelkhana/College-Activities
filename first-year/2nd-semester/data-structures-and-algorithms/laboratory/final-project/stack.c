/**
 * Operations of stack
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure

typedef struct node
{
    int data;
    struct node *next;
} node;

 // Function to create a stack

void createStack(node** TOP)
{
    node* PushNode = (node*)malloc(sizeof(node*));
    PushNode->next = NULL;
    *TOP = PushNode;
    char Resp, Temp;
    int Ctr = 1;

    do
    {
        printf("\nNode no. %d\n", Ctr);
    	printf("Enter data => ");
    	scanf("%d", &PushNode->data);
    	scanf("%c", &Temp); /* Used when there is scanf() or gets() prior to reading a 
                                character */
    	printf("\nAdd another node [Y/N]? ");
    	scanf("%c", &Resp);

        if (toupper(Resp) == 'Y')
        {
            Ctr++;
            PushNode = (node*)malloc(sizeof(node*));
            PushNode->next = *TOP;
            *TOP = PushNode;
        }
    }
    while (toupper(Resp) == 'Y');
    PushNode = NULL;

    printf("\nStack created. Enter option 2 to view the stack.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to display stack

void displayStack(node** TOP)
{
    node* PopNode = *TOP;
    node* TempTOP = NULL;
    int Ctr = 1;

    // If stack is empty
    if (PopNode == NULL)
        printf("The stack is empty. Enter option 1 to create a stack.\n");
    // If stack is not empty
    else
    {
        do
        {
            printf("Node %d Content:\n", Ctr);
			printf("\tData => %d\n", (*TOP)->data);
			*TOP = (*TOP)->next;
            PopNode->next = NULL;

            // PUSH PopNode to TempTOP
            if (TempTOP == NULL)
                TempTOP = PopNode;
            else
            {
                PopNode->next = TempTOP;
                TempTOP = PopNode;
            }

            PopNode = *TOP;
            Ctr++;
        }
        while (*TOP != NULL);
        
        // PUSH TempTOP to *TOP
        do
        {
            PopNode = TempTOP;
            TempTOP = TempTOP->next;
            PopNode->next = NULL;
            if (*TOP == NULL)
                *TOP = PopNode;
            else
            {
                PopNode->next = *TOP;
                *TOP = PopNode;
            }
            PopNode = TempTOP;
        }
        while (TempTOP != NULL);
    }

    printf("\nStack displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node in stack

void push(node** TOP)
{
    node* PushNode = (node*)malloc(sizeof(node*));

    printf("\nEnter data => ");
    scanf("%d", &PushNode->data);
    PushNode->next = NULL;

    // If stack is empty
    if (*TOP == NULL)
        *TOP = PushNode;
    // If stack is not empty
    else
    {
        PushNode->next = *TOP;
        *TOP = PushNode;
    }
    PushNode = NULL;

    printf("\n%d added. Enter option 2 to view the stack.\n", (*TOP)->data);
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node in stack

void pop(node** TOP)
{
    node* PopNode = *TOP;
    // If stack is empty
    if (PopNode == NULL)
        printf("\nDeletion failed because the stack is empty. Enter option 1 to create a stack.\n");
    // If stack is not empty
    else
    {
        *TOP = (*TOP)->next;
        PopNode->next = NULL;
        free(PopNode);
        PopNode = NULL;
        printf("\nTop node deleted. Enter option 2 to view the stack.\n");
    }
    
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete the entire stack

void delStack(node** TOP)
{
    // If stack is empty
    if (*TOP == NULL)
		printf("\nDeletion failed because the stack is already empty. Enter option 1 to create a stack.\n");
	// If stack is not empty
    else
	{
		free(*TOP);
		*TOP = NULL;
		printf("\nEntire stack has been deleted. Enter option 2 to view the stack.\n");
	}
	
	printf("Press any key to continue...");
	getch();
	system("cls");
}

// Main function

int main()
{
	// Variables

	int option = 0;
	int isChoosing = 1;
	node* TOP = NULL;
	
	// Action status string

	const char* options[] = {"", "\nCREATING A STACK",
            "\nDISPLAYING STACK\n", 
			"\nADDING A NODE", 
            "\nDeleting node...",
            "\nDeleting the entire stack...",
            // "SORT THE STACK",
        };
	
	// Menu loop

	while (isChoosing == 1)
    {
		// system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a stack\n");
		printf("2: Display stack\n");
		printf("3: Add a node\n");
		printf("4: Delete a node\n");
		printf("5: Delete the entire stack\n");
		printf("0: EXIT\n");

		printf("\nEnter your option: ");
        scanf("%d", &option);
		
		switch(option)
        {
			case 1:
				printf("%s\n", options[option]);
				createStack(&TOP);
				option = 0;
				break;
			case 2:
				printf("%s\n", options[option]);
				displayStack(&TOP);
				option = 0;
				break;
			case 3:
				printf("%s\n", options[option]);
				push(&TOP);
				option = 0;
				break;
			case 4:
				printf("%s\n", options[option]);
				pop(&TOP);
				option = 0;
				break;
			case 5:
				printf("%s\n", options[option]);
				delStack(&TOP);
				option = 0;
				break;
			case 0:
				isChoosing = 0;
				printf("\nExiting...\nPress any key to continue...");
				getch();
				break;
			default:
				printf("\nInput is not among the given options.\n");
				printf("Press any key to continue....");
				option = 0;
				getch();
				system("cls");
				break;
		}
	}
	return 0;
}
