//
//  ViewController.swift
//  RushPhoneCall
//
//  Created by Kai Rush on 3/4/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//
/*  Author: Kai Rush
    Purpose: Code to show how to make a phone call directily with in our 
    app.  You cannot test this call feature on the simulator.  The 
    following code is for Xcode 7.3.1 (iOS 9) and I already upgraded my 
    iPhone to iOS 10. Therefore, I will test the RushPhoneCall_iOS10 on 
    my iPhone device  during class to show you how the in-app call 
    feature works.
 */


import UIKit

class ViewController: UIViewController {

    @IBAction func makePhoneCallButtonClicked(sender: UIButton) {
        
        UIApplication.sharedApplication().openURL(NSURL(string: "tel://18157536936")!)
        
        // Display the simple alert since we cannot test the above
        // code on the simulator
        let alertController = UIAlertController(title: "Calling..", message: "1(815)753-6936", preferredStyle: .Alert)
        
        let dismissButton = UIAlertAction(title: "Dismiss", style: .Cancel, handler: {
            
            (alert: UIAlertAction!) -> Void in
        })
        alertController.addAction(dismissButton)
        self.presentViewController(alertController, animated: true, completion: nil)
        
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

