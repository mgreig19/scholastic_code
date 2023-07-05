// Good addition program that handles bad input
// by testing first

import java.util.Scanner;

public class Addition1
{
   public static void main(String[] args)
   {
      // create a Scanner to obtain input from the command window
      Scanner input = new Scanner(System.in);

      int number1;
      int number2;
      String x;
      int sum;

      System.out.print("Enter first integer: ");
      while (!input.hasNextInt())
	{
	  x = input.next();  // eat bad value
	  System.out.print("Not an integer. Try again: ");
	}
      number1 = input.nextInt();	  
      
      System.out.print("Enter second integer: ");
      while (!input.hasNextInt())
	{
	  x = input.next();  // eat bad value
	  System.out.print("Not an integer. Try again: ");
	}
      number2 = input.nextInt();

      sum = number1 + number2;

      System.out.printf("Sum is %d%n", sum); // display sum
   } // end method main
} // end class Addition1

