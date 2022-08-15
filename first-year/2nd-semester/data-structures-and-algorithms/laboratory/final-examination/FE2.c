/**
 * Operations of double/doubly-linked list
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>

// Node structure

typedef struct node
{
    int no;
    char name[15];
    float unitPrice;
    int quantity;
    float totalPrice;
    struct node *prev, *next;
} node;

// Function to enter information

void enterInfo(node** NewNode)
{
	char temp;

    // Product number
    printf("Product No.: ");
    scanf("%d", &(*NewNode)->no);
    fflush(stdin);

    // Product Name
    printf("Product Name: ");
    gets((*NewNode)->name);
	fflush(stdin);

    // Unit price
    printf("Unit Price: ");
    scanf("%f", &(*NewNode)->unitPrice);
	fflush(stdin);

    // Quantity
    printf("Qty.: ");
    scanf("%d", &(*NewNode)->quantity);
    fflush(stdin);

    (*NewNode)->totalPrice = ((*NewNode)->unitPrice * (*NewNode)->quantity) + (((*NewNode)->unitPrice * (*NewNode)->quantity) * 0.12);
}

// Function to create a linked list

void createList(node** HEAD, node** TAIL)
{
    node* NewNode = (node*)malloc(sizeof(node));
	char Resp, Temp;
	int Ctr = 1;

    *HEAD = NewNode;
    *TAIL = NewNode;
    (*HEAD)->prev = NULL;
    (*HEAD)->next = NULL;
	
    do
	{
    	printf("\nProduct no. %d\n", Ctr);
    	
        enterInfo(&NewNode);

        // Add another record
    	printf("\nAdd another product [Y/N]? ");
    	scanf("%c", &Resp);
    	if (toupper(Resp) == 'Y')
       	{
			Ctr++;
			NewNode->next = (node*)malloc(sizeof(node));
            NewNode->next->prev = NewNode;
            NewNode = NewNode->next;
            *TAIL = NewNode;
        }
   	}
	while(toupper(Resp) == 'Y');

    (*TAIL)->next = NULL;
    NewNode = NULL; // Disconnects NewNode pointer

	printf("\nList created. Enter option 2 to view list.\n");
	printf("Press any key to continue...\n");
	getch();
	//system("cls");
}

// Function to display the list from top to bottom

void topToBottom(node** HEAD)
{
    node* TravNode = *HEAD;
	int Ctr = 1;

	// If list is empty
	if (TravNode == NULL)
		printf("There are no products. Enter option 1 to input product.\n\n");
	// If list is not empty
	else
    {
        printf("\tProduct No.");
        printf("\tProduct Name");
        printf("\tUnit Price");
        printf("\tQty.");
        printf("\tTotal Price\n");
        do
		{
            printf("%d.\t", Ctr);
            printf("%d\t\t", TravNode->no);
	 		printf("%s\t\t", TravNode->name);
            printf("%0.2f\t\t", TravNode->unitPrice);
            printf("%d\t", TravNode->quantity);
            printf("%0.2f\t\n", TravNode->totalPrice);
            TravNode = TravNode->next;
			Ctr++;
		}
		while (TravNode != NULL);
    }
	
	printf("\nList displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	//system("cls");
}

// Function to add a new node at the tail

void addTail(node** HEAD, node** TAIL)
{
    node* NewNode = (node*)malloc(sizeof(node));

	enterInfo(&NewNode);

	NewNode->prev = NULL;
	NewNode->next = NULL;

	// If list is empty
	if (*TAIL == NULL)
		*HEAD = *TAIL = NewNode;
	// If list is not empty
	else
	{
		NewNode->prev = *TAIL;
		(*TAIL)->next = NewNode;
		*TAIL = NewNode; // Connects the new node at the tail
	}
	NewNode = NULL; // Disconnects NewNode pointer

	printf("\nAdded at the tail. Enter option 2 to view receipt.\n");
	printf("Press any key to continue...\n");
	getch();
	//system("cls");
}

// Main function

int main()
{
	// Variables

	int option = 0;
	int isChoosing = 1;
	node* HEAD = NULL;
    node* TAIL = NULL;
	
	// Action status string

	const char* options[] = {"", "\nCREATING A LINKED LIST",
            "\nDISPLAYING LIST FROM TOP TO BOTTOM\n", 
            "\nADDING A NODE AT THE TAIL",
        };
	
	// Menu loop

	while (isChoosing == 1)
    {
		// system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a double linked list\n");
		printf("2: Display double linked list from top to bottom\n");
		printf("3: Add a node at the tail\n");
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
				topToBottom(&HEAD);
				option = 0;
				break;
			case 3:
				printf("%s\n", options[option]);
				addTail(&HEAD, &TAIL);
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
				//system("cls");
				break;
		}
	}
	return 0;
}
