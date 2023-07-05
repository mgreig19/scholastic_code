// Fig. 17.19: RandIntStream.java

// Rolling a die 6,000,000 times

import java.security.SecureRandom;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class RandIntStream
{
   public static void main(String[] args)
   {
      SecureRandom random = new SecureRandom();

      // roll a die 6,000,000 times and summarize the results

      System.out.printf("%n%-6s%s%n", "Face", "Frequency");

      random.ints(6_000_000, 1, 7)
            .boxed()
            .collect(Collectors.groupingBy(Function.identity(),
               Collectors.counting()))
            .forEach((face, frequency) -> 
               System.out.printf("%4d%10d%n", face, frequency));

      System.out.println();

   } // end main

} // end class RandIntStream
