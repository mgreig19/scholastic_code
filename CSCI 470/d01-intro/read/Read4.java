import static java.lang.Math.*;
import java.io.IOException;
import java.lang.IllegalStateException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Read4
{
  private static Scanner inputFile;

  public static void main(String[] args) throws Exception
  {
    String inputLine;
    String s;
    
    int recordCount = 0;

    int inputNum;
    int inputNum2;
    String inputAlpha;
    String inputNumString;
    
    inputFile = new Scanner(Paths.get("data.txt"));

    while (inputFile.hasNext())
      {
        // get alpha
        recordCount += 1;
	inputAlpha = inputFile.next();
        System.out.printf("%nalpha is %s%n", inputAlpha);

	// get number
	if (inputFile.hasNext())
	  {
	    inputNumString = inputFile.next();
	    System.out.printf("numString is %s%n", inputNumString);

	    // have data, now must check for numeric
	    Scanner sc = new Scanner(inputNumString);
	    if (sc.hasNextInt())
	      {
		// two equivalent ways of getting integer value
		inputNum = Integer.parseInt(inputNumString);
		inputNum2 = sc.nextInt();
		System.out.printf("num is %d or %d%n", inputNum, inputNum2);
	      }
	    else
	      System.out.printf("... is not numeric%n");
	  }
	else
          {
	    System.out.printf("file should not end here%n%n");
	    System.exit(1);	  
          }
      }
	
    System.out.println();
    inputFile.close();

  } // end main

} // end Read1
