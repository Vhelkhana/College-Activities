/*****************************************************************************

MACHINE PROBLEM 3

Write a program that computes the cost of the postage on first-class mail
according to the following rate scale: 10.00 pesos for the first 5 grams or
fraction of a gram, 2.00 pesos for each additional gram, or fraction thereof,
plus a 15.00 pesos service charge if the customer desires special delivery.
The input is the weight of the mail.

*****************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main()
{
    float wMail, cMail, fstGrm, addGrm;
    int ctr = 0;
    char temp, resp;
    
    printf("Enter weight of mail (g): ");
    scanf("%f", &wMail);
    
    fstGrm = wMail/5;
    
    if (fstGrm > 1)
    {
		addGrm = wMail - 5;
		for (ctr; addGrm > 0; ++ctr)
        {
	        addGrm -= 1;
	    }
		cMail = (ctr * 2) + 10;
    }
    else
    {
		cMail = 10.00;
    }
        
    do
    {
        printf("Do you want to make a special delivery [Y/N]? ");
		scanf("%c", &temp); /***to catch the null value being returned
                   by scanf() or gets(), used when there is a scanf()
                   or gets() prior to reading a character***/
		scanf("%c", &resp);
        resp = toupper(resp);
    }
	while (!((resp) == 'Y'||(resp) == 'N'));
    
    if ((resp) == 'Y')
    {
        cMail += 15;
		printf("\nAdditional PHP 15.00 was added for special delivery.");
		printf("\nThe total cost of postage is PHP %0.2f.\n", cMail);
    }
    else if (resp == 'N')
    {
        printf("The cost of postage is PHP %0.2f.\n", cMail);
    }
        
    return 0;
}
