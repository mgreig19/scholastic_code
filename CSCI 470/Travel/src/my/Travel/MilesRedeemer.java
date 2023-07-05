package my.Travel;

//Programmer: Mason Greig
//			Montel Rutherford
//Assignment 2
//This code includes the MilesRedeemer() class which calculates 
//the tickets to be redeemed for the supplied miles balance
//Date due: 2/??/2018


import java.util.*;

//Sourced and modified from Assignment 1 instructions to compare two Destination objects
class MileageComparator implements Comparator<Destination> {

	public int compare(Destination d1, Destination d2) {

		return (d2.getMiles() - d1.getMiles());

	}
}

// This class creates a MilesRedeemer object and performs various calculations
// on user input data which is passed from the main program file

public class MilesRedeemer {

	// Obviously variables
	private ArrayList<Destination> destList = new ArrayList<>();
	private int milesBal = 0;

	private ArrayList<Destination> getDestListObj() {
		
		return destList;
	}
	// Method to build the Destinations object for use in the MilesRedeemer method
	public void readDestinations(Scanner fileScanner) {

		while (fileScanner.hasNext()) {

			// initializing local variables to passed in file data
			String destName = fileScanner.next();
			int normalMiles = fileScanner.nextInt();
			int superMiles = fileScanner.nextInt();
			int upgradeMiles = fileScanner.nextInt();
			int beginMonth = fileScanner.nextInt();
			int lastMonth = fileScanner.nextInt();

			// passing variables to destination class constructor to create a destination
			// object
			destList.add(new Destination(destName, normalMiles, superMiles, upgradeMiles, beginMonth, lastMonth));
		}
		// sorts the destinations based on miles
		destList.sort(new MileageComparator());
		fileScanner.close();
	}

	// gets the city names from the destination object and sorts them alphabetically
	public String[] getCityNames() {

		// initializes the size of the string array to the size of the destList object
		String cities[] = new String[destList.size()];
		int i = 0;

		// assigns the city names stored in the destinations object in a string array
		for (Destination d : destList) {
			cities[i++] = d.getName();
		}

		// sorts the string array alphabetically
		Arrays.sort(cities);
		return cities;
	}
	
	//returns the destination object at the passed in subscript
	public Destination getCityInfo(int subScript){
		
		return getDestListObj().get(subScript);
	}
	
	// This method redeems the passed in miles for tickets
	public ArrayList<String> redeemMiles(int miles, int month) {

		ArrayList<Integer> citiesAvailable = new ArrayList<>();
		ArrayList<String> purchasedTickets = new ArrayList<>();

		// This loop checks for qualifying saver miles tickets and if none are available
		// it continues on to initialize the
		// eligible miles to the normal miles of the flight
		for (int i = 0; destList.size() > i; i++) {

			int eligibleMiles = 0;

			// decision to check whether a person's miles are eligible for the supersaver
			// discount
			if (!(month >= destList.get(i).getStartMonth() && month <= destList.get(i).getEndMonth())) {
				eligibleMiles = destList.get(i).getMiles();
			} else {
				eligibleMiles = destList.get(i).getSaverMiles();
			}
			// After assigning a mile type a city is added to the list as long as the
			// necessary miles are in the balance; the balance is then updated
			if (miles >= eligibleMiles) {
				miles -= eligibleMiles;
				citiesAvailable.add(i);
			}
		}

		// This loop is used to determine if a ticket can be upgraded to first class
		for (int i = 0; citiesAvailable.size() > i; i++) {

			// get the upgrade cost of the ticket
			int upgradeCost = destList.get(citiesAvailable.get(i)).getUpgdeMiles();

			// if the upgrade cost is > than the available miles then an economy class
			// ticket is assigned
			if (upgradeCost > miles) {
				purchasedTickets
						.add("* A trip to " + destList.get(citiesAvailable.get(i)).getName() + " economy class");
			}
			// if there are enough available miles then the program should upgrade the
			// ticket.
			else {
				miles -= upgradeCost;
				purchasedTickets.add("* A trip to " + destList.get(citiesAvailable.get(i)).getName() + " first class");
			}
		}
		// set the milesBal member of the class and return the tickets
		// purchased/available
		setRemainingMiles(miles);
		return purchasedTickets;
	}

	// Accessor methods to the data members of the class
	public int getRemainingMiles() {
		return milesBal;
	}

	private int setRemainingMiles(int newMiles) {
		return (milesBal = newMiles);
	}

}
