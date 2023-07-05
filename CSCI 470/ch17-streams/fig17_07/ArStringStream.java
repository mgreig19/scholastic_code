// Based on Fig. 17.7: ArStringStream.java

// Demonstrating lambdas and streams with an array of Strings.

import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Collectors;

public class ArStringStream

{
   public static void main(String[] args)
   {
      String[] strings = 
         {"Red", "orange", "Yellow", "green", "Blue", "indigo", "Violet"};

      // display original strings

      System.out.printf("%nOriginal strings: %s%n%n", Arrays.asList(strings));

      // strings in uppercase

      System.out.printf("strings in uppercase: %s%n%n",
         Arrays.stream(strings)
               .map(String::toUpperCase)
               .collect(Collectors.toList()));

      // strings greater than "m" (case insensitive) sorted ascending

      System.out.printf("strings greater than m sorted ascending: %s%n%n",
         Arrays.stream(strings)
               .filter(s -> s.compareToIgnoreCase("m") > 0)
               .sorted(String.CASE_INSENSITIVE_ORDER)
               .collect(Collectors.toList()));

      // strings greater than "m" (case insensitive) sorted descending

      System.out.printf("strings greater than m sorted descending: %s%n%n",
         Arrays.stream(strings)
               .filter(s -> s.compareToIgnoreCase("m") > 0)
               .sorted(String.CASE_INSENSITIVE_ORDER.reversed())
               .collect(Collectors.toList()));

   } // main

} // end class ArStringStream

