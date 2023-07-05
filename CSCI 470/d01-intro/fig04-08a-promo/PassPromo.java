// Fig. 7.13a: PassPromo.java
// Passing promoted items

public class PassPromo
{
   public static void main(String[] args)
   {
       byte b = 3;
       modifyElement(b);
       System.out.printf("b = %d%n", b);
   } 
   
   // multiply argument by 2
   public static void modifyElement(int element)
   {
      element *= 2;
      System.out.printf(
         "Value of element in modifyElement: %d%n", element);
   } 
}
