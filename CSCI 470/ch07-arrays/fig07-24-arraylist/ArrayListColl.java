// Fig. 7.24: ArrayListColl.java

// Generic ArrayList collection demonstration.

import java.util.ArrayList;

public class ArrayListColl
{
   public static void main(String[] args)
   {

     System.out.printf("%n");  // improve readability on screen

     // create a new ArrayList of Strings with an initial capacity of 10
      ArrayList<String> items = new ArrayList<String>(); 

      items.add("red"); // append an item to the list          
      items.add("yellow"); // add "yellow" to the end of the list      
      items.add("green"); // add "green" to the end of the list
      items.add("yellow"); // add "yellow" to the end of the list      
      items.remove("yellow"); // remove the first "yellow"

      
      // ArrayList is a useful way to keep track of a pile of items
      // to do that, do not use specific subscripts like this
      // items.add(0, "yellow"); // insert "yellow" at index 0
      // items.remove(1); // remove item at index 1


      // if you just need to know whether something is in a pile of
      // items and don't need the index value, you don't need to do this
      // display the colors in the list
      // for (int i = 0; i < items.size(); i++)
      //   System.out.printf("%s ", items.get(i));

      // display colors using enhanced for
      for (String item : items)
         System.out.printf("%s ", item);
      System.out.printf("%n%n");
      
      // check if a value is in the List
      System.out.printf("red is %sin the list%n%n",
         items.contains("red") ? "": "not ");

      // display number of elements in the List
      System.out.printf("Size: %s%n%n", items.size());

   } // end main

} // end class ArrayListColl
