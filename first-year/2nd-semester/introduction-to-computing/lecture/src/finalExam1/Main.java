package finalExam1;

public class Main
{
	public static void main(String[] args)
	{
		Viper s1 = new Viper("Snek", "orange", 0, 0, 0);
		Python s2 = new Python("Noodle Boi", "yellow", 0, 0, 0);
		Rattlesnake s3 = new Rattlesnake("Murder Spaghetti", "brown", 0, 0, 0);
		
		// Setter methods
		s1.setAge(8);
		s1.setLength(10);
		s1.setWeight(8.5);
		
		s2.setAge(6);
		s2.setLength(16);
		s2.setWeight(21);
		
		s3.setAge(20);
		s3.setLength(5.2);
		s3.setWeight(4.5);
		
		// VIPER
		
		System.out.println("-----VIPER-----\n");
		System.out.println("Name: " + s1.getName());
		System.out.println("Color: " + s1.getColor());
		System.out.println("Age: " + s1.getAge());
		
		// Snake methods
		System.out.println("\n->SNAKE METHODS");
		s1.faveFood();
		s1.sleep();
		
		// Abstract methods
		System.out.println("\n->ABSTRACT METHODS");
		s1.hungry();
		s1.threatened();
		s1.angry();
		
		// Unique viper methods
		System.out.println("\n->UNIQUE METHODS");
		s1.escape();
		s1.bored();
		System.out.println();
		
		// PYTHON
		
		System.out.println("-----PYTHON-----\n");
		System.out.println("Name: " + s2.getName());
		System.out.println("Color: " + s2.getColor());
		System.out.println("Age: " + s2.getAge());
		
		// Snake methods
		System.out.println("\n->SNAKE METHODS");
		s2.faveFood();
		s2.sleep();
		
		// Abstract methods
		System.out.println("\n->ABSTRACT METHODS");
		s2.hungry();
		s2.threatened();
		s2.angry();
		
		// Unique python methods
		System.out.println("\n->UNIQUE METHODS");
		s2.itchy();
		s2.cold();
		System.out.println();
		
		// RATTLESNAKE
		
		System.out.println("-----RATTLESNAKE-----\n");
		System.out.println("Name: " + s3.getName());
		System.out.println("Color: " + s3.getColor());
		System.out.println("Age: " + s3.getAge());
		
		// Snake methods
		System.out.println("\n->SNAKE METHODS");
		s3.faveFood();
		s3.sleep();
		
		// Abstract methods
		System.out.println("\n->ABSTRACT METHODS");
		s3.hungry();
		s3.threatened();
		s3.angry();
		
		// Unique rattlesnake methods
		System.out.println("\n->UNIQUE METHODS");
		s3.drink();
		s3.winter();
	}
}
