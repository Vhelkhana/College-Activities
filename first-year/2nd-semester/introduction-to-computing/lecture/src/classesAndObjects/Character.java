package classesAndObjects;

import java.util.Scanner;
import org.apache.commons.lang3.StringUtils;

public class Character
{
	// Attributes
	
	String gender;
	String skinColor;
	String hairstyle;
	String nameChar;
	
	// Method to create character
	
	void charCreation()
	{
		Scanner sc = new Scanner(System.in);
		
		// Gender
		
		do
		{
			System.out.println("GENDER: FEMALE MALE");
			System.out.print("Gender: ");
			this.gender =  sc.nextLine();
			
			if (!(gender.equalsIgnoreCase("Female") || gender.equalsIgnoreCase("Male")))
			{
				System.out.println("Invalid gender.");
			}
		}
		while (!(gender.equalsIgnoreCase("Female") || gender.equalsIgnoreCase("Male")));
		
		System.out.println();
		
		// Skin color
		
		do
		{
			System.out.println("SKIN COLOR: TYPE 1 TYPE 2 TYPE 3");
			System.out.print("Skin color: ");
			this.skinColor = sc.nextLine();
			
			if (!(skinColor.equalsIgnoreCase("Type 1") || skinColor.equalsIgnoreCase("Type 2") || 
					skinColor.equalsIgnoreCase("Type 3")))
			{
				System.out.println("Invalid skin color.");
			}
		}
		while (!(skinColor.equalsIgnoreCase("Type 1") || skinColor.equalsIgnoreCase("Type 2") || 
				skinColor.equalsIgnoreCase("Type 3")));
		
		System.out.println();
		
		// Hair style
		
		do
		{
			System.out.println("HAIR STYLE: TYPE 1 TYPE 2 TYPE 3");
			System.out.print("Hair style: ");
			this.hairstyle = sc.nextLine();
			
			if (!(hairstyle.equalsIgnoreCase("Type 1") || hairstyle.equalsIgnoreCase("Type 2") || 
					hairstyle.equalsIgnoreCase("Type 3")))
			{
				System.out.println("Invalid hair style.");
			}
		}
		while (!(hairstyle.equalsIgnoreCase("Type 1") || hairstyle.equalsIgnoreCase("Type 2") || 
				hairstyle.equalsIgnoreCase("Type 3")));
		
		// Character name
		
		System.out.print("\nCharacter name: ");
		this.nameChar = sc.nextLine();
		
		System.out.println("\nCharacter created.");
	}
	
	// Method to print character
	
	void printCharacter()
	{
		System.out.println("Name: " + this.nameChar);
		System.out.println("Gender: " + StringUtils.capitalize(this.gender.toLowerCase()));
		System.out.println("Skin color: " + StringUtils.capitalize(this.skinColor.toLowerCase()));
		System.out.println("Hair style: " + StringUtils.capitalize(this.hairstyle.toLowerCase()));
	}
}
