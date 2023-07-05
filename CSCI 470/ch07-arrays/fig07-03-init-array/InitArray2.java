// 7.3a: trying to update an initialized array

public class InitArray2
{
   public static void main(String[] args)
   {
      // initializer list specifies the initial value for each element
      int[] array = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
      array[0] = 20;

      for (int counter = 0; counter < array.length; counter++)
         System.out.printf("%5d", array[counter]);
      System.out.printf("%n%n");


      int[] data;
      data = new int[] {10,20,30,40,50,60,71,80,90,91};

      for (int counter = 0; counter < data.length; counter++)
         System.out.printf("%5d", data[counter]);
      System.out.printf("%n%n");

      // data = {10,20,30,40,50,60,71,80,90,91}; - not OK


      int[] data2 = new int[] {10,20,30,40,50,60,71,80,90,91};
   
      for (int counter = 0; counter < data2.length; counter++)
         System.out.printf("%5d", data2[counter]);
      System.out.printf("%n");
   
   }
}

