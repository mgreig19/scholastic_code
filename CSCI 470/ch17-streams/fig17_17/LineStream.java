// Based on Fig. 17.17: LineStream.java

// Counting word occurrences in a text file.

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;
import java.util.TreeMap;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class LineStream
{
   public static void main(String[] args) throws IOException
   {
      // Regex that matches one or more consecutive whitespace characters

      Pattern pattern = Pattern.compile("\\s+"); 

      System.out.println();

      // count occurrences of each word in a Stream<String> sorted by word

      Map<String, Long> wordCounts = 
         Files.lines(Paths.get("para.txt"))
              .map(line -> line.replaceAll("(?!')\\p{P}", ""))
              .flatMap(line -> pattern.splitAsStream(line))
              .collect(Collectors.groupingBy(String::toLowerCase,
                 TreeMap::new, Collectors.counting()));
      

      // display the words grouped by starting letter

      wordCounts.entrySet()
         .stream()
         .collect(
            Collectors.groupingBy(entry -> entry.getKey().charAt(0), 
               TreeMap::new, Collectors.toList()))
         .forEach((letter, wordList) -> 
            { 
               System.out.printf("%n%C%n", letter);
               wordList.stream().forEach(word -> System.out.printf(
                  "%13s: %d%n", word.getKey(), word.getValue()));
            });


      System.out.println();

      
   } // end main

} // end class LineStream
