//Programmers: Mason Greig

//			   Montel Rutherford
//Assignment 2
//
//Date due: 2/??/2018
//
//This is the GUI program source code
//It builds the user interface window application
//

package my.Travel;

import java.util.ArrayList;

import javax.swing.*;

//gui class
public class travel extends javax.swing.JFrame {

	// gui class variables to handle the passing of the MilesRedeemer class argument
	// and the creation of the month string array to hold months
	private MilesRedeemer destAvailable = new MilesRedeemer();
	public String[] travelMonth = getMonthStrings();
	// Variables declaration for gui pieces
	public javax.swing.JList<String> cityList;
	private javax.swing.JTextField inputText;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JLabel jLabel4;
	private javax.swing.JLabel jLabel5;
	private javax.swing.JLabel jLabel6;
	private javax.swing.JLabel jLabel7;
	private javax.swing.JLabel jLabel8;
	private javax.swing.JLabel jLabel9;
	private javax.swing.JScrollPane jScrollPane1;
	private javax.swing.JScrollPane jScrollPane2;
	private javax.swing.JTextArea jTextArea1;
	public javax.swing.JTextField milesText;
	private javax.swing.JSpinner monthSpinner;
	public javax.swing.JTextField monthText;
	private javax.swing.JButton redeemButton;
	public javax.swing.JPanel redeemPanel;
	private javax.swing.JTextField remainText;
	public javax.swing.JTextField superText;
	public javax.swing.JPanel travelPanel;
	public javax.swing.JTextField upgradeText;

	// a spinnerList model which is instantiated with the string array of months
	SpinnerListModel pickMonth = new SpinnerListModel(travelMonth);

	// variable to hold the list of destination cities which can be traveled to
	DefaultListModel myModel = new DefaultListModel();

	// constructor for the gui; accepts a MilesRedeemer object as a argument
	public travel(MilesRedeemer destInfo) {
		super.setTitle("Milage Redemption Application");
		setPassedArg(destInfo);
		initComponents();
	}

	/**
	 * This method is called from within the constructor to initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is always
	 * regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")

	// initializes the gui components to their appropiate states when the object is
	// created
	private void initComponents() {

		// initializes the gui variables to their starting states
		// and populated list values
		travelPanel = new javax.swing.JPanel();
		milesText = new javax.swing.JTextField();
		milesText.setEditable(false);
		upgradeText = new javax.swing.JTextField();
		upgradeText.setEditable(false);
		superText = new javax.swing.JTextField();
		superText.setEditable(false);
		monthText = new javax.swing.JTextField();
		monthText.setEditable(false);
		jScrollPane1 = new javax.swing.JScrollPane();
		cityList = new JList<>(myModel);
		jLabel1 = new javax.swing.JLabel();
		jLabel2 = new javax.swing.JLabel();
		jLabel3 = new javax.swing.JLabel();
		jLabel4 = new javax.swing.JLabel();
		jLabel5 = new javax.swing.JLabel();
		redeemPanel = new javax.swing.JPanel();
		inputText = new javax.swing.JTextField();
		remainText = new javax.swing.JTextField();
		remainText.setEditable(false);
		monthSpinner = new javax.swing.JSpinner(pickMonth);
		jScrollPane2 = new javax.swing.JScrollPane();
		jTextArea1 = new javax.swing.JTextArea();
		jTextArea1.setEditable(false);
		jLabel6 = new javax.swing.JLabel();
		jLabel7 = new javax.swing.JLabel();
		jLabel8 = new javax.swing.JLabel();
		redeemButton = new javax.swing.JButton();
		jLabel9 = new javax.swing.JLabel();

		// program ends on window close
		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

		// sets background color and border of gui travelPane
		travelPanel.setBackground(new java.awt.Color(51, 255, 255));
		travelPanel.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0), 3));

		// calls the updateListInfo method
		updateListInfo(getPassedArg());

		// determines the selection of the jList object
		cityList.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
		cityList.setName("");

		// a method which responds to the user clicking on one of the objects in the
		// selection list
		cityList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
			public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
				cityListValueChanged(evt);
			}
		});

		// places the list of available cities into the window panel
		jScrollPane1.setViewportView(cityList);

		// sets the text of the labels for the left side panel of the application window
		jLabel1.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
		jLabel1.setText("List of Destination Cities");

		jLabel2.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel2.setText("Required Miles");

		jLabel3.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel3.setText("Miles for Upgrading");

		jLabel4.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel4.setText("Miles for SuperSaver");

		jLabel5.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel5.setText("Months for SuperSaver");

		// left side panel layout in the application window
		javax.swing.GroupLayout travelPanelLayout = new javax.swing.GroupLayout(travelPanel);
		travelPanel.setLayout(travelPanelLayout);
		travelPanelLayout.setHorizontalGroup(travelPanelLayout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(travelPanelLayout.createSequentialGroup().addGap(25, 25, 25).addGroup(travelPanelLayout
						.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 303, Short.MAX_VALUE)
						.addGroup(travelPanelLayout.createSequentialGroup().addComponent(jLabel1).addGap(0, 0,
								Short.MAX_VALUE))
						.addGroup(javax.swing.GroupLayout.Alignment.TRAILING,
								travelPanelLayout.createSequentialGroup()
										.addGroup(travelPanelLayout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(jLabel2).addComponent(jLabel3).addComponent(jLabel4)
												.addComponent(jLabel5))
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
												javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
										.addGroup(travelPanelLayout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
												.addComponent(monthText, javax.swing.GroupLayout.DEFAULT_SIZE, 153,
														Short.MAX_VALUE)
												.addComponent(upgradeText).addComponent(milesText)
												.addComponent(superText))))
						.addContainerGap()));
		travelPanelLayout.setVerticalGroup(travelPanelLayout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(javax.swing.GroupLayout.Alignment.TRAILING, travelPanelLayout.createSequentialGroup()
						.addGap(27, 27, 27).addComponent(jLabel1)
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
						.addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 221,
								javax.swing.GroupLayout.PREFERRED_SIZE)
						.addGap(18, 18, 18)
						.addGroup(travelPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(jLabel2).addComponent(milesText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
						.addGap(18, 18, 18)
						.addGroup(travelPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(jLabel3).addComponent(upgradeText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
						.addGap(18, 18, 18)
						.addGroup(travelPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(superText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addComponent(jLabel4))
						.addGap(18, 18, 18)
						.addGroup(travelPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(monthText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addComponent(jLabel5))
						.addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)));

		// sets background of the right side panel
		redeemPanel.setBackground(new java.awt.Color(255, 153, 255));
		redeemPanel.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0), 3));

		// sets the size of the jTextArea1 field and places it as a scroll pane
		jTextArea1.setColumns(20);
		jTextArea1.setRows(5);
		jScrollPane2.setViewportView(jTextArea1);

		// the labels which are displayed on the right side of the application
		jLabel6.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel6.setText("Your Accumulated Miles");

		jLabel7.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel7.setText("Month of Departure");

		jLabel8.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
		jLabel8.setText("Your Remaining Miles");

		redeemButton.setText("Redeem tickets >>>");

		jLabel9.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
		jLabel9.setText("Redeem Tickets");

		// calls the redeemButtonClicked method when an action is caught from the button
		redeemButton.addActionListener(e -> {
			redeemButtonClicked();
		});

		// layout of the right side panel in the application window
		javax.swing.GroupLayout redeemPanelLayout = new javax.swing.GroupLayout(redeemPanel);
		redeemPanel.setLayout(redeemPanelLayout);
		redeemPanelLayout.setHorizontalGroup(redeemPanelLayout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(redeemPanelLayout.createSequentialGroup()
						.addGroup(redeemPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
								.addGroup(redeemPanelLayout.createSequentialGroup().addGap(93, 93, 93)
										.addGroup(redeemPanelLayout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(jLabel6).addComponent(jLabel7))
										.addGap(50, 50, 50)
										.addGroup(redeemPanelLayout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(inputText, javax.swing.GroupLayout.PREFERRED_SIZE, 147,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addComponent(monthSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 147,
														javax.swing.GroupLayout.PREFERRED_SIZE)))
								.addGroup(redeemPanelLayout.createSequentialGroup().addGap(154, 154, 154)
										.addComponent(jLabel8)
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
										.addComponent(remainText, javax.swing.GroupLayout.PREFERRED_SIZE, 130,
												javax.swing.GroupLayout.PREFERRED_SIZE))
								.addGroup(redeemPanelLayout.createSequentialGroup().addGap(59, 59, 59).addComponent(
										jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 472,
										javax.swing.GroupLayout.PREFERRED_SIZE))
								.addGroup(redeemPanelLayout.createSequentialGroup().addGap(189, 189, 189).addComponent(
										redeemButton, javax.swing.GroupLayout.PREFERRED_SIZE, 192,
										javax.swing.GroupLayout.PREFERRED_SIZE))
								.addGroup(redeemPanelLayout.createSequentialGroup().addGap(226, 226, 226)
										.addComponent(jLabel9)))
						.addContainerGap(67, Short.MAX_VALUE)));
		redeemPanelLayout.setVerticalGroup(redeemPanelLayout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(redeemPanelLayout.createSequentialGroup().addContainerGap(21, Short.MAX_VALUE)
						.addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 26,
								javax.swing.GroupLayout.PREFERRED_SIZE)
						.addGap(18, 18, 18)
						.addGroup(redeemPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(jLabel6).addComponent(inputText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
						.addGap(18, 18, 18)
						.addGroup(redeemPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(monthSpinner, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addComponent(jLabel7))
						.addGap(34, 34, 34).addComponent(redeemButton).addGap(18, 18, 18)
						.addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 203,
								javax.swing.GroupLayout.PREFERRED_SIZE)
						.addGap(26, 26, 26)
						.addGroup(redeemPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(remainText, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addComponent(jLabel8))
						.addGap(27, 27, 27)));

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGroup(
				javax.swing.GroupLayout.Alignment.TRAILING,
				layout.createSequentialGroup().addContainerGap()
						.addComponent(travelPanel, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
						.addComponent(redeemPanel, javax.swing.GroupLayout.DEFAULT_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
						.addContainerGap()));
		layout.setVerticalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(layout.createSequentialGroup().addContainerGap()
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
								.addComponent(redeemPanel, javax.swing.GroupLayout.DEFAULT_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
								.addComponent(travelPanel, javax.swing.GroupLayout.DEFAULT_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
						.addContainerGap()));

		pack();
	}

	// updates the information which is displayed in the jList object
	// by populating the myModel variable with city names
	public final void updateListInfo(MilesRedeemer listOfCities) {
		String[] cities = new String[listOfCities.getCityNames().length];
		cities = listOfCities.getCityNames();

		for (String city : cities) {
			myModel.addElement(city);
		}
	}

	// This method is called when the redeemButton is clicked
	public void redeemButtonClicked() {
		remainText.setText(null);

		ArrayList<String> travelList = new ArrayList<>();
		int monthNum = 0;

		// store the entered in number into the milesEntered variable
		try {

			int milesEntered = Integer.valueOf(inputText.getText());

			// compares the spinner selected travel month to the values stored in the
			// travelMonth variable; when found, the numeric value of the month's order
			// in the year + 1 (to account for starting at 0) is stored for later use
			String monthSelected = (String) monthSpinner.getValue();
			for (int i = 0; i < travelMonth.length; i++) {
				if (travelMonth[i] == monthSelected) {
					monthNum = i + 1;
				}
			}

			// passes the milesEntered and monthNum variables into the redeemMiles method
			// to get the tickets available for redeeming with the entered miles and
			// month of departure
			travelList = destAvailable.redeemMiles(milesEntered, monthNum);

			// appends strings to the jTextArea1 if the returned ticket list is not empty
			if (!travelList.isEmpty()) {

				// informational text
				jTextArea1.setText("\nYour accumulated miles can be used to redeem the following tickets:\n\n");

				// place each ticket from the ticketList into the jTextArea
				for (String ticket : travelList) {

					jTextArea1.append(ticket);
					jTextArea1.append("\n");
				}
			} else {
				// if the travelList is empty then print an error message
				jTextArea1.setText(
						"\nNo tickets are currently availble to purchase with your available miles balance. \nPlease check back later for more deals!");
			}

			// sets the remainingMiles variable to the amount of remaining miles
			// in the destination object
			String remainingMiles = String.valueOf(destAvailable.getRemainingMiles());
			// place the found value in the associated text field
			remainText.setText(remainingMiles);
		} catch (NumberFormatException e) {
			jTextArea1.setText("\n\nInvaild number entered. Please enter a valid number.");
		}
	}

	// getter method; pass the milesRedeemer class object to the calling method
	public MilesRedeemer getPassedArg() {

		return destAvailable;
	}

	// setter method; sets the class variable to the argument passed in from main
	private void setPassedArg(MilesRedeemer passedDests) {

		destAvailable = passedDests;
	}

	// a method supplied by the professor
	// gets a string array populated by the names of the months
	private String[] getMonthStrings() {

		String[] months = new java.text.DateFormatSymbols().getMonths();
		int lastIndex = months.length - 1;
		if (months[lastIndex] == null || months[lastIndex].length() <= 0) {
			// last item empty
			String[] monthStrings = new String[lastIndex];
			System.arraycopy(months, 0, monthStrings, 0, lastIndex);
			return monthStrings;
		} else {
			// last item not empty
			return months;
		}
	}

	// this method gets the name of the selected city from the jList object
	// and sets the text fields with the information related to the selected object
	private void cityListValueChanged(javax.swing.event.ListSelectionEvent evt) {

		String test = (String) cityList.getSelectedValue();

		for (int i = 0; i < destAvailable.getCityNames().length; i++) {

			if (test.equals(destAvailable.getCityInfo(i).getName())) {
				milesText.setText(String.valueOf(destAvailable.getCityInfo(i).getMiles()));
				superText.setText(String.valueOf(destAvailable.getCityInfo(i).getSaverMiles()));
				upgradeText.setText(String.valueOf(destAvailable.getCityInfo(i).getUpgdeMiles()));
				monthText.setText(travelMonth[destAvailable.getCityInfo(i).getStartMonth() - 1] + " to "
						+ travelMonth[destAvailable.getCityInfo(i).getEndMonth() - 1]);
			}

		}

	}

}
