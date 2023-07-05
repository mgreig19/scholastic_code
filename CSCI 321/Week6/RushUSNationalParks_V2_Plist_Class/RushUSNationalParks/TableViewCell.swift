//
//  TableViewCell.swift
//  RushUSNationalParks
//
//  Created by Kai Rush on 2/21/17.
//  Copyright © 2017 Kai Rush. All rights reserved.
//

import UIKit

class TableViewCell: UITableViewCell {
    
    @IBOutlet weak var cellIImageView: UIImageView!
    
    @IBOutlet weak var cellTitleLabel: UILabel!
    
    @IBOutlet weak var cellSubTitleLabel: UILabel!
    
    

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
