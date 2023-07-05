// Fig. 7.22a: ArrayEquality
// Arrays class functions and array equality

import java.util.Arrays;

public class ArrayEquality
{
   public static void main(String[] args)
   {
      System.out.printf("%n");

      // sort doubleArray into ascending order
      double[] doubleArray = {8.4, 9.3, 0.2, 7.9, 3.4};
      Arrays.sort(doubleArray); 
      System.out.printf("doubleArray: ");

      for (double value : doubleArray)
         System.out.printf("%.1f ", value);
      System.out.printf("%n%n");

      // fill 10-element array with 7s
      int[] filledIntArray = new int[10]; 
      Arrays.fill(filledIntArray, 7); 
      displayArray(filledIntArray, "filledIntArray");

      // copy array intArray into array intArrayCopy
      int[] intArray = {1, 2, 3, 4, 10, 101};
      int[] intArrayCopy = new int[intArray.length];

      System.arraycopy(intArray, 0, intArrayCopy, 0, intArray.length);
      displayArray(intArray, "intArray");
      displayArray(intArrayCopy, "intArrayCopy");

      // compare intArray and intArrayCopy for equality
      boolean b = Arrays.equals(intArray, intArrayCopy);
      System.out.printf("intArray %s intArrayCopy%n",
         (b ? "==" : "!="));

      // compare intArray and intArrayCopy for equality - v. 2
      b = intArray.equals(intArrayCopy);
      System.out.printf("intArray %s intArrayCopy%n",
         (b ? "==" : "!="));

      // compare intArray and intArrayCopy for equality - v. 3
      b = intArray == intArrayCopy;
      System.out.printf("intArray %s intArrayCopy%n%n",
         (b ? "==" : "!="));

      // search intArray for the value 5
      int location = Arrays.binarySearch(intArray, 5); 
      
      if (location >= 0)
         System.out.printf(
            "Found 5 at element %d in intArray%n", location); 
      else
         System.out.printf("5 not found in intArray%n"); 



      // binary search intArray for the value 8763
      location = Arrays.binarySearch(intArray, 8763);

      if (location >= 0)
         System.out.printf(
            "Found 8763 at element %d in intArray%n", location); 
      else
         System.out.printf("8763 not found in intArray%n%n"); 
   } 

   // function to print array
   public static void displayArray(int[] array, String description)
   {     
      System.out.printf("%s: ", description);
      for (int value : array)
         System.out.printf("%d ", value);
      System.out.printf("%n%n");
   } 
}
