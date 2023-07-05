<?php
/**********************************
Assignment 10 
Mason Greig
CSCI 466
Georgia Brown
Section 1
**********************************/
	//includes and require to start the php file
	include ("includes/raceHeader.html");
	require ("includes/conn.php");
	include ("menu.html");
	//displays the heading of the dropdown search
	echo "<br><br><br>";
	echo "Choose Desired Track Distance<br>";
	echo "<br>";
	//sets sql query statement
	$stmt = "select distance from race group by distance order by distance";
	//create form
	echo '<form name="race" id="race" method="post">';
	echo '<select name="dist">';
	//show the available distances as the options to select in the form
	foreach ($conn->query ($stmt) as $row)
	{
		echo '<option value="';
		echo $row["distance"];
		echo '">';
		echo $row["distance"];
		echo '</option>';
	}
	//end of select 
	echo '</select>';
	//select button to submit query selection
	echo '<br><input type="submit" name="submit" value="Show Track"><br>';
	echo '</form>';
	//end of form

	//if the current server method is a request = POST
	if ($_SERVER['REQUEST_METHOD']=="POST")
	{
		//set track to the name of the select
		$dist = $_POST['dist'];
		//set select statement query
		$stmt = "select name from race where distance = '$dist' group by name";
		//print out the results of the search
		echo "<br>Available ".$dist." races are located at :<br><br>";
		echo '<table border="1">';
		echo '<tr><th>';
		echo "Track Names";
		echo '</th></tr><br>';
		foreach ($conn->query ($stmt) as $row)
		{
			//print the found results on screen
			echo '<tr><td>';
			echo $row['name'];
			echo '</td></tr>';
		}
		echo '</table>';
	}
	//include closing footer file
	include ("includes/footer.html");
//end of php file
?>
