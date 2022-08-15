/**
 * Operations of single/singly-linked list
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

// Function to add a new node at the head

node* addHead(node* START)
{
    node* NewNode = (node*)malloc(sizeof(node));

    printf("\nEnter data => ");
    scanf("%d", &NewNode->data);

	// Connecting at the head
	NewNode->next = START;
	START = NewNode;
	// Disconnecting NewNode pointer
	NewNode = NULL;

	printf("\n%d added at the head. Enter option 2 to view list.\n", START->data);
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to add a new node at the tail

node* addTail(node* START)
{
    node* END = START;
	node* NewNode = (node*)malloc(sizeof(node));

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);
    int temp = NewNode->data;
	NewNode->next = NULL;

	// If list is empty
	if (START == NULL)
	{
		START = NewNode;
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
		END->next = NewNode;
		NewNode = NULL;
		END = NULL;
	}
	
	printf("\n%d added at the tail. Enter option 2 to view list.\n", temp);
	printf("Press any key to continue...\n");
	getch();
	system("cls");
	
	return START;
}

// Function to add a new node before a value

node* addBeforeGivenNode(node* START)
{
	node *Previous = NULL, *Current = START;
	node* NewNode = (node*)malloc(sizeof(node));
	int Before_Val = 0, Flag = 0;

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);
    int temp = NewNode->data;
	NewNode->next = NULL;

	printf("Enter value where %d will be inserted before => ", temp);
    scanf("%d", &Before_Val);

	// If list is empty
	if (START == NULL)
	{
		printf("\nInsertion failed because the list is empty. Enter option 1 to create list.\n");
	}
	// if list is not empty
	else
	{
		// Adding before given node
		do
		{
			if (Before_Val == Current->data)
				Flag = 1;
			else
			{
				Previous = Current;
				Current = Current->next;
			}
		}
		while (Flag != 1 && Current != NULL);
		if (Flag == 1)
		{
			NewNode->next = Current;
			if (Previous == NULL)
				START = NewNode;
			else
				Previous->next = NewNode;
			NewNode = NULL;
			
			printf("\n%d added before %d. Enter option 2 to view list.\n", temp, Before_Val);
		}
		// If Before_Val does not exist in the list
		else
		{
			printf("\nInsertion failed because %d does not exist in the list.\n", Before_Val);
		}
		Previous = Current = NULL;
	}
	
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
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

// Function to delete a node at the head

node* delHead(node* START)
{
    node *DelNode = START;
	
	// If list is empty
	if (START == NULL)
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n");
	// If list is not empty
	else
	{
		START = START->next;
		DelNode->next = NULL;
		free(DelNode);
		DelNode = NULL;
		
		printf("\nHead node has been deleted. Enter option 2 to view list.\n");
	}
	
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to delete a node at the tail

node* delTail(node* START)
{
    node* Previous = NULL;
	node* DelNode = START;

	// If there are no nodes
	if (DelNode == NULL)
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n");
	// If there is only one node
	else if (DelNode != NULL && DelNode->next == NULL)
	{
		free(DelNode);
		DelNode = NULL;
		START = NULL;
		printf("\nTail node has been deleted. Enter option 2 to view list.\n");
	}
	// If there are 2 or more nodes
	else if (DelNode != NULL && DelNode->next != NULL)
	{
		while (DelNode->next != NULL)
		{
			Previous = DelNode;
			DelNode = DelNode->next;
		}
		Previous->next = NULL;
		Previous = NULL;
		free(DelNode);
		DelNode = NULL;
		printf("\nTail node has been deleted. Enter option 2 to view list.\n");
	}
	
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to delete a node by value

node* delNode(node* START)
{
    node* Previous = NULL;
	node* DelNode = START;
	int Delete_Val = 0, Flag = 0;

	printf("\nEnter value to be deleted => ");
    scanf("%d", &Delete_Val);
	
	// If list is empty
	if (START == NULL)
	{
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n", Delete_Val);
	}
	// If list is not empty
	else
	{
		// Finding Delete_Val
		while (Flag != 1 && DelNode != NULL)
		{
			if (Delete_Val == DelNode->data)
				Flag = 1;
			else
			{
				Previous = DelNode;
				DelNode = DelNode->next;
			}
		}
		if (Flag == 0)
			printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
		else
		{
			// Deleting node by value
			if (DelNode == START)
			{
				START = START->next;
				DelNode->next = NULL;
			}
			else 
			{
				Previous->next = DelNode->next;
				DelNode->next = NULL;
			}
			free(DelNode);
		}
		Previous = DelNode = NULL;
		printf("\n%d has been deleted.\n", Delete_Val);
	}
	
	printf("Press any key to continue...\n");
	getch();
	system("cls");

	return START;
}

// Function to delete a node before a value

node* delBeforeNode(node* START)
{
	int Delete_Val = 0;
    node *Current, *Previous, *Temp;

    printf("\nEnter value to delete node before it => ");
    scanf("%d", &Delete_Val);
	
    // If list is empty
    if (START == NULL)
	{
        printf("\nDeletion failed because the list is empty. Enter option 1 to create list.\n");
    }
    // If list only has one node
    else if (START->next == NULL)
	{
        printf("\nDeletion failed because list only has one node.\n");
    }
    // If list have 2 or more nodes
    else
	{
        Current = START;
        Temp = START;
        Previous = START;
        // Finding Delete_Val
        while (Current->data != Delete_Val)
		{
            Temp = Previous;
            Previous = Current;
            Current = Current->next;
			// If Delete_Val is not in the list
			if (Current == NULL)
			{
				printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
				printf("Press any key to continue...");
				getch();
				system("cls");

				return START;
			}
        }
        // If Delete_Val is the second node
        if (Current == START->next)
		{
            START = Current;
            free(Previous);
			printf("\nNode before %d has been deleted.\n", Delete_Val);
        }
        // If Delete_Val is the first node
        else if (Current == START)
		{
            printf("\nDeletion failed because there are no nodes before %d to delete.\n", Delete_Val);
        }
        // If Delete_Val is not the first or second node
        else
		{
            Temp->next = Current;
            free(Previous);
			printf("\nNode before %d has been deleted.\n", Delete_Val);
        }
	}

	printf("Press any key to continue...");
	getch();
	system("cls");

	return START;
}

// Function to delete a node after a value

void delAfterNode(node* START)
{
    int Delete_Val = 0;
    struct node *Current, *After, *Temp;

    printf("\nEnter value to delete node after it => ");
    scanf("%d", &Delete_Val);
	
    // If list is empty
    if (START == NULL)
	{
        printf("\nDeletion failed because the list is empty. Enter option 1 to create list.\n");
    }
	// If list only has one node
    else if (START->next == NULL)
	{
        printf("\nDeletion failed because list only has one node.\n");
    }
    else
	{
        Current = START;
        Temp = START;
        After = START;
		// Finding Delete_Val
        while (Current->data != Delete_Val)
		{
            Current = Current->next;
			if (Current == NULL)
			{
				printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
				printf("Press any key to continue...");
				getch();
				system("cls");
				return;
			}
        }
		// If Delete_Val is at the tail
		if (Current->next == NULL)
		{
			printf("\nDeletion failed because there are no nodes after %d to delete.\n", Delete_Val);
			printf("Press any key to continue...");
			getch();
			system("cls");
			return;
		}
		// Deleting second node
        else if (Current == START)
		{
            After = After->next;
			Temp = After->next;
			Current->next = Temp;
			After->next = NULL;
			free(After);
			After = NULL;
			printf("\nNode after %d has been deleted.\n", Delete_Val);
        }
		// Deleting tail
		else if (Current->next->next == NULL)
		{
			After = Current->next;
			Current->next = NULL;
			free(After);
			After = NULL;
			printf("\nNode after %d has been deleted.\n", Delete_Val);
		}
		// Deleting anywhere from 3rd node to second to the last node
        else
		{
            After = Current->next;
			Temp = After->next;
			Current->next = Temp;
			After->next = NULL;
            free(After);
			After = NULL;
			printf("\nNode after %d has been deleted.\n", Delete_Val);
        }
	}

	Current = NULL;
	After = NULL;
	Temp = NULL;

	printf("Press any key to continue...");
	getch();
	system("cls");
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
		printf("3: Add a node at the head\n");
		printf("4: Add a node at the tail\n");
		printf("5: Add a node before a given node\n");
		printf("6: Add a node after a given node\n");
		printf("7: Delete a node at the head\n");
		printf("8: Delete a node at the tail\n");
		printf("9: Delete a node by value\n");
		printf("10: Delete a node before a given node\n");
		printf("11: Delete a node after a given node\n");
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
			case 3:
				printf("%s\n", options[option]);
				START = addHead(START);
				option = 0;
				break;
			case 4:
				printf("%s\n", options[option]);
				START = addTail(START);
				option = 0;
				break;
			case 5:
				printf("%s\n", options[option]);
				START = addBeforeGivenNode(START);
				option = 0;
				break;
			case 6:
				printf("%s\n", options[option]);
				START = addAfterGivenNode(START);
				option = 0;
				break;
			case 7:
				printf("%s\n", options[option]);
				START = delHead(START);
				option = 0;
				break;
			case 8:
				printf("%s\n", options[option]);
				START = delTail(START);
				option = 0;
				break;
			case 9:
				printf("%s\n", options[option]);
				START = delNode(START);
				option = 0;
				break;
			case 10:
				printf("%s\n", options[option]);
				START = delBeforeNode(START);
				option = 0;
				break;
			case 11:
				printf("%s\n", options[option]);
				delAfterNode(START);
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
