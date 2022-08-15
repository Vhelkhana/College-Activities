package finalExam3;

import java.util.HashMap;
import java.util.Scanner;

public class HashMaps
{
	public static void main(String[] args)
	{
		HashMap<String, Integer> championships = new HashMap<>();
		HashMap<String, String> nickname = new HashMap<>();
		
		Scanner sc = new Scanner(System.in);
		
		championships.put("Kobe", 5);
		championships.put("LeBron", 4);
		championships.put("Stephen", 4);
		championships.put("Michael", 6);
		championships.put("Dwayne", 3);
		
		nickname.put("Kobe", "Black Mamba");
		nickname.put("LeBron", "The King");
		nickname.put("Stephen", "Chef Curry");
		nickname.put("Michael", "Air Jordan");
		nickname.put("Dwayne", "D-Wade");
		
		System.out.print("who is your favorite Basketball player? ");
		String player = sc.next();
		championships(championships, nickname, player);
	}
	
	public static void championships(HashMap<String, Integer> championships, HashMap<String, String> nickname, String player)
	{
		if (championships.get(player) != null && nickname.get(player) != null )
		{
			System.out.println(nickname.get(player) + " has " + championships.get(player) + " championships.");
		}
		else
		{
			System.out.println("The system does not recognize this player.");
		}
	}
}
