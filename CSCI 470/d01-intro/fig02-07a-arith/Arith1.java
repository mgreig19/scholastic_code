// 2c: negative numbers, order of operations, compound assignment

public class Arith1
{
   public static void main(String[] args)
   {   
      System.out.printf("5/3 = %d%n", 5/3);
      System.out.printf("-5/3 = %d%n", -5/3);
      System.out.printf("5/-3 = %d%n%n", 5/-3);

      System.out.printf("5%%3 = %d%n", 5%3);
      System.out.printf("-5%%3 = %d%n", -5%3);
      System.out.printf("5%%-3 = %d%n%n", 5%-3);

      System.out.printf("36/2*3 = %d%n%n", 36/2*3);

      // how simple arith and compound asgt are different
      byte a = 5;
      a += 10;
      // a = a + 10;  illegal assignment

   } 
}
