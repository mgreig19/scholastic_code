// based on Fig. 7.13a: PassPromo.java
// ambiguous passing of promoted items

public class PromoAmbig
{
   public static void main(String[] args)
   {
       byte b = 3;
       modifyElement(b);
       System.out.printf("b = %d%n", b);
   } 
   
  /*
  // multiply argument by 2
   public static void modifyElement(int element)
   {
      element *= 2;
      System.out.printf(
         "Int in modifyElement: %d%n", element);
   } 
  */
  
   // another multiply argument by 2
   public static void modifyElement(long element)
   {
      element *= 2;
      System.out.printf(
         "Long in modifyElement: %d%n", element);
   } 
}
