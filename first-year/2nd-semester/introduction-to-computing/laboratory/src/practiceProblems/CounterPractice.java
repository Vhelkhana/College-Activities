/**
 * 1. Generate the ff. series of numbers:		
 * a. 3 2 1 0 -1 -2 -3
 * b. 1 1 2 4 3 9 4 16 5 25
 */

package practiceProblems;

public class CounterPractice
{
	public static void main(String[] args)
	{
		// PART A
		System.out.println("PART A");
		System.out.println("Solution 1");
		solutionA1();
		System.out.println("Solution 2");
		solutionA2();
		
		// PART B
		System.out.println("PART B");
		solutionB1();
		solutionB2();
		solutionB3();
	}
	
	// PART A
	// Solution 1 using while loop
	public static void solutionA1()
	{
		int ctr = 3;
		while (ctr >= -3)
		{	
			System.out.print(ctr + " ");
			ctr--;
		}
		System.out.println();
	}
	// Solution 2 using for loop
	public static void solutionA2()
	{
		for (int ctr = 3; ctr >= -3; ctr--)	
			System.out.print(ctr + " ");
		System.out.println();
	}
	
	// PART B
	// Solution 1
	public static void solutionB1()
	{
		int ctr = 1;
		while (ctr <= 5)
		{	
			int sq = ctr * ctr;
			System.out.print(ctr + " " + sq + " ");
			ctr++;
		}
		System.out.println();
	}
	// Solution 2
	public static void solutionB2()
	{
		int ctr = 1;
		while (ctr <= 5)
		{	
			System.out.print(ctr + " " +  ctr * ctr + " ");
			ctr++;
		}
		System.out.println();
	}
	// Solution 3
	public static void solutionB3()
	{
		int ctr = 1;	
		while (ctr <= 5)	
		{	
			System.out.print(ctr + " " +  Math.pow(ctr, 2) + " ");
			ctr++;
		}
		System.out.println();
	}
}
