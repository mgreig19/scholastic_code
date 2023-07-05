//
//  ViewController.swift
//  RushPhoneCall_iOS10
//
//  Created by Kai Rush on 3/4/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//
/*  Author: Kai Rush
    Purpose: Code to show how to make a phone call directily with in our app.  You cannot test this call feature on the simulator.  I will show you in class how it shows up on my registered iPhone device.
    Note: This is Swift 3.0 code, which runs on Xcode 8.2.1 and tested on
    iPhone with iOS 10.2.1.  Tested on 3/4/2017.
 */

import UIKit

class ViewController: UIViewController {
    
    
    @IBAction func makePhoneCallButtonClicked(_ sender: UIButton) {
        let myURL:NSURL = URL(string: "tel://18157536936")! as NSURL
        UIApplication.shared.open(myURL as URL, options: [:], completionHandler: nil)
        
        // Display the simple alert since we cannot test the above
        // code on the simulator
        let alertController = UIAlertController(title: "Calling..", message: "1(815)753-6936", preferredStyle: .alert)
        
        let dismissButton = UIAlertAction(title: "Dismiss", style: .cancel, handler: {
            
            (alert: UIAlertAction!) -> Void in
        })
        alertController.addAction(dismissButton)
        self.present(alertController, animated: true, completion: nil)
    
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

