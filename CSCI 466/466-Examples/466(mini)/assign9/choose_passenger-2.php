<?php
	/*
	May-Myo Khine
	z1785954

	CSCI 466 Section 2
	Assign 9
	MySQL embedded in php
	Due date: Apr 14, 2017

	Instructor Georgia Brown
	TA Kartheek Chintalapati
	Spring 2017
	*/

        require("conn.php");



        $sql = 'select * from passenger';
        echo '<h3>Show Passenger\'s Flights</h3>';

        echo '<form action = "includes/choose_passenger_show_flight.php" method = "post">';
        echo '<select name = "passenger">';

        foreach($conn->query($sql) as $row)
        {
        echo '<option value="';
        echo $row["passnum"]."-".$row["firstName"]."-".$row["lastName"];
        echo ' ">';
        echo $row["firstName"]." ".$row["lastName"];
        echo '</option>';
        }

        echo '</select>';
        echo '<br><input type= "submit" name = "submit" value = "show" <br>';
        echo '</form>';

?>

