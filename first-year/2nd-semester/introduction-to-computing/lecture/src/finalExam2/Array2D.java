package finalExam2;

public class Array2D
{
	public static void main(String[] args)
	{
		String[][] cars = {{"Full Name", "Year", "Car Brand", "Model", "Plate Number", "Car Color"},
				{"Sierra Ortiz", "2021", "Toyota", "Hilux", "AGZ-3000", "Black"},
				{"Rhydian Talbot", "2004", "Mitsubishi", "Evo", "ABV-0408", "Red"},
				{"Livia Cain", "2021", "Ford", "Territory", "FGZ-2202", "Blue"},
				{"Keri Mclean", "2005", "Toyota", "Tamaraw Fx", "AMN-3403", "Green"},
				{"Anais Chapman", "2017", "Honda", "Civic", "XFA-3504", "Red"},
				{"Nafisa Conway", "1998", "Mazda", "323", "MAZ-9056", "Silver"},
				{"Jaimee Seymour", "2014", "Ford", "Mustang", "FFB-3566", "Yellow"},
				{"Jonah Mccartney", "2006", "Isuzu", "Crosswind", "JSO-6717", "Pink"},
				{"Hayden Odling", "1977", "Layland", "Mini", "SLW 287R", "Neon Green"}};
		
		for (int i = 0; i < cars.length; i++)
		{
			for (int j = 0; j < cars[i].length; j++)
			{
				if ((j == 2 && i != 2 && i != 0) || j == 3 && i != 3 && i != 4 && i != 8)
					System.out.print(cars[i][j] + "\t\t");
				else
					System.out.print(cars[i][j] + "\t");
			}
			System.out.println();
		}
	}
}
