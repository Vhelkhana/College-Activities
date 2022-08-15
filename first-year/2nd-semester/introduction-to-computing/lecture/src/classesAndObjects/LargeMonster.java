package classesAndObjects;

import java.util.ArrayList;
import java.util.Scanner;

public class LargeMonster
{
	// Attributes
	
	String nameLargeMonster;
	String nickname;
	String enemyType;
	ArrayList<String> elements = new ArrayList<String>();
	ArrayList<String> ailments = new ArrayList<String>();
	ArrayList<String> weakness = new ArrayList<String>();
	ArrayList<String> resistances = new ArrayList<String>();
	ArrayList<String> locations = new ArrayList<String>();
	String temperedLevel;
	
	LargeMonster(String nameLargeMonster, String nickname, String enemyType, 
			ArrayList<String> elements, ArrayList<String> ailments, 
			ArrayList<String> weakness, ArrayList<String> resistances, 
			ArrayList<String> locations, String temperedLevel)
	{
		this.nameLargeMonster = nameLargeMonster;
		this.nickname = nickname;
		this.enemyType = enemyType;
		this.elements = elements;
		this.ailments = ailments;
		this.weakness = weakness;
		this.resistances = resistances;
		this.locations = locations;
		this.temperedLevel = temperedLevel;
	}
	
	// Method to print large monsters
	
	void printLargeMonster(String nameLargeMonster, String nickname, String enemyType, 
			ArrayList<String> elements, ArrayList<String> ailments, 
			ArrayList<String> weakness, ArrayList<String> resistances, 
			ArrayList<String> locations, String temperedLevel)
	{
		// Name
		
		System.out.println("----------" + this.nameLargeMonster + "----------");
		
		// Nickname
		
		System.out.println("Nickname: " + this.nickname);
		
		// Enemy type
		
		System.out.println("Enemy Type: " + this.enemyType);
		
		// Elements
		
		for (int i = 0; i < this.elements.size(); i++)
		{
			if (i == 0)
				System.out.print("Elements: " + this.elements.get(i));
			else
				System.out.print(", " + this.elements.get(i));
		}
		System.out.println();
		
		// Ailments
		
		for (int i = 0; i < this.ailments.size(); i++)
		{
			if (i == 0)
				System.out.print("Ailments: " + this.ailments.get(i));
			else
				System.out.print(", " + this.ailments.get(i));
		}
		System.out.println();
		
		// Weakness
		
		for (int i = 0; i < this.weakness.size(); i++)
		{
			if (i == 0)
				System.out.print("Weakness: " + this.weakness.get(i));
			else
				System.out.print(", " + this.weakness.get(i));
		}
		System.out.println();
		
		// Resistances
		
		for (int i = 0; i < this.resistances.size(); i++)
		{
			if (i == 0)
				System.out.print("Resistances: " + this.resistances.get(i));
			else
				System.out.print(", " + this.resistances.get(i));
		}
		System.out.println();
		
		// Locations
		
		for (int i = 0; i < this.locations.size(); i++)
		{
			if (i == 0)
				System.out.print("Locations: " + this.locations.get(i));
			else
				System.out.print(", " + this.locations.get(i));
		}
		System.out.println();
		
		// Tempered level
		
		System.out.println("Tempered Lv.: " + this.temperedLevel);
	}
	
	// Method to change nickname of large monsters
	
	void changeNickname(String nameLargeMonster, String nickname)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\nDo you want to set a nickname to this large monster [Y/N]? ");
		String resp = sc.nextLine();
		
		if (resp.equalsIgnoreCase("Y"))
		{
			System.out.print("Enter nickname: ");
			String nick = sc.nextLine();
			
			this.nickname = nick;
			System.out.println("You renamed " + nameLargeMonster + " to " + this.nickname + "!");
		}
		else
		{
			System.out.println("Nickname not changed.");
		}
	}
}
