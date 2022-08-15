/**
 * A Java program that requires user to work out and eat before going out
 */

package midtermExam;

import java.util.Scanner;

public class MidtermExam4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		boolean doneWorkout = false; // Given
		boolean doneEating = true; // Given
		
		System.out.println("Did you do your workout [Y/N]? ");
		String resp1 = sc.next();
		System.out.println("Are you done eating [Y/N]? ");
		String resp2 = sc.next();
		
		// Updates work out and eating status
		
		if (resp1.equalsIgnoreCase("Y"))
			doneWorkout = false;
		else
			doneWorkout = true;
		if (resp2.equalsIgnoreCase("Y"))
			doneEating = true;
		else
			doneEating = false;
		
		// Displays if user can go out
		
		if (!doneWorkout && doneEating)
			System.out.println("You can go out.");
		else
			System.out.println("You cannot go out.");
		
		sc.close();
	}
}
