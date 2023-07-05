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
        $flight = $_POST["passenger"];
        list($passnum, $firstName, $lastName) = explode("-", $_POST['passenger'],3);

        $sql = "select origination, destination from flight, passenger, manifest
                where flight.flightnum=manifest.flightnum and manifest.passnum=passenger.passnum and passenger.passnum = '$passnum' order by origination";

        $results = 0;

	echo "<h3>$firstName $lastName's flight schedule</h3>";
        foreach($conn->query($sql) as $row)
        {
        echo $row["origination"]." - ".$row["destination"];
        echo '<br>';
        $result++;
        }

        if($result==0)
                echo "This passenger has no flight.";
        echo '<br><br><a href=".."> Back</a>';



?>

