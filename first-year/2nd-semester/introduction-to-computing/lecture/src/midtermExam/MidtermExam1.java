/**
 * A Java program that greets the user when time is entered
 */

package midtermExam;

import java.util.Scanner;

public class MidtermExam1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter time (e.g. 5): ");
		int time = sc.nextInt();
		System.out.print("AM or PM? ");
		String meridiem = sc.next();
		
		if (meridiem.equalsIgnoreCase("am"))
		{
			if (time >= 1 && time <= 12)
			{
				System.out.println("Good morning");
			}
			else
			{
				System.out.println("Invalid time. Please only choose numbers from 1 to 12.");
			}
		}
		else if (meridiem.equalsIgnoreCase("pm"))
		{
			if ((time >= 1 && time <= 5) || time == 12)
			{
				System.out.println("Good afternoon");
			}
			else if (time >= 6 && time <= 9)
			{
				System.out.println("Good evening");
			}
			else if (time >= 10 && time <= 11)
			{
				System.out.println("Sleeping Time");
			}
			else
			{
				System.out.println("Invalid time. Please only choose numbers from 1 to 12.");
			}
		}
		else
		{
			System.out.println("Invalid time. Please choose AM or PM only.");
		}
		
		sc.close();
	}
}
