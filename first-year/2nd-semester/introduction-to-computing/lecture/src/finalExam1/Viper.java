package finalExam1;

public class Viper extends Snake
{
	// Constructor
	Viper(String name, String color, int age, double lengthFt, double weightKG)
	{
		super(name, color, age, lengthFt, weightKG);
	}
	
	// Unique method 1
	public void escape()
	{
		System.out.println("Slither away...");
	}
	
	// Unique method 2
	public void bored()
	{
		System.out.println("Talking to fellow snek");
	}
	
	// Abstract 1
	void hungry()
	{
		System.out.println("Hungry!");
	}

	// Abstract 2
	void threatened()
	{
		System.out.println("Hides!");
	}

	// Abstract 3
	void angry()
	{
		System.out.println("Bite!");
	}
}
