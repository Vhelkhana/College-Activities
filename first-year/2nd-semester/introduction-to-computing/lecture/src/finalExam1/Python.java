package finalExam1;

public class Python extends Snake
{
	// Constructor
	Python(String name, String color, int age, double lengthFt, double weightKG)
	{
		super(name, color, age, lengthFt, weightKG);
	}
	
	// Unique method 1
	void itchy()
	{
		System.out.println("Shed skin!");
	}
	
	// Unique method 2
	void cold()
	{
		System.out.println("Curling into ball...");
	}
	
	// Abstract 1
	void hungry()
	{
		System.out.println("Need food!");
	}

	// Abstract 2
	void threatened()
	{
		System.out.println("Camouflage!");
	}

	// Abstract 3
	void angry()
	{
		System.out.println("Hiss!");
	}
}
