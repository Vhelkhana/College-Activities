/**
 * ICC 0103.1-7 Dana Justine D. Pacatang
 * 
 * INSTRUCTIONS:
 * 
 * Area Menu					
 * C. Circle		C = πr2		π = 3.1416	r = radius
 * R. Rectangle		R = lw		l = length	w = width
 * S. Square		S = s2		s = side	
 * T. Triangle		T = 1/2bh	b = base	h = height
 * 
 * Use a SWITCH-CASE approach.					
 * Select which area to perform and input the requirements for a particular selected area.
 * The input requirements for each formula are variables located to the right of the equal
 * symbol. Any other choices except CRSTX/crstx are considered 'invalid'.					
 */

package assignments;

import java.util.Scanner;

public class SwitchCase
{
	// Method to display menu and get option
	public static String displayMenu()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Area Menu");
		System.out.println("C. Circle");
		System.out.println("R. Rectangle");
		System.out.println("S. Square");
		System.out.println("T. Triangle");
		System.out.println("X. Exit\n");
		System.out.print("Enter option: ");
		String option = sc.next();
		
		return option;
	}
	
	// Method to calculate area of circle
	public static void areaCircle()
	{
		Scanner sc = new Scanner(System.in);
		double pi = 3.1416;
		
		System.out.print("Enter radius: ");
		double r = sc.nextDouble();
		double C = pi * r * r;
		System.out.println("The area of the circle is " + C + ".\n");
	}
	
	// Method to calculate area of rectangle
	public static void areaRectangle()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter length: ");
		double l = sc.nextDouble();
		System.out.print("Enter width: ");
		double w = sc.nextDouble();
		double R = l * w;
		System.out.println("The area of the rectangle is " + R + ".\n");
	}
	
	// Method to calculate area of square
	public static void areaSquare()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter side: ");
		double s = sc.nextDouble();
		double S = s * s;
		System.out.println("The area of the square is " + S + ".\n");
	}
	
	// Method to calculate area of triangle
	public static void areaTriangle()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter base: ");
		double b = sc.nextDouble();
		System.out.print("Enter height: ");
		double h = sc.nextDouble();
		double T = (double)1 / 2 * b * h;
		System.out.println("The area of the triangle is " + T + ".\n");
	}
	
	// Main method
	public static void main(String[] args)
	{
		int isChoosing = 1;
		
		while(isChoosing == 1)
		{
			String option = displayMenu();
			switch(option.toUpperCase())
			{
				case "C": 
					areaCircle();
					break;
				case "R": 
					areaRectangle();
					break;
				case "S": 
					areaSquare();
					break;
				case "T": 
					areaTriangle();
					break;
				case "X": 
					System.out.println("\nProgram terminated.");
					isChoosing = 0;
					break;
				default:
					System.out.println("\nInvalid option.");
					System.out.println("Please try again.\n");
					break;
			}
		}
	}
}
