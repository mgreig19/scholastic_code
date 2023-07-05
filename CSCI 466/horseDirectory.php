<?php
/*************************************
	Assignment 10
	Mason Greig
	z1768935
	Georgia Brown
	CSCI 466
	Section 1
**************************************/

	//includes and require to header, connection, and menu files
	include ("includes/horseHeader.html");
	require ("includes/conn.php");
	include ("menu.html");

	//Table title
	echo "<br><br><br>";
	echo "Horses and Lineage<br>";
	echo "<br>";

	//set sql query to display all horse and track information
	$stmt ='select name, sire, dam from horse order by name';
	//set displayQ to the result of the passed query to the database
	$displayQ = $conn->query ($stmt) or die ("ERROR: " . implode (":", $conn->errorInfo()));
	//Table build and column labels
	echo '<table border="1">';
	echo '<tr><th> ';
	echo 'Horse Name';
	echo '</th><th> ';
	echo 'Sire';
	echo '</th><th> ';
	echo 'Dam';
	echo '</th></tr> ';
	//Table information formatted and then populated by return of query
	while ($row = $displayQ->fetch (PDO::FETCH_ASSOC))
	{
		echo '<tr><td> ';
		echo $row['name'];
		echo '</td><td> ';
		echo $row['sire'];
		echo '</td><td> ';
		echo $row['dam'];
		echo '</td></tr> ';
	}
	echo '</table>';
	//end of table boundry
	//Table title of track information
	echo "<br>";
	echo "Race Tracks and Distance<br>";
	echo "<br>";

	//set sql query
	$stmt = 'select name, distance from race';

	//set displayQ to the return result of the query that was passed to the database
	$displayQ = $conn->query ($stmt) or die ("ERROR: " . implode (":", $conn->errorInfo()));

	//Table start and column labels
	echo '<table border="2">';
	echo '<tr><th> ';
	echo 'Track Name';
	echo '</th><th> ';
	echo 'Distance';
	echo '</th></tr> ';

	//Table formatted and then data from db populates table
	while ($row = $displayQ->fetch (PDO::FETCH_ASSOC))
	{
		echo '<tr><td> '.$row['name'].'</td><td> '.$row['distance'].'</td></tr> ';
	}
	echo '</table>';
	//end of the table
	//include footer file for end of document
	include ("includes/footer.html");
//end of php file
?>
