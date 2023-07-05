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

//connect html page to the server base
$host = 'courses';
$user = 'z1785954';
$password='1995Mar02';
$db = 'z1785954';
$options = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8');
$conn = new PDO("mysql:host=$host;dbname=$db",$user,$password);
try
{
  	$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$conn->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
}
catch(PDOException $e)
{
  echo 'ERROR: ' . $e->getMessage();
}
?>
