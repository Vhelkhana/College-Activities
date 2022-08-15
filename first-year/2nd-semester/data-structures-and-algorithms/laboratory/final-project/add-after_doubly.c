#include <stdio.h>
#include <stdlib.h>

// Node structure

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

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
	system("cls");
}

// Function to display the list from top to bottom

void topToBottom(node** HEAD)
{
    node* TravNode = *HEAD;
	int Ctr = 1;

	// If list is empty
	if (TravNode == NULL)
	// If list is not empty
		printf("The list is empty.\n");
	else
		do
		{
			printf("Node %d Content:\n", Ctr);
			printf("\tData => %d\n", TravNode->data);
			TravNode = TravNode->next;
			Ctr++;
		}
		while (TravNode != NULL);
	
	printf("\nList displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to display the list from bottom to top

void bottomToTop(node** TAIL)
{
    node* TravNode = *TAIL;
	int Ctr = 1;

	// If list is empty
	if (TravNode == NULL)
		printf("The list is empty.\n");
	// If list is not empty
	else
		do
		{
			printf("Node %d Content:\n", Ctr);
			printf("\tData => %d\n", TravNode->data);
			TravNode = TravNode->prev;
			Ctr++;
		}
		while (TravNode != NULL);
	
	printf("\nList displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node after a value

void addAfterGivenNode(node** HEAD, node** TAIL)
{
    node* Current = *HEAD;
	node* NewNode = (node*)malloc(sizeof(node*));
	int After_Val = 0, Flag = 0;

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);
	int temp = NewNode->data;

	NewNode->prev = NULL;
	NewNode->next = NULL;

	printf("Enter value where %d will be inserted after => ", temp);
    scanf("%d", &After_Val);

	// If list is empty
	if (Current == NULL)
		printf("\nInsertion failed because the list is empty. Enter option 1 to create list.\n");
	// if list is not empty
	else
	{
		// Finding After_Val
		while(Flag == 0 && Current != NULL)
		{
			if (Current->data == After_Val)
				Flag = 1;
			else
				Current = Current->next;
		}
		// If After_Val does not exist in the list
		if (Flag == 0)
			printf("\nInsertion failed because %d does not exist in the list.\n", After_Val);
		// Adding after given a node
		else
		{
			// If After_Val is at the tail
			if (Current == *TAIL)
			{
				NewNode->prev = *TAIL;
				(*TAIL)->next = NewNode;
				*TAIL = NewNode;
				printf("\n%d added after %d. Enter option 2 to view list.\n", temp, After_Val);
			}
			// If After_Val is not at the tail
			else
			{
				NewNode->next = Current->next;
				NewNode->prev = Current;
				Current->next->prev = NewNode;
				Current->next = NewNode;
				printf("\n%d added after %d. Enter option 2 to view list.\n", temp, After_Val);
			}
			Current = NewNode = NULL;
		}
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
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
			"\nDISPLAYING LIST FROM BOTTOM TO TOP\n", 
            "\nADDING A NODE AT THE HEAD",
            "\nADDING A NODE AT THE TAIL",
            "\nADDING A NODE BEFORE A GIVEN NODE",
            "\nADDING A NODE AFTER A GIVEN NODE",
            "\nDeleting node from the head...",
            "\nDeleting node from the end...",
            "\nDELETING A GIVEN NODE",
            "\nDELETING A NODE BEFORE A GIVEN NODE",
            "\nDELETING A NODE AFTER A GIVEN NODE",
            "\nDeleting the entire list...",
            // "SORT THE LIST",
        };
	
	// Menu loop

	while (isChoosing == 1)
    {
		// system("cls");
		printf("******** MAIN MENU ********\n");
		printf("1: Create a double linked list\n");
		printf("2: Display double linked list from top to bottom\n");
		printf("3: Display double linked list from bottom to top\n");
		printf("7: Add a node after a given node\n");
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
				bottomToTop(&TAIL);
				option = 0;
				break;
			case 7:
				printf("%s\n", options[option]);
				addAfterGivenNode(&HEAD, &TAIL);
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


