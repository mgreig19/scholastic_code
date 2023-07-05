import static java.lang.Math.*;
import java.io.IOException;
import java.lang.IllegalStateException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// read line w/ scanner, then break it up w/ regex
// doesn't handle empty line at eof properly

public class ReadB
{
  private static Scanner inputFile;

  public static void main(String[] args) throws Exception
  {
    String inputLine;
    String s;
    
    int recordCount = 0;

    int inputNum;
    String inputAlpha;
    
    String inputPatStr = "(\\w+)\\s*(\\d+)";
    Pattern inputPat = Pattern.compile(inputPatStr);

    inputFile = new Scanner(Paths.get("data.txt"));
    
    while (inputFile.hasNext())
      {
        recordCount += 1;
	inputLine = inputFile.nextLine();
	System.out.printf("line is %s%n", inputLine);

	Matcher m = inputPat.matcher(inputLine);

	if (m.find())
	  {
	    inputAlpha = m.group(1);
	    inputNum = Integer.parseInt(m.group(2));
	    System.out.printf("fields are: %s %d%n%n",
			      inputAlpha, inputNum);
	  }
	else
	  System.out.printf("Line is improperly formatted%n%n");
      } // end while
	
    System.out.printf("record count = %d%n%n", recordCount);
    inputFile.close();

  } // end main

} // end ReadB
