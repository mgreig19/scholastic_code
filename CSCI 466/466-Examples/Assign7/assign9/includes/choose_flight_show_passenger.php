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
	include("../header.html");
	require("conn.php");

	if ( $_SEVER['REQUEST_METHOD']='POST')
	//post variable
	$flight = $_POST["flight"];
	//get split into three variables
	list($flightnum, $origination, $destination) = explode("-", $_POST['flight'],3);

	$sql = "select firstName, lastName from flight, passenger, manifest
		where flight.flightnum=manifest.flightnum and manifest.passnum=passenger.passnum and flight.flightnum = '$flightnum' order by lastName";

	$results = 0;

	//header line to show up
	echo "<h3>Passengers on the flight ( $origination - $destination)</h3>";

	//for loop to show names
	foreach($conn->query($sql) as $row)
        {
        echo $row["firstName"]." ".$row["lastName"];
	echo '<br>';
	$result++;
        }

	//error msg
	if($result==0)
		echo "No passenger on this flight";
	//return to the previous link
	echo '<br><br><a href=".."> Back</a>';



?>
