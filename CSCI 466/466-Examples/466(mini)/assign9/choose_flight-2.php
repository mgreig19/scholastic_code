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

	$sql = 'select * from flight';
	echo '<h3>Show Flight\'s Passengers</h3>';

	echo '<form action = "includes/choose_flight_show_passenger.php" method = "post">';
	echo '<select name = "flight">';

        foreach($conn->query($sql) as $row)
        {
	//drop box
        echo '<option value="';
	//which is passed
        echo $row["flightnum"]."-".$row["origination"]."-".$row["destination"];
	echo ' ">';
	//which will show
	echo $row["origination"]."-".$row["destination"];
	echo '</option>';
        }

	echo '</select>';
	//show button
	echo '<br><input type= "submit" name = "submit" value = "show" <br>';
	echo '</form>';

?>
