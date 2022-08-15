#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Product structure

typedef struct
{
    int no;
    char name[15];
    float unitPrice;
    int quantity;
} Product;

// Gotoxy

COORD coord = {0, 0};
void gotoxy(int x, int y);

// Main function

int main()
{
    Product Products[5];
    int i = 0, j = 0;
    char temp;
    float totalPrice[5];

    system("cls");

    // Headings

    printf("\tPrint No.\t");
    printf("Product Name\t");
    printf("Unit Price\t");
    printf("Qty.\t");
    printf("Total Price\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d.\n", i + 1);
    }

    // Enter data

	int xCoord = 8, yCoord = 1; //11

    // Rows
	for (i = 0; i < 5; i++, yCoord++)
	{
        xCoord = 8;
        // Columns
		for (j = 0; j < 5; j++, xCoord += 16)
		{
			gotoxy(xCoord, yCoord);
            switch(j)
            {
                case 0: scanf("%d", &Products[i].no);
                        scanf("%c", temp);
                        break;
                case 1: scanf("%s", &Products[i].name);
                        scanf("%c", temp);
                        break;
                case 2: scanf("%f", &Products[i].unitPrice);
                        scanf("%c", temp);
                        break;
                case 3: scanf("%d", &Products[i].quantity);
                        break;
                case 4: gotoxy(xCoord - 8, yCoord);
                        totalPrice[j] = (Products[i].unitPrice * Products[i].quantity) + ((Products[i].unitPrice * Products[i].quantity) * 0.12);
                        printf("%0.2f", totalPrice[j]);
                        break;
            }
		}
		printf("\n");
	}
}

// Function to make gotoxy() work

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}