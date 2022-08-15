/**
 * ICC 0103-7 Intermediate Programming (Lecture)
 * Dana Justine D. Pacatang
 * 
 * A Java program that will explicitly cast Long to Short data type
 */

package exercises;

public class Exercise1Num2
{
	public static void main(String[] args)
	{
		long num1Long = 32768L;
		short num1Short = 0;
		num1Short = (short) num1Long;
		
		long num2Long = 32767;
		short num2Short = 0;
		num2Short = (short) num2Long;
		
		System.out.println(num1Short); // numbers larger than 32,768 cannot fit in short so it shows -32768 instead
		System.out.println(num2Short); // 32,767 fits in short so it prints the number correctly
	}
}
