/**
 * A Java program that enables user to withdraw money
 */

package midtermExam;

import java.util.Scanner;

public class MidtermExam2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Welcome to the Land Bank ATM");
		System.out.print("Please Enter Your Pin: ");
		int pin = sc.nextInt();
		
		if (pin == 9576)
		{
			double currentAmount = 1000.00d;
			double fee = 10.00d;
			
			System.out.println("The pin is correct");
			System.out.print("How much will you withdraw? ");
			double withdraw = sc.nextDouble();
			if (withdraw > 990)
			{
				System.out.println("******************************");
				System.out.println("You only have P " + String.format("%.2f", currentAmount) + 
						". You can only withdraw P " + String.format("%.2f", currentAmount - fee) + 
						" and below because of the P " + String.format("%.2f", fee) + " withdrawal fee.");
			}
			else
			{
				currentAmount -= withdraw + fee;
				
				System.out.println("******************************");
				System.out.println("Your transaction: Withdrawal");
				System.out.println("Amount: " + String.format("%.2f", withdraw));
				System.out.println("Withdrawal fee: " + String.format("%.2f", fee));
				System.out.println("Your new balance is P " + String.format("%.2f", currentAmount));
				System.out.println("******************************");
				System.out.println("Thank you for using our service!");
				
			}
		}
		else
		{
			System.out.println("Incorrect pin. Please try again.");
		}
		
		sc.close();
	}
}
