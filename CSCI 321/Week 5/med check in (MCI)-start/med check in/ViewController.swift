//
//  ViewController.swift
//  med check in
//
//  Created by Kai Rush on 2/10/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {
    
    //Mark connections for outlets to be used in the application
    @IBOutlet weak var dateTextField: UITextField!
    @IBOutlet weak var headachePainLevel: UILabel!
    @IBOutlet weak var HPainLabel: UILabel!
    @IBOutlet weak var chestPainLevel: UILabel!
    @IBOutlet weak var CPainLabel: UILabel!
    @IBOutlet weak var neckPainLevel: UILabel!
    @IBOutlet weak var NPainLabel: UILabel!
    @IBOutlet weak var timeLabel: UILabel!
    @IBOutlet weak var chestPainSlider: UISlider!
    @IBOutlet weak var neckPainSlider: UISlider!
    @IBOutlet weak var headPainSlider: UISlider!
    @IBOutlet weak var checkInTextView: UITextView!
    
    //Mark action functions for button, switches, and sliders
    
    //this function displays a message for the user and the current time to be displayed for the check-in time
    @IBAction func checkedIn(sender: UIButton) {
        let currentTime = NSDate()
        let currentTimeFormatter = NSDateFormatter()
        currentTimeFormatter.timeStyle = .ShortStyle
        currentTimeFormatter.dateStyle = .NoStyle
        checkInTextView.text = "Thank you! Your check-in time is \(currentTimeFormatter.stringFromDate(currentTime)). \nYour doctor will be with you shortly."
    }
    
    //this function makes the labels/slider for the head pain information visiable for use if the switch is on and hides them if off
    @IBAction func headSwitch(sender: UISwitch) {
        if sender.on{
            headachePainLevel.hidden = false
            headPainSlider.hidden = false
            HPainLabel.hidden = false
        }
        else
        {
            HPainLabel.hidden = true
            headachePainLevel.hidden = true
            headPainSlider.hidden = true
        }
    }
    
    //this function sends the value of the slider to the headache pain level label
    @IBAction func headPainSlider(sender: UISlider) {
        let painNum = Int(sender.value)
        headachePainLevel.text = ("\(painNum)")
    }
    
    //this function makes the labels/slider for the neck pain information visiable for use if the switch is on and hides them if off
    @IBAction func neckSwitch(sender: UISwitch) {
        if sender.on{
            NPainLabel.hidden = false
            neckPainSlider.hidden = false
            neckPainLevel.hidden = false
        }
        else{
            NPainLabel.hidden = true
            neckPainLevel.hidden = true
            neckPainSlider.hidden = true
        }
    }
    
    //this function sends the value of the slider to the neck pain level label
    @IBAction func neckPainSlider(sender: UISlider) {
        let painNum = Int(sender.value)
        neckPainLevel.text = ("\(painNum)")
    }
    
    //this function makes the labels/slider for the chest pain information visiable for use if the switch is on and hides them if off
    @IBAction func chestSwitch(sender: UISwitch) {
        if sender.on{
            CPainLabel.hidden = false
            chestPainSlider.hidden = false
            chestPainLevel.hidden = false
        }
        else{
            CPainLabel.hidden = true
            chestPainLevel.hidden = true
            chestPainSlider.hidden = true
        }
    }
    
    //this function sends the value of the slider to the chest pain level label
    @IBAction func chestPainSlider(sender: UISlider) {
        let painNum = Int(sender.value)
        chestPainLevel.text = ("\(painNum)")
    }
    
    
    //Mark: UITextField Delegate methods
    
    // This function dismisses the keyboard when the user taps outside the keyboard surface
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        view.endEditing(true)
    }
    
    // This function dismisses the keyboard when the user presses the Return key on the keyboard
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        dateTextField.resignFirstResponder()
        return true
    }
    
    //sets the format of the date picker to the short style for both the date and time values held in the datepicker and also puts the date string into the dateTextField and the time into the timeLabel to be displayed when a date and time are selected from the date picker
    func datePickerChanged(sender: UIDatePicker){
        let dateFormatter = NSDateFormatter()
        dateFormatter.dateStyle = .ShortStyle
        dateTextField.text = dateFormatter.stringFromDate(sender.date)
        
        let timeFormatter = NSDateFormatter()
        timeFormatter.timeStyle = .ShortStyle
        timeLabel.text = timeFormatter.stringFromDate(sender.date)
        }
    
    //brings up the date picker when the user presses inside the textfield for the date/time selection and calls the datepicker object as the item to use to choose the date and time
    func textFieldDidBeginEditing(textField: UITextField) {
        let datePicker = UIDatePicker()
        textField.inputView = datePicker
        datePicker.addTarget(self, action: #selector(ViewController.datePickerChanged(_:)), forControlEvents: .ValueChanged)
    }
    
    //hides the labels and sliders when the view loads and makes the datetextfield as the first responder so that the date picker generates upon the app opening
    override func viewDidLoad() {
        super.viewDidLoad()
        dateTextField.becomeFirstResponder()
        HPainLabel.hidden = true
        NPainLabel.hidden = true
        CPainLabel.hidden = true
        neckPainLevel.hidden = true
        neckPainSlider.hidden = true
        chestPainLevel.hidden = true
        chestPainSlider.hidden = true
        headachePainLevel.hidden = true
        headPainSlider.hidden = true
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

