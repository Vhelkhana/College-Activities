package midtermExam;

public class MidtermExam
{
	public static void main (String[] args)
	{
		double result = 10/4;
		System.out.println(result);
		
		int num1 = 8, num2 = 3;
		System.out.print("The quotient is " + num1 / num2);
		
		boolean T = true;
		boolean F = false;
		
		if (T && F || T || F && T)
			System.out.println("\nValid");
		if (T != F)
			System.out.println("\nValid");
	
		System.out.println(2 + 5 + "ab");
		System.out.println("ab" + 2 + 5);
		
		int num = 3;
		
		if (num > 0 && num < 5)
			System.out.println("\nValid");
		
		System.out.println(1 + 2 - 3 * 4 / 5);
		
	}
}
