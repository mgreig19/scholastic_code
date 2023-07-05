// Based on Fig. 3.8: Account.java
// Test promo in math and call

public class Accountp
  {   
    private String name; // instance variable 
    private double balance; // instance variable 

    // constructor
    public Accountp(String name, double balance) 
      {
        this.name = name;
        if (balance > 0.0)
          this.balance = balance;
      }

    // float will be promoted to double to add to balance
    public void makeDeposit(float depositAmount) 
      {      
        if (depositAmount > 0.0)
          balance = balance + depositAmount;

        // could also say: balance += depositAmount;
      }

    public double getBalance()
      {
        return balance; 
      } 

    public void setName(String name)
      {
        this.name = name; 
      } 

   public String getName()
     {
        return name; 
     } 
  }
