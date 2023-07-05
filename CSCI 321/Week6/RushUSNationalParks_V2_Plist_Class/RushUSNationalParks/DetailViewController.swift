//
//  DetailViewController.swift
//  RushUSNationalParks
//
//  Created by Kai Rush on 2/21/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController {

    // Outlets to display park image, park name and state name
    @IBOutlet weak var dtvImageView: UIImageView!
    @IBOutlet weak var dtvStateLabel: UILabel!
    @IBOutlet weak var dtvHoursLabel: UILabel!
    @IBOutlet weak var dtvFeeLabel: UILabel!
    
    // Prepare variables to hold data sent from the TableViewController
    var sentData1:String! // park image
    var sentData2:String! // state name
    var sentData3:String! // park hours
    var sentData4:String! // entrance fee
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // Place the sent data into it's appropriate outlets
        dtvImageView.image = UIImage(named: sentData1)
        dtvStateLabel.text = sentData2
        dtvHoursLabel.text = sentData3
        dtvFeeLabel.text = sentData4
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

}
