// Based on Fig. 17.6: ArrayStream.java

// Demonstrating lambdas and streams with an array of Integers.

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ArrayStream
{
   public static void main(String[] args)
   {
      Integer[] values = {2, 9, 5, 0, 3, 7, 1, 4, 8, 6};

      System.out.println();

      // display original values

      System.out.printf("Original values: %s%n%n", Arrays.asList(values));

      // sort values in ascending order with streams

      System.out.printf("Sorted values: %s%n%n", 
         Arrays.stream(values)
               .sorted()
               .collect(Collectors.toList()));

      // values greater than 4

      List<Integer> greaterThan4 =
         Arrays.stream(values)
               .filter(value -> value > 4)
               .collect(Collectors.toList());
      System.out.printf("Values greater than 4: %s%n%n", greaterThan4);

      // filter values greater than 4 then sort the results

      System.out.printf("Sorted values greater than 4: %s%n%n",
         Arrays.stream(values)
               .filter(value -> value > 4)
               .sorted()
               .collect(Collectors.toList()));

      // greaterThan4 List sorted with streams

      System.out.printf(
         "Values greater than 4 (ascending with streams): %s%n%n",
         greaterThan4.stream()
               .sorted()
               .collect(Collectors.toList()));

   } // end main

} // end class ArrayStream

