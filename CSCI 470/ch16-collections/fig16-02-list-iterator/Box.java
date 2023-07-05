
import java.lang.Integer;

public class Box
  {
    public static void main(String[] args)
      {
	int i;
	int j;
	i = 3;
	j = new Integer(i);
	System.out.printf("Value is %d%n", j);
	
	j = new Integer(i).intValue();
	System.out.printf("Value is %d%n", j);

      } // end main
  
  } // end class Box
