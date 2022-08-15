package classesAndObjects;

import java.util.ArrayList;

public class Main
{
	public static void main(String[] args)
	{
		// CHARACTER
		
		Character char1 = new Character(); // First object
		
		// LARGE MONSTERS
		
		// Kirin attribute values
		
		ArrayList<String> eleKirin = new ArrayList<String>();
		eleKirin.add("Thunder");
		ArrayList<String> ailKirin = new ArrayList<String>();
		ailKirin.add("Thunderblight");
		ailKirin.add("Paralysis");
		ArrayList<String> weakKirin = new ArrayList<String>();
		weakKirin.add("Fire");
		weakKirin.add("Water");
		weakKirin.add("Ice");
		ArrayList<String> resKirin = new ArrayList<String>();
		resKirin.add("Thunder");
		resKirin.add("Paralysis");
		ArrayList<String> locKirin = new ArrayList<String>();
		locKirin.add("Coral Highlands");
		locKirin.add("The Guiding Lands");
		
		LargeMonster Kirin = new LargeMonster("Kirin", "None", "Elder Dragon", eleKirin, 
				ailKirin, weakKirin, resKirin, locKirin, "3"); // Second object
		
		// Xeno'jiiva attribute values
		
		ArrayList<String> eleXeno = new ArrayList<String>();
		eleXeno.add("Fire");
		eleXeno.add("Dragon");
		ArrayList<String> ailXeno = new ArrayList<String>();
		ailXeno.add("Fireblight");
		ailXeno.add("Dragonblight");
		ArrayList<String> weakXeno = new ArrayList<String>();
		weakXeno.add("Poison");
		ArrayList<String> resXeno = new ArrayList<String>();
		resXeno.add("Sleep");
		ArrayList<String> locXeno = new ArrayList<String>();
		
		LargeMonster Xeno = new LargeMonster("Xeno'jiiva", "None", "Elder Dragon", eleXeno, 
				ailXeno, weakXeno, resXeno, locXeno, "3 (Arch-Tempered Only)");  // Third object

		// CHARACTER CREATION
		
		System.out.println("CHARACTER CREATION!!!!!\n");
		char1.charCreation();
		System.out.println();
		
		// PRINTING
		
		// Character
		
		char1.printCharacter();
		System.out.println();
		
		// Kirin
		
		System.out.println("LARGE MONSTER GUIDE!!!!!\n");
		
		Kirin.printLargeMonster(Kirin.nameLargeMonster, Kirin.nickname, Kirin.enemyType, 
				Kirin.elements, Kirin.ailments, Kirin.weakness, Kirin.resistances, 
				Kirin.locations, Kirin.temperedLevel);
		
		Kirin.changeNickname(Kirin.nameLargeMonster, Kirin.nickname);
		
		// Xeno'jiiva
		
		System.out.println();
		
		Xeno.printLargeMonster(Xeno.nameLargeMonster, Xeno.nickname, Xeno.enemyType, 
				Xeno.elements, Xeno.ailments, Xeno.weakness, Xeno.resistances, 
				Xeno.locations, Xeno.temperedLevel);
		
		Xeno.changeNickname(Xeno.nameLargeMonster, Xeno.nickname);
	}
}
