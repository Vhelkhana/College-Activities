/**
 * A Java program that checks plate number coding scheme
 */

package midtermExam;

import java.util.Scanner;

public class MidtermExam3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter your plate number's last digit: ");
		int plateLastDigit = sc.nextInt();
		
		if (plateLastDigit == 1 || plateLastDigit == 2)
			System.out.println("Your car is not allowed on Monday.");
		else if (plateLastDigit == 3 || plateLastDigit == 4)
			System.out.println("Your car is not allowed on Tuesday.");
		else if (plateLastDigit == 5 || plateLastDigit == 6)
			System.out.println("Your car is not allowed on Wednesday.");
		else if (plateLastDigit == 7 || plateLastDigit == 8)
			System.out.println("Your car is not allowed on Thursday.");
		else if (plateLastDigit == 9 || plateLastDigit == 0)
			System.out.println("Your car is not allowed on Friday.");
		
		sc.close();
	}
}
