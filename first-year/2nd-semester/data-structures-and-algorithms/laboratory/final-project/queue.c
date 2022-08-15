/**
 * Operations of queue
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>

// Node structure

typedef struct node
{
    int data;
    struct node *next;
} node;

 // Function to create a queue

void createQueue(node** FRONT, node** REAR)
{
    node* NewNode = (node*)malloc(sizeof(node*));
    char Resp, Temp;
    int Ctr = 1;
    
    NewNode->next = NULL;
    *FRONT = *REAR = NewNode;
    do
    {
        printf("\nNode no. %d\n", Ctr);
    	printf("Enter data => ");
    	scanf("%d", &NewNode->data);
    	scanf("%c", &Temp); /* Used when there is scanf() or gets() prior to reading a 
                                character */
    	printf("\nAdd another node [Y/N]? ");
    	scanf("%c", &Resp);
        if (toupper(Resp) == 'Y')
        {
            Ctr++;
            NewNode->next  = (node*)malloc(sizeof(node*));
            *REAR = NewNode->next;
            NewNode = NewNode->next;
        }
    }
    while (toupper(Resp) == 'Y');
    (*REAR)->next = NULL;
    NewNode = NULL;

    printf("\nQueue created. Enter option 2 or 3 to view the queue.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to display queue with repeating data

void displayRepeat(node** FRONT, node** REAR)
{
    node* TravNode = *FRONT;
    node* TFRONT = NULL;
    node* TREAR = NULL;
    int Ctr = 1;

    // If queue is empty
    if (TravNode == NULL)
        printf("The queue is empty. Enter option 1 to create a queue.\n");
    // If queue is not empty
    else
    {
        do
        {
            printf("Node %d Content:\n", Ctr);
			printf("\tData => %d\n", TravNode->data);
            *FRONT = TravNode->next;
            if (*FRONT == NULL)
                *REAR = NULL;
            TravNode->next = NULL;
            
            // Add TravNode to TempQueue
            if (TFRONT == NULL && TREAR == NULL)
            {
                TFRONT = TREAR = TravNode;
            }
            else
            {
                TREAR->next = TravNode;
                TREAR = TREAR->next;
            }
            
            TravNode = *FRONT;
            Ctr++;
        }
        while (*FRONT != NULL);

        // Transfer TempQueue to Queue
        do
        {
            TravNode = TFRONT;
            TFRONT = TravNode->next;
            if (TFRONT == NULL)
                TREAR = NULL;
            TravNode->next = NULL;
            if (*FRONT == NULL && *REAR == NULL)
                *FRONT = *REAR = TravNode;
            else
            {
                (*REAR)->next = TravNode;
                *REAR = (*REAR)->next;
            }
        }
        while (TFRONT != NULL);
    }

    TravNode = NULL;

    printf("\nQueue displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function that stops displaying queue if a node with same value as front is reached

void displayNoRepeat(node** FRONT, node** REAR)
{
    node* TravNode = *FRONT;
    int Ctr = 1, Flag = 0;

    if (TravNode == NULL)
        printf("The queue is empty. Enter option 1 to create a queue.\n");
    else
    {
        Flag = (*FRONT)->data;
        do
        {
            printf("Node %d Content:\n", Ctr);
			printf("\tData => %d\n", TravNode->data);
            *FRONT = TravNode->next;
            TravNode->next = NULL;
            (*REAR)->next = TravNode;
            *REAR = (*REAR)->next;
            TravNode = *FRONT;
            Ctr++;
        }
        while (Flag != (*FRONT)->data);
        TravNode = NULL;
    }

    printf("\nQueue displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node in queue

void enqueue(node** FRONT, node** REAR)
{
    node* NewNode = (node*)malloc(sizeof(node*));
    
    printf("Enter data => ");
    scanf("%d", &NewNode->data);
    NewNode->next = NULL;

    // If queue is empty
    if (*REAR == NULL)
        *FRONT = *REAR = NewNode;
    // If queue is not empty
    else
    {
        (*REAR)->next = NewNode;
        *REAR = NewNode;
    }
    NewNode = NULL;

    printf("\n%d added. Enter option 2 or 3 to view the queue.\n", (*REAR)->data);
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node in queue

void dequeue(node** FRONT, node** REAR)
{
    node* DelNode = *FRONT;

    // If queue is empty
    if (DelNode == NULL)
        printf("\nDeletion failed because the queue is empty. Enter option 1 to create a queue.\n");
    // If queue is not empty
    else
    {
        *FRONT = (*FRONT)->next;
        DelNode->next = NULL;
        free(DelNode);
        DelNode = NULL;
        printf("\nFront node deleted. Enter option 2 or 3 to view the queue.\n");
    }

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete the entire queue

void delQueue(node** FRONT, node** REAR)
{
    // If queue is empty
    if (*FRONT == NULL && *REAR == NULL)
		printf("\nDeletion failed because the queue is already empty. Enter option 1 to create a queue.\n");
	// If queue is not empty
    else
	{
		free(*FRONT);
		*FRONT = *REAR = NULL;
		printf("\nEntire queue has been deleted. Enter option 2 or 3 to view the queue.\n");
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
	node* FRONT = NULL;
    node* REAR = NULL;
	
	// Action status string

	const char* options[] = {"", "\nCREATING A QUEUE",
            "\nDISPLAYING QUEUE WITH REPEATING DATA\n", 
            "\nDISPLAYING QUEUE WITH NO REPEATING DATA\n", 
			"\nADDING A NODE\n", 
            "\nDeleting front node...",
            "\nDeleting the entire queue...",
            // "SORT THE STACK",
        };
	
	// Menu loop

	while (isChoosing == 1)
    {
		// system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a queue\n");
        printf("2: Display queue with repeating data\n");
		printf("3: Display queue with no repeating data\n");
		printf("4: Add a node\n");
		printf("5: Delete a node\n");
		printf("6: Delete the entire queue\n");
		printf("0: EXIT\n");

		printf("\nEnter your option: ");
        scanf("%d", &option);
		
		switch(option)
        {
			case 1:
				printf("%s\n", options[option]);
				createQueue(&FRONT, &REAR);
				option = 0;
				break;
			case 2:
				printf("%s\n", options[option]);
				displayRepeat(&FRONT, &REAR);
				option = 0;
				break;
			case 3:
				printf("%s\n", options[option]);
				displayNoRepeat(&FRONT, &REAR);
				option = 0;
				break;
			case 4:
				printf("%s\n", options[option]);
				enqueue(&FRONT, &REAR);
				option = 0;
				break;
			case 5:
				printf("%s\n", options[option]);
				dequeue(&FRONT, &REAR);
				option = 0;
				break;
            case 6:
				printf("%s\n", options[option]);
				delQueue(&FRONT, &REAR);
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
