/*
	ICC 0103-7 Intermediate Programming (Lecture)
	Dana Justine D. Pacatang
	
	A Java program that includes:
		a. C Style comment
		b. 5 variables (any data type)
		c. 1 Function/Method
		d. Print all variables and method
*/

package exercises;

import java.util.Scanner;

public class Exercise1Num3
{
	// Method to print user's favorite animals
	
	public static String favAnimals(String name, String item1, String item2, String item3, String item4, String item5)
	{
		// Prints all variables
		System.out.println(name + "'s Top Favorite Animals");
		System.out.println("Top 1: " + item1);
		System.out.println("Top 2: " + item2);
		System.out.println("Top 3: " + item3);
		System.out.println("Top 4: " + item4);
		System.out.println("Top 5: " + item5);
		
		String fave = "Your favorite animals are " + item1 + ", " + item2 + ", " + item3 + ", " + item4 + ", and " + item5 + "!";
		
		return fave;
	}
	
	// Main method
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your first name: ");
		String firstName = sc.nextLine();
		System.out.println("Enter your 5 favorite animals: ");
		String animal1 = sc.next();
		String animal2 = sc.next();
		String animal3 = sc.next();
		String animal4 = sc.next();
		String animal5 = sc.next();
		
		// Prints method
		System.out.println(favAnimals(firstName, animal1, animal2, animal3, animal4, animal5));
		
		sc.close();
	}
}