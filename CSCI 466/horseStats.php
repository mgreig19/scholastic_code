<?php
/**********************************
Assignment 10 
Mason Greig
CSCI 466
Georgia Brown
Section 1
**********************************/
	//includes and require to start the php file
	include ("includes/statHeader.html");
	require ("includes/conn.php");
	include ("menu.html");
	//displays the heading of the dropdown search
	echo "<br><br><br>";
	echo "Choose Desired Horse<br>";
	echo "<br>";
	//sets sql query statement
	$stmt = "select name from horse order by name";
	//create form
	echo '<form name="stat" id="stat" method="post">';
	echo '<select name="horse">';
	//show the available horses as the options to select in the form
	foreach ($conn->query ($stmt) as $row)
	{
		echo '<option value="';
		echo $row["name"];
		echo '">';
		echo $row["name"];
		echo '</option>';
	}
	//end of select
	echo '</select>';
	//select button to submit query selection
	echo '<br><input type="submit" name="submit" value="Show Records"><br>';
	echo '</form>';
	//end of form

	//if the current server method is a request = POST
	if ($_SERVER['REQUEST_METHOD']=="POST")
	{
		//set track to the name of the select
		$horseName = $_POST['horse'];
		//set select statement query
		$stmt = "select r.name, i.tm, i.finish from race r, horse h, runsin i where r.race_id = i.rid and h.horse_id = i.hid and h.name = '$horseName'";
		//print out the results of the search
		echo $horseName.' participated in the races below:<br><br>';
		echo '<table border="2">';
		echo '<tr><th>';
		echo "Track Name";
		echo '</th><th>';
		echo "Race Time";
		echo '</th><th>';
		echo "Place";
		echo '</th></tr>';
		foreach ($conn->query ($stmt) as $row)
		{
			//print the found results on screen
			echo '<tr><td>';
			echo $row['name'];
			echo '</td><td>';
			echo $row['tm'];
			echo '</td><td>';
			echo $row['finish'];
			echo '</td></tr>';
		}
		echo '</table>';
	}
	//include closing footer file
	include ("includes/footer.html");
//end of php file
?>
