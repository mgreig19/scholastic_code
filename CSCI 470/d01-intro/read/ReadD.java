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
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;


// read line w/ BufferedReader, then break it up w/ regex
// constant is used to make regex handle Unicode strings

// note that BufferedReader is synchronized
// (although that's not needed here)

public class ReadD
{
  public static void main(String[] args) throws Exception
  {
    BufferedReader br;

    String inputLine;
    String s;
    
    int recordCount = 0;

    int inputNum;
    String inputAlpha;
    
    String inputPatStr = "(\\w+)\\s*(\\d+)";
    Pattern inputPat = Pattern.compile(inputPatStr,
			 Pattern.UNICODE_CHARACTER_CLASS);

    br = new BufferedReader(new InputStreamReader(
	       new FileInputStream(new File("data8.txt")),
			           StandardCharsets.ISO_8859_1));

    inputLine = br.readLine();
    while (inputLine != null)
      {
        recordCount += 1;
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

        inputLine = br.readLine();
	
      } // end while
	
    System.out.printf("record count = %d%n%n", recordCount);
    br.close();
  
  } // end main

} // end ReadD
