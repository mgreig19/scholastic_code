//
//  TableViewController.swift
//  RushUSNationalParks
//
//  Created by Kai Rush on 2/21/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//
//  Author: Kai Rush
//  Swift 2.0, iOS 9
//
//  Purpose: To demonstrate the following concepts:
//  - Read data from a property list
//  - Create a Foundation class to hold its properties
//  - Passing data from a tableview controller
//  (UITableViewController) to a detail viewcontroller (UIViewController)
//


import UIKit

class TableViewController: UITableViewController {

    var parkObject = [Park]() // Instantial an object of the Park class

    override func viewDidLoad() {
        super.viewDidLoad()
        
        readPropertyList()
        
    }

    //This function finds the property list, read each dictionary entries (properties)
    // in the plist arrray, and append initalize the object protperies in the Park class.
    func readPropertyList() {
        let path = NSBundle.mainBundle().pathForResource("Top3Parks_Plist", ofType: "plist")!
        let parkArray:NSArray = NSArray(contentsOfFile:path)!
        
        for dictionary in parkArray {
            let park_name = dictionary["parkName"] as! String
            let park_state = dictionary["state"] as! String
            let annual_visitors = dictionary["visitors"] as! String
            let park_hours = dictionary["parkHours"] as! String
            let entrance_fee = dictionary["fee"] as! String
            let cell_image = dictionary["cell_image"] as! String
            let park_image = dictionary["park_image"] as! String
            
            parkObject.append(Park(name: park_name, state: park_state, visitors: annual_visitors, hours: park_hours, fee: entrance_fee, cellImage: cell_image, parkImage: park_image))
            
        }
        
    }
    
    
    // MARK: - Table view data source

    // We have one section in our tableview
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }

    // The number of rows in our table = number of items in our array list
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return parkObject.count     // return the number of objects in the Park class
    }

    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        // Allocate our table view cell with our TableViewCell class
        let park:Park = parkObject[indexPath.row]
        
        let cell:TableViewCell = tableView.dequeueReusableCellWithIdentifier("CELL") as! TableViewCell

        // Place cell image, park name and annual visitors in the table cell
        let cellImageName = UIImage(named: park.cellImage)
        cell.cellIImageView.image = cellImageName
        cell.cellTitleLabel.text = park.name
        cell.cellSubTitleLabel.text = park.visitors

        return cell
    }
        
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if (segue.identifier == "DetailView") {
            let destVC = segue.destinationViewController as! DetailViewController
            
            // Prepare to send data to the DetailViewController
            if let indexPath = self.tableView
                .indexPathForSelectedRow {
                
               let park:Park = parkObject[indexPath.row]

                destVC.navigationItem.title = park.name
                destVC.sentData1 = park.parkImage
                destVC.sentData2 = park.state
                destVC.sentData3 = park.hours
                destVC.sentData4 = park.fee
               
            }
        }
    }
    

}
