//
//  Park.swift
//  RushUSNationalParks
//
//  Created by Kai Rush on 2/22/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//

import Foundation

// Initialize properties of the Park class.
class Park {
    var name:String!
    var state:String!
    var visitors:String!
    var hours:String!
    var fee:String!
    var cellImage:String!
    var parkImage:String!
    
    init(name: String, state: String, visitors: String, hours: String, fee: String, cellImage: String, parkImage: String) {
        
        self.name = name
        self.state = state
        self.visitors = visitors
        self.hours = hours
        self.fee = fee
        self.cellImage = cellImage
        self.parkImage = parkImage
    }
    
}