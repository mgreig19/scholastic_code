//
//  ViewController.swift
//  RushMapViews_iOS9
//
//  Created by Kai Rush on 3/4/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//
/*  Author: Kai Rush
    Purpose: Use the MapKit and Core Location frameworks
    to display the user's current location and get direction to, in this
    example, the Lincoln Monument, Washington DC.
 
    This app performs the following tasks:
    1.  Shows map in the Standard, Satellite or Hybrid map view.
 
    2.  Asks the user for the permission before displaying the user's
        current location. (See two NSLocation-entries in the Info.plist)
 
        Also, I use the custom location by specifying the latitude and
        longitude of the current location (Westin Georgetown, Washington DC)
        Simulator/Hardware/Location/Custom Location
 
        I used the latlong.net website to get the latitude and longitude
        of an address.
 
    3.  Drops a pin at the Lincoln Monument.  Clicking the pin, display
        the title and subtitle of the location.
 
    4.  Invokes the Apple's map web-application to get direction from the
        user's current location (Westin Georgetown) to the Lincoln Monument.
 
Version 1.0, Xcode 7.3.1 (iOS9).  Tested on simulator, 3/4/2017  ~K. Rush  */

import UIKit
import MapKit           // Added the MapKit.framework
import CoreLocation     // Added the CoreLocation.framework

// Note the CLLocationManagerDelege in the class definition
class ViewController: UIViewController, CLLocationManagerDelegate {

    // MARK: - VARIABLES
    // This variable is needed for setting up the location manager 
    // when the user clicks on the Locate Me button.
    var manager = CLLocationManager()
    
    // MARK: - OUTLETS
    @IBOutlet weak var mapView: MKMapView!
    @IBOutlet weak var mapTypeSegment: UISegmentedControl!
    
    // MARK: - ACTIONS
    
    // This function is called when the user selects the map type
    // on the segmented control.
    @IBAction func mapTypeControl(_ sender: UISegmentedControl) {
        let segIndex = sender.selectedSegmentIndex
        switch segIndex {
        case 0:
            mapView.mapType = MKMapType.standard
        case 1:
            mapView.mapType = MKMapType.satellite
        case 2:
            mapView.mapType = MKMapType.hybrid
        default:
            break
        }
    }
    
/*   This function is called when the user clicks on the Locate Me
     button.  It performs the following tasks:
     1.  Designates the location manager as the delegate.
     2.  Sets the location accuracy to be the best.
     3.  Asks the user for the permission to get his/her current location.
     4.  Once the authorizes, the location manager gets the user location
     and displays the user location on the map view.
 */
    @IBAction func locateMeButton(_ sender: UIBarButtonItem) {
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization()
        manager.startUpdatingLocation()
        mapView.showsUserLocation = true
    }
    
/*  This function performs the following tasks:
     1.  Gets our user location.
     2.  Zooms in that location.
     3.  Displays the region.
*/
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        // Get the user location
        let userlocation:CLLocation = locations[0] as CLLocation
        
        // Do not update the location change
        manager.stopUpdatingLocation()
        
        // Get the latitude and longitude of the user location
        let location = CLLocationCoordinate2D(latitude: userlocation.coordinate.latitude, longitude: userlocation.coordinate.longitude)
        
        // Zoom in equally
        let span = MKCoordinateSpanMake(0.5, 0.5)
        
        // Get the center of the region to show on the map
        let region = MKCoordinateRegion(center: location, span: span)
        
        // Display the region on the map
        mapView.setRegion(region, animated: true)
        
    }

/* This function is called when the user clicks the "Directions" button to instruct this app to invoke the Apple's map web-application to get
    a direction from the user's current location to the Lincoln Monument,
    Washington DC.
 */
    @IBAction func directionsButtonClicked(_ sender: UIBarButtonItem) {
        UIApplication.shared.openURL(URL(string: "http://maps.apple.com/maps?daddr=38.889269,-77.050176")!)
    }
    
    
/*  This function is called after the app launches. Instruct the app
    to perform the following tasks:
    1.  Show a location pin drop at the Lincoln Monument, Washington DC.
        I used the latlong.net website to get the lattidue and longitude
        of the Lincoln Monument.
    2.  Clicking on the dropped pin, display the title and subtitle of
        the location.
 
 */
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let pinLocation: CLLocationCoordinate2D = CLLocationCoordinate2DMake(38.889269, -77.050176)
        let objAnnimation = MKPointAnnotation()
        objAnnimation.coordinate = pinLocation
        objAnnimation.title = "Lincoln Monument"
        objAnnimation.subtitle = "Washington DC, United States"
        self.mapView.addAnnotation(objAnnimation)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

