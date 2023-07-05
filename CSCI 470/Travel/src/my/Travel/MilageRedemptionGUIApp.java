package my.Travel;
//Programmers: Mason Greig

//			   Montel Rutherford
//Assignment 2
//
//Date due: 2/??/2018
//
//This is the main driver program for Assignment 2
//
//Any collaborator citations are included in the Destination.java file
//

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MilageRedemptionGUIApp {
	
	//the main driver program
	public static void main(String args[]) throws FileNotFoundException {
		
		//if there is an incorrect number of arguments print an error and end program
    		if(args.length != 1) {

			System.out.println("Error: Invalid number of arguments.");
			return;
		}
    		
    		//instance of the destination object
    		MilesRedeemer service = new MilesRedeemer();
    	 	//open and read file using the specified delimiter and store it into scan
  		//then call readDestinations to build the required destinations object
  		try {
  			Scanner scan = new Scanner(new File(args[0])).useDelimiter(";|-|\n");
  			service.readDestinations(scan);
  		}
  		//catches the exception which is produced when the file is not found
  		catch(FileNotFoundException fnf) {
  			System.out.println(fnf + "Error: the file does not exist/was not found.");
  		}
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(travel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(travel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(travel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(travel.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        travel j = new travel(service);
        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                j.setVisible(true);
                j.travelPanel.setVisible(true);
                j.redeemPanel.setVisible(true);
            }
       });

    }
}
