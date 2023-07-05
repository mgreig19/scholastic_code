// 2d: math constants

public class Math2
{
   public static void main(String[] args)
   {   
     float f;
     double d;

     // won't compile w/o cast
     f = (float)Math.PI;

     d = Math.PI;
     
     System.out.printf("%npi is approximately %f%n", Math.PI);
     System.out.printf("pi is approximately %.20f%n%n", Math.PI);

     System.out.printf("f is %f%n", f);
     System.out.printf("f is %.20f%n%n", f);

     System.out.printf("d is %f%n", d);
     System.out.printf("d is %.20f%n%n", d);

   } 
}
