package finalExam1;

public class Rattlesnake extends Snake
{

	Rattlesnake(String name, String color, int age, double lengthFt, double weightKG)
	{
		super(name, color, age, lengthFt, weightKG);
	}

	// Unique method 1
	void drink()
	{
		System.out.println("Mlem");
	}
	
	// Unique method 2
	void winter()
	{
		System.out.println("Hibernate!");
	}
	
	// Abstract 1
	void hungry()
	{
		System.out.println("Want mouse!");
	}

	// Abstract 2
	void threatened()
	{
		System.out.println("Run!");
	}

	// Abstract 3
	void angry()
	{
		System.out.println("Rattles!");
	}
}
