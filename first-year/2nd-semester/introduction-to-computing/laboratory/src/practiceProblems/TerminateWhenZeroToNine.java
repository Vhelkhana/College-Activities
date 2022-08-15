/**
 * Input a character and terminate the process once 0-9 is entered.
 */

package practiceProblems;

import java.util.Scanner;

public class TerminateWhenZeroToNine
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while (true)
		{	
			System.out.println("Input a character, enter 0-9 to stop");
			char ch = sc.next().charAt(0);
				
			if (ch >= '0' && ch <= '9')
				break;
		}
		System.out.println("stop");
	}
}
