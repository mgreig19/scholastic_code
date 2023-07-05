// Displaying formatted lines with method System.out.printf

public class Format1
{
  public static void main(String[] args)
  {
    int i     = 12345;
    double f  = 3.14159;
    boolean b = true;
    String s  = "abcde";

    char c1   = '\u0041';
    char c2   = 'A';
    
    // float g = 3.14;  "possible lossy conversion"
    
    System.out.printf("i: %d %8d %08d %3d%n", i, i, i, i);
    System.out.printf("f: %f %8f %8.4f%n", f, f, f);

    System.out.printf("s: %s %8s %-8s%n", s, s, s);
    System.out.printf("c: %s %s %b %3b%n", c1, c2, c1==c2, b);
    
   } // end method main
} // end class Format1
