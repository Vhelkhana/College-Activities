package practiceProblems;

import java.util.Scanner;

public class NestedLoops
{
	// Main method
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int r = 0;
		
		while (true)
		{
			System.out.print("Enter row: ");
			r = sc.nextInt();
			
			if (r > 0)
				break;
		}
		
		System.out.println();
		System.out.println("-----PATTERN 1-----");
		pattern1(r);
		
		System.out.println();
		System.out.println("-----PATTERN 2-----");
		pattern2(r);
		
		System.out.println();
		System.out.println("-----PATTERN 3-----");
		pattern3(r);
		
		System.out.println();
		System.out.println("-----PATTERN 4-----");
		pattern4(r);
		
		System.out.println();
		System.out.println("-----PATTERN 5-----");
		pattern5(r);
		
		System.out.println();
		System.out.println("-----PATTERN 6-----");
		pattern6(r);
		
		System.out.println();
		System.out.println("-----PATTERN 7-----");
		pattern7(r);
		
		System.out.println();
		System.out.println("-----PATTERN 8-----");
		pattern8(r);
		
		System.out.println();
		System.out.println("-----PATTERN 9-----");
		pattern9(r);
		
		System.out.println();
		System.out.println("-----PATTERN 10-----");
		pattern10(r);
		
		System.out.println();
		System.out.println("-----PATTERN 11-----");
		pattern11(r);
		
		System.out.println();
		System.out.println("-----PATTERN 12-----");
		pattern12(r);
		
		System.out.println();
		System.out.println("-----PATTERN 13-----");
		pattern13(r);
		
		System.out.println();
		System.out.println("-----PATTERN 14-----");
		pattern14(r);
	}
	// Pattern 1
	public static void pattern1(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int col = row; col >= 1; col--)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 2
	public static void pattern2(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int space = row; space < r; space++)
			{
				System.out.print("  ");
			}
			for (int col = row; col >= 1; col--)
			{
				System.out.print(col + " ");
			}
			System.out.println();
		}
	}
	// Pattern 3
	public static void pattern3(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int space = row; space < r; space++)
			{
				System.out.print("  ");
			}
			for (int col = row; col >= 1; col--)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 4
	public static void pattern4(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int space = row; space >= 2; space--)
			{
				if (space != 1)
					System.out.print("  ");
			}
			for (int col = row; col <= r; col++)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 5
	public static void pattern5(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int col = r; col >= row; col--)
			{
				System.out.print(col + " ");
			}
			System.out.println();
		}
	}
	// Pattern 6
	public static void pattern6(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int col = r; col >= row; col--)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 7
	public static void pattern7(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int col = 1; col <= row; col++)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 8
	public static void pattern8(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int space = row; space >= 2; space--)
			{
				if (space != 1)
					System.out.print("  ");
			}
			for (int col = r; col >= row; col--)
			{
				System.out.print(col + " ");
			}
			System.out.println();
		}
	}
	// Pattern 9
	public static void pattern9(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int space = row; space >= 2; space--)
			{
				if (space != 1)
					System.out.print("  ");
			}
			for (int col = row; col <= r; col++)
			{
				System.out.print(col + " ");
			}
			System.out.println();
		}
	}
	// Pattern 10
	public static void pattern10(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int space = row; space >= 2; space--)
			{
				if (space != 1)
					System.out.print("  ");
			}
			for (int col = r; col >= row; col--)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 11
	public static void pattern11(int r)
	{
		for (int row = r; row >= 1; row--)
		{
			for (int space = r - 1; space >= row; space--)
			{
				System.out.print("  ");
			}
			for (int col = 1; col <= row; col++)
			{
				System.out.print(row + " ");
			}
			System.out.println();
		}
	}
	// Pattern 12
	public static void pattern12(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int space = r - 1; space >= row; space--)
			{
				System.out.print(" ");
			}
			for (int col = 1; col <= row; col++)
			{
				System.out.print(col + " ");
			}
			System.out.println();
		}
	}
	// Pattern 13
	public static void pattern13(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int space = r - 1; space >= row; space--)
			{
				System.out.print("  ");
			}
			for (int col = 1; col <= row; col++)
			{
				if (col == 1)
					System.out.print("* ");
				else
					System.out.print("* * ");
			}
			System.out.println();
		}
	}
	// Pattern 14
	public static void pattern14(int r)
	{
		for (int row = 1; row <= r; row++)
		{
			for (int col = row; col <= row * r; col += row)
			{
				System.out.print(col + "\t");
			}
			System.out.println();
		}
	}
}
