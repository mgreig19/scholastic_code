// extension of Fig. 2.6: Welcome4.java
// Displaying multiple lines with method System.out.printf
// and other output functions

public class Welcome4a
{
   // main method begins execution of Java application
   public static void main(String[] args)
   {
       System.out.print("Welcome to ");
       System.out.println("Java Programming!");

       System.out.println("Welcome\nto\nJava\nProgramming!");
       
       System.out.printf("%s%n%s%n",          
         "Welcome to", "Java Programming!");

   } // end method main
} // end class Welcome4a
