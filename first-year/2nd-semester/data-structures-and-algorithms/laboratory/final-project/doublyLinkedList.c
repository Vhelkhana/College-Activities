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
		printf("The list is empty.\n");
	// If list is not empty
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

// Function to add a new node at the head

void addHead(node** HEAD, node** TAIL)
{
    node* NewNode = (node*)malloc(sizeof(node));

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);

	NewNode->prev = NULL;
	NewNode->next = NULL;

	// If list is empty
	if (*HEAD == NULL)
		*HEAD = *TAIL = NewNode;
	// If list is not empty
	else
	{
		NewNode->next = *HEAD;
		(*HEAD)->prev = NewNode;
		*HEAD = NewNode; // Connects the new node at the head
	}
	NewNode = NULL; // Disconnects NewNode pointer

	printf("\n%d added at the head. Enter option 2 to view list.\n", (*HEAD)->data);
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node at the tail

void addTail(node** HEAD, node** TAIL)
{
    node* NewNode = (node*)malloc(sizeof(node));

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);

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

	printf("\n%d added at the tail. Enter option 2 to view list.\n", (*TAIL)->data);
	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node before a value

void addBeforeGivenNode(node** HEAD)
{
	node* Current = *HEAD;
	node* NewNode = (node*)malloc(sizeof(node));
	int Before_Val = 0, Flag = 0;

	printf("\nEnter data => ");
    scanf("%d", &NewNode->data);
	int temp = NewNode->data;

	NewNode->prev = NULL;
	NewNode->next = NULL;

	printf("Enter value where %d will be inserted before => ", temp);
    scanf("%d", &Before_Val);

	// If list is empty
	if (Current == NULL)
		printf("\nInsertion failed because the list is empty. Enter option 1 to create list.\n");
	// if list is not empty
	else
	{
		// Finding Before_Val
		while(Flag == 0 && Current != NULL)
		{
			if (Current->data == Before_Val)
				Flag = 1;
			else
				Current = Current->next;
		}
		// If Before_Val does not exist in the list
		if (Flag == 0)
			printf("\nInsertion failed because %d does not exist in the list.\n", Before_Val);
		// Adding before a given node
		else
		{
			// If Before_Val is the head
			if (Current == *HEAD)
			{
				NewNode->next = *HEAD;
				(*HEAD)->prev = NewNode;
				*HEAD = NewNode;
				printf("\n%d added before %d. Enter option 2 to view list.\n", temp, Before_Val);
			}
			// If Before_Val is not the head
			else
			{
				NewNode->next = Current;
				NewNode->prev = Current->prev;
				Current->prev->next = NewNode;
				Current->prev = NewNode;
				printf("\n%d added before %d. Enter option 2 to view list.\n", temp, Before_Val);
			}
			Current = NewNode = NULL;
		}
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to add a new node after a value

void addAfterGivenNode(node** HEAD, node** TAIL)
{
    node* Current = *HEAD;
	node* NewNode = (node*)malloc(sizeof(node));
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
				Current->next = NewNode;
				Current->next->prev = NewNode;
				printf("\n%d added after %d. Enter option 2 to view list.\n", temp, After_Val);
			}
			Current = NewNode = NULL;
		}
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node at the head

void delHead(node** HEAD, node** TAIL)
{
    node *DelNode = *HEAD;

	// If list is empty
	if (DelNode == NULL)
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n");
	// If list only has one node
	else if (DelNode->next == NULL)
	{
		free(DelNode);
		DelNode = NULL;
		*HEAD = NULL;
		*TAIL = NULL;
		printf("\nHead node has been deleted. Enter option 2 to view list.\n");
	}
	// If list has more than 1 node
	else
	{
		*HEAD = (*HEAD)->next;
		(*HEAD)->prev = NULL;
		DelNode->next = NULL;
		free(DelNode);
		DelNode = NULL;
		printf("\nHead node has been deleted. Enter option 2 to view list.\n");
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node at the tail

void delTail(node** HEAD, node** TAIL)
{
    node *DelNode = *TAIL;

	// If list is empty
	if (DelNode == NULL)
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n");
	// If list only has one node
	else if ((*HEAD)->next == NULL)
	{
		free(DelNode);
		DelNode = NULL;
		*HEAD = NULL;
		*TAIL = NULL;
		printf("\nTail node has been deleted. Enter option 2 to view list.\n");
	}
	// If list has more than 1 node
	else
	{
		*TAIL = (*TAIL)->prev;
		(*TAIL)->next = NULL;
		DelNode->prev = NULL;
		free(DelNode);
		DelNode = NULL;
		printf("\nTail node has been deleted. Enter option 2 to view list.\n");
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node by value

void delNode(node** HEAD, node** TAIL)
{
	node* DelNode = *HEAD;
	node *Previous, *After;
	int Delete_Val = 0, Flag = 0;
	
	printf("\nEnter value to be deleted => ");
    scanf("%d", &Delete_Val);

	// If list is empty
	if (DelNode == NULL)
		printf("\nDeletion failed because list is empty. Enter option 1 to create list.\n", Delete_Val);
	// If list only has one node
	else if (DelNode->next == NULL)
	{
		free(DelNode);
		*HEAD = NULL;
		*TAIL = NULL;
		DelNode = NULL;
		printf("\n%d has been deleted.\n", Delete_Val);
	}
	// If list has more than one node
	else
	{
		// Finding Delete_Val
		while (Flag == 0 && DelNode != NULL)
		{
			if (DelNode->data == Delete_Val)
				Flag = 1;
			else
				DelNode = DelNode->next;
		}
		if (Flag == 0)
			printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
		// Deleting node by value
		else
		{
			// If Delete_Val is at the head
			if (DelNode == *HEAD)
			{
				*HEAD = (*HEAD)->next;
				(*HEAD)->prev = NULL;
				DelNode->next = NULL;
				free(DelNode);
				DelNode = NULL;
				printf("\n%d has been deleted.\n", Delete_Val);
			}
			// If Delete_Val is at the tail
			else if (DelNode == *TAIL)
			{
				*TAIL = (*TAIL)->prev;
				(*TAIL)->next = NULL;
				DelNode->prev = NULL;
				free(DelNode);
				DelNode = NULL;
				printf("\n%d has been deleted.\n", Delete_Val);
			}
			// If Delete_Val is not at the head nor tail
			else
			{
				Previous = DelNode->prev;
				After = DelNode->next;
				Previous->next = After;
				After->prev = Previous;
				DelNode->next = NULL;
				DelNode->prev = NULL;
				free(DelNode);
				DelNode = NULL;
				printf("\n%d has been deleted.\n", Delete_Val);
			}
		}
		
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node before a value

void delBeforeNode(node** HEAD)
{
	node *Current = *HEAD, *Previous = *HEAD;
	int Delete_Val = 0;

	printf("\nEnter value to delete node before it => ");
    scanf("%d", &Delete_Val);

	// If list is empty
	if (Current == NULL)
		printf("\nDeletion failed because the list is empty. Enter option 1 to create list.\n");
	// If list only has one node
	else if (Current->next == NULL)
	{
		printf("\nDeletion failed because list only has one node.\n");
	}
	else
	{
		// Finding Delete_Val
        while (Current->data != Delete_Val)
		{
			Current = Current->next;
			// If Delete_Val is not in the list
			if (Current == NULL)
			{
				printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
				printf("Press any key to continue...\n");
				getch();
				system("cls");
				return;
			}
		}
		// If Delete_Val is the second node
        if (Current == (*HEAD)->next)
		{
            *HEAD = Current;
			Previous->next = NULL;
			Current->prev = NULL;
            free(Previous);
			Previous = NULL;
			Current = NULL;
			printf("\nNode before %d has been deleted.\n", Delete_Val);
        }
        // If Delete_Val is the first node
        else if (Current == *HEAD)
		{
            printf("\nDeletion failed because there are no nodes before %d to delete.\n", Delete_Val);
        }
        // If Delete_Val is not the first nor second node
        else
		{
            Previous = Current->prev;
			Previous->prev->next = Current;
			Current->prev = Previous->prev;
			Previous->prev = NULL;
			Previous->next = NULL;
            free(Previous);
			Previous = NULL;
			Current = NULL;
			printf("\nNode before %d has been deleted.\n", Delete_Val);
        }
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete a node after a value

void delAfterNode(node** HEAD, node** TAIL)
{
    node *Current = *HEAD, *After = *HEAD;
	int Delete_Val = 0;

	printf("\nEnter value to delete node after it => ");
    scanf("%d", &Delete_Val);

	// If list is empty
	if (Current == NULL)
		printf("\nDeletion failed because the list is empty. Enter option 1 to create list.\n");
	// If list only has one node
	else if (Current->next == NULL)
	{
		printf("\nDeletion failed because list only has one node.\n");
	}
	else
	{
		// Finding Delete_Val
        while (Current->data != Delete_Val)
		{
			Current = Current->next;
			// If Delete_Val is not in the list
			if (Current == NULL)
			{
				printf("\nDeletion failed because %d does not exist in the list.\n", Delete_Val);
				printf("Press any key to continue...\n");
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
        // If Delete_Val is the second to the last node
        else if (Current->next == *TAIL)
		{
			After = Current->next;
			*TAIL = Current;
			Current->next = NULL;
			After->prev = NULL;
			free(After);
			After = NULL;
			Current = NULL;
			printf("\nNode after %d has been deleted.\n", Delete_Val);
        }
        // If Delete_Val is not the second to the last node nor at the tail
        else
		{
            After = Current->next;
			Current->next = After->next;
			After->next->prev = Current;
			After->prev = NULL;
			After->next = NULL;
			free(After);
			After = NULL;
			Current = NULL;
			printf("\nNode after %d has been deleted.\n", Delete_Val);
        }
	}

	printf("Press any key to continue...\n");
	getch();
	system("cls");
}

// Function to delete whole list

void delList(node** HEAD, node** TAIL)
{
	if (*HEAD == NULL && *TAIL == NULL)
		printf("\nDeletion failed because the list is already empty. Choose option 2 to view list.\n");
	else
	{
		free(*HEAD);
		*HEAD = NULL;
		*TAIL = NULL;
		printf("\nEntire list has been deleted. Choose option 2 to view list.\n");
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
		printf("4: Add a node at the head\n");
		printf("5: Add a node at the tail\n");
		printf("6: Add a node before a given node\n");
		printf("7: Add a node after a given node\n");
		printf("8: Delete a node at the head\n");
		printf("9: Delete a node at the tail\n");
		printf("10: Delete a node by value\n");
		printf("11: Delete a node before a given node\n");
		printf("12: Delete a node after a given node\n");
		printf("13: Delete the entire list\n");
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
			case 4:
				printf("%s\n", options[option]);
				addHead(&HEAD, &TAIL);
				option = 0;
				break;
			case 5:
				printf("%s\n", options[option]);
				addTail(&HEAD, &TAIL);
				option = 0;
				break;
			case 6:
				printf("%s\n", options[option]);
				addBeforeGivenNode(&HEAD);
				option = 0;
				break;
			case 7:
				printf("%s\n", options[option]);
				addAfterGivenNode(&HEAD, &TAIL);
				option = 0;
				break;
			case 8:
				printf("%s\n", options[option]);
				delHead(&HEAD, &TAIL);
				option = 0;
				break;
			case 9:
				printf("%s\n", options[option]);
				delTail(&HEAD, &TAIL);
				option = 0;
				break;
			case 10:
				printf("%s\n", options[option]);
				delNode(&HEAD, &TAIL);
				option = 0;
				break;
			case 11:
				printf("%s\n", options[option]);
				delBeforeNode(&HEAD);
				option = 0;
				break;
			case 12:
				printf("%s\n", options[option]);
				delAfterNode(&HEAD, &TAIL);
				option = 0;
				break;
			case 13:
				printf("%s\n", options[option]);
				delList(&HEAD, &TAIL);
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
