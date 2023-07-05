// based on Fig. 14.2: StringMisc.java

// Demonstrates the length, charAt and getChars
// methods of the String class.

public class ScharAt02
{
   public static void main(String[] args)
   {
      String s1 = "hello there";
      char[] charArray = new char[5];

      int i;
      
      System.out.printf("s1: %s", s1);

      // test length method
      System.out.printf("\nLength of s1: %d", s1.length());

      // loop through characters in s1 with charAt and display reversed
      System.out.printf("%nThe string reversed is: ");

      for (int count = s1.length() - 1; count >= 0; count--)
         System.out.printf("%c ", s1.charAt(count));
      System.out.printf("%n%n");
      
      
      // charAt
      System.out.printf("Using substr: ");

      for (i = 0; i < s1.length(); i++)
	System.out.printf("%s", s1.charAt(i));
      System.out.printf("%n");
      

      // substring
      System.out.printf("Using substr: ");

      for (i = 0; i < s1.length(); i++)
	System.out.printf("%s", s1.substring(i, i+1));
      System.out.printf("%n");

      // code points
      System.out.printf("Code points: ");

      for (i = 0; i < s1.length(); i++)
	System.out.printf("%s ", s1.codePointAt(i));
      System.out.printf("%n");

      
      
      // copy characters from string into charArray
      s1.getChars(0, 5, charArray, 0);
      System.out.printf("%nThe character array is: ");

      for (char character : charArray)
         System.out.print(character);

      System.out.println();
   } 
} // end class ScharAt02
