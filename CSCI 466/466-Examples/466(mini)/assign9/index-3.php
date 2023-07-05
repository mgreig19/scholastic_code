
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
//connect with header file
include("header.html");
 	echo "<h1>Assignment 9</h1>";
        echo "<h2>Flights and Passengers' information</h2>";

//connect the files with the webpage
require("includes/conn.php");
require("includes/list_passenger.php");
require("includes/choose_flight.php");
require("includes/choose_passenger.php");
require("includes/flight_from_origination.php");
?>
