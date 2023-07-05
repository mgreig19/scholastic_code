//
//  ViewController.swift
//  App Name: Stepper
//
//  Created by Mason Greig on 2/6/17.
//
/*
 PURPOSE: To demonstrate the following:
 1.  Create a stepper UI control
 2.  Display the value from the stepper as it increases and decreases.
 2.  Use the stepper value in a computation.
 */

import UIKit

class ViewController: UIViewController {
    
    // MARK: PROPERTIES
    let currentQty = 50  // set current OH qty
    var recQty = 0       // set default for display
    
    // MARK: OUTLETS
    @IBOutlet weak var currentQtyLabel: UILabel!
    @IBOutlet weak var receivedQtyLabel: UILabel!
    @IBOutlet weak var newQtyLabel: UILabel!
    
    // MARK: ACTIONS
    // As the stepper value changes, the received qty
    // label is assigned and displayed.
    @IBAction func qtyStepperClicked(sender: UIStepper) {
        //Convert the received quantity to an UIViewController
        recQty = Int(sender.value) - 1
        receivedQtyLabel.text = "\(recQty)"
    }
    
    // This function is called when the user clicks
    // the Compute New Qty button
    @IBAction func newQtyButtonClicked(sender: UIButton) {
        //Compute and display the new quantity
        let newQty = currentQty + recQty
        newQtyLabel.text = "\(newQty)"
    }
    
    // MARK: viewDidLoad
    // After the app launches, display the current OH Qty
    // and the default (0) received qty.
    override func viewDidLoad() {
        super.viewDidLoad()
        currentQtyLabel.text = "\(currentQty)"
        receivedQtyLabel.text = "\(recQty)"
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
}

