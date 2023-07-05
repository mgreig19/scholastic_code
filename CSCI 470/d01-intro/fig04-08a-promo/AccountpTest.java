// Based on Fig. 3.9: AccountTest.java
// shows function calls and math using promotion
// also shows unprotected input

import java.util.Scanner;

public class AccountpTest
  {
    public static void main(String[] args) 
      {
	// create an account using a double
        Accountp account1 = new Accountp("Jane Green", 50.00);

	// create an account using a float
	// float is passed to the constructor and promoted to double
        Accountp account2 = new Accountp("John Blue", (float)-7.53); 

        // display initial balance of each object
        System.out.printf("%s balance: $%.2f%n",
          account1.getName(), account1.getBalance()); 

        System.out.printf("%s balance: $%.2f%n%n",
          account2.getName(), account2.getBalance()); 

        // create Scanner
        Scanner input = new Scanner(System.in);

        // get a double and add it
	// must cast to float first
        System.out.print("Enter deposit amount for account1: ");
        double depositAmount = input.nextDouble();
        System.out.printf("%nadding %.2f to account1 balance%n%n", 
          depositAmount);
        account1.makeDeposit((float)depositAmount);

        // get a float and add it
        System.out.print("Enter deposit amount for account2: ");
        float depositAmount2 = input.nextFloat();
        System.out.printf("%nadding %.2f to account2 balance%n%n", 
          depositAmount2);
        account2.makeDeposit(depositAmount2);

        // display balances
        System.out.printf("%s balance: $%.2f%n", 
          account1.getName(), account1.getBalance()); 
        System.out.printf("%s balance: $%.2f%n%n",
          account2.getName(), account2.getBalance()); 
      }
  }
