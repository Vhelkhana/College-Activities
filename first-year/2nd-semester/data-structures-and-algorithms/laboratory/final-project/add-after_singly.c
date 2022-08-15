#include <stdio.h>
#include <stdlib.h>

// Node structure

typedef struct node
{
    int data;
    struct node *next;
} node;

// Function to create a linked list

node* createList(node* START)
{
    node* NewNode = (node*)malloc(sizeof(node));
	char Resp, Temp;
	int Ctr = 1;

	START = NewNode;
	
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
			NewNode = NewNode->next;
        }
   	}
	while(toupper(Resp) == 'Y');

   	NewNode->next = NULL; // Signifies end of list
   	NewNode = NULL; // Disconnects NewNode pointer

	printf("\nList created. Enter option 2 to view list.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to display the list

void displayList(node* START)
{
    node* Current = START;
	int Ctr = 1;

    // Traverses the list while printing data
   	if (Current == NULL)
		printf("The list is empty. Enter option 1 to create list.\n");
   	else
     	do
        {
	 		printf("Node %d Content:\n", Ctr);
	 		printf("\tData => %d\n", Current->data);
	 		Current = Current->next;
	 		Ctr++;
     	}
        while (Current != NULL);
    
	// Disconnects Current pointer
    Current = NULL;

	printf("\nList displayed.\n");
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node after a value

node* addAfterGivenNode(node* START)
{
    node* NewNode = (node*)malloc(sizeof(node));
    node* Current = START;
	int After_Val = 0, Flag = 0;

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);
    int temp = NewNode->data;
	NewNode->next = NULL;

	printf("Enter value where %d will be inserted after => ", temp);
    scanf("%d", &After_Val);

	// If list is empty
	if (START == NULL)
	{
		printf("\nInsertion failed because the list is empty. Enter option 1 to create list.\n", After_Val);
	}
	// if list is not empty
	else
	{
		// Adding after given node
		do
		{
			if (After_Val == Current->data)
				Flag = 1;
			else
				Current = Current->next;
		}
		while (Flag != 1 && Current != NULL);
		if (Flag == 1)
		{
			NewNode->next = Current->next;
			Current->next = NewNode;
			NewNode = NULL;
			
			printf("\n%d added after %d. Enter option 2 to view list.\n", temp, After_Val);
		}
		// If After_Val does not exist in the list
		else
			printf("\nInsertion failed because %d does not exist in the list.\n", After_Val);
	    
		Current = NULL;
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to delete whole list

node* delList(node* START)
{
	if (START == NULL)
		printf("\nDeletion failed because the list is already empty. Choose option 2 to view list.\n");
	else
	{
		free(START);
		START = NULL;
		printf("\nEntire list has been deleted. Choose option 2 to view list.\n");
	}
	
	printf("Press any key to continue...");
	getch();
	system("cls");
	
	return START;
}

// Main function

int main()
{
	// Variables

	int option = 0;
	int isChoosing = 1;
	node* START = NULL;
	
	// Action status string

	const char* options[] = {"", "\nCREATING A LINKED LIST",
            "\nDisplaying list...\n", 
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
		printf("******** MAIN MENU ********\n");
		printf("1: Create a single linked list\n");
		printf("2: Display single linked list\n");
		printf("6: Add a node after a given node\n");
		printf("12: Delete the entire list\n");
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
			case 6:
				printf("%s\n", options[option]);
				START = addAfterGivenNode(START);
				option = 0;
				break;
			case 12:
				printf("%s\n", options[option]);
				START = delList(START);
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
