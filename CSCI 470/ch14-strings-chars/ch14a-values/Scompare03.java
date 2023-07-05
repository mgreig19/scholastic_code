// based on Fig. 14.3: StringCompare.java
// String methods equals, equalsIgnoreCase and compareTo

public class Scompare03
{
   public static void main(String[] args)
   {
      // s1 is a copy of "hello"
      String s1 = new String("hello");

      String s2 = "goodbye";
      String s3 = "Happy Birthday";
      String s4 = "happy birthday";

      System.out.printf(
         "s1 = %s%ns2 = %s%ns3 = %s%ns4 = %s%n%n",
	 s1, s2, s3, s4);

      // test for equality
      if (s1.equals("hello"))  // true
         System.out.println("s1 equals \"hello\"");
      else
         System.out.println("s1 does not equal \"hello\""); 

      // test for equality with ==
      if (s1 == "hello")  // false, not the same object
         System.out.println("s1 is the same object as \"hello\"");
      else
         System.out.println("s1 is not the same object as \"hello\"");

      // test for equality (ignore case)
      if (s3.equalsIgnoreCase(s4))  // true
        System.out.printf("%s equals %s with case ignored%n%n",
			   s3, s4);
      else
         System.out.println("s3 does not equal s4%n%n");

      // test compareTo
      System.out.printf(
         "s1.compareTo(s2) is %d%n", s1.compareTo(s2));
      System.out.printf(
         "s2.compareTo(s1) is %d%n", s2.compareTo(s1));
      System.out.printf(
         "s1.compareTo(s1) is %d%n", s1.compareTo(s1));
      System.out.printf(
         "s3.compareTo(s4) is %d%n", s3.compareTo(s4));
      System.out.printf(
         "s4.compareTo(s3) is %d%n%n", s4.compareTo(s3));

   } 
} // end class Scompare03
