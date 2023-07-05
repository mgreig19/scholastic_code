
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

	echo '<table><th><h3>First Names</h3></th><th><h3>Last Names</h3></th>';

	$sql="select firstName, lastName from passenger order by lastName";
	foreach($conn->query($sql) as $row)
	{
	echo '<tr><td>';
	echo $row["firstName"];
	echo '</td><td>';
	echo $row["lastName"];
	echo '<br>';
	echo '</td></tr>';
	}

	echo '</table>';
?>
