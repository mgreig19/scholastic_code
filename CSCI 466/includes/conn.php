<?php
//Mason Greig
//z1768935
//Assignment 10
//Georgia Brown
//Section 1

//Connection file: This file connects the php 
//files to the mySQL database which holds the data

//Log-in Information
$host = 'courses';
$user = 'z1768935';
$password = '1991Apr09';
$db = 'z1768935';

//Create connection
$conn = new PDO("mysql:host=$host;dbname=$db",$user,$password);

//Error checking
try
{
	$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch (PDOException $e)
{
	echo 'ERROR: '.$e->getMessage();
}
//End of php file
?>
