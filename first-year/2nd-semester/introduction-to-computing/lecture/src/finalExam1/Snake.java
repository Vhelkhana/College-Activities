package finalExam1;

public abstract class Snake
{
	// 5 private attributes
	private String name;
	private String color;
	private int age;
	private double lengthFt;
	private double weightKG;
	
	// Constructor
	Snake(String name, String color, int age, double lengthFt, double weightKG)
	{
		this.name = name;
		this.color = color;
		this.age = age;
		this.lengthFt = lengthFt;
		this.weightKG = weightKG;
	}
	
	// Method 1
	void faveFood()
	{
		System.out.println("Mouse!");
	}
	
	// Method 2
	void sleep()
	{
		System.out.println("Zzzz");
	}
	
	// Getter 1
	public String getName()
	{
		return name;
	}
	
	// Getter 2
	public String getColor()
	{
		return color;
	}
	
	// Getter 3
	public int getAge()
	{
		return age;
	}
	
	// Setter 1
	public void setAge(int age)
	{
		this.age = age;
	}
	
	// Setter 2
	public void setLength(double lengthFt)
	{
		this.lengthFt = lengthFt;
	}
	
	// Setter 3
	public void setWeight(double weightKG)
	{
		this.weightKG = weightKG;
	}
	
	// Abstract 1
	abstract void hungry();
	
	// Abstract 2
	abstract void threatened();
	
	// Abstract 3
	abstract void angry();
}
