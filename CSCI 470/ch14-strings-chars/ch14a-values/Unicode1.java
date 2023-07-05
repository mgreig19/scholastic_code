// print some Unicode chars

import java.lang.*;

public class Unicode1
{
   public static void main(String[] args)
   {
      System.out.printf("%n");

      char ch[];
      
      System.out.printf("this is letter e:      \u0065 %n");
      System.out.printf("this is an accented e: \u00E9 %n");
      System.out.printf("this is a smiley face: \u263A %n");

      System.out.printf("attempt to convert Unicode to lower case:");
      System.out.printf(" ");
      
      ch = Character.toChars(0x65);
      System.out.printf("%c%n", ch[0]);
      System.out.printf("%s%n", new String(ch));

      ch = Character.toChars(101);
      System.out.printf("%c%n", ch[0]);

      ch = Character.toChars('e');
      System.out.printf("%c%n", ch[0]);

      ch = Character.toChars(0xE9);
      System.out.printf("%c%n", ch[0]);

      
      System.out.printf("%n");
      
   } 
}
