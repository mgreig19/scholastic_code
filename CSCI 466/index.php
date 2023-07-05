<?php
	include ("includes/header.html");
	require ("includes/conn.php");
	echo "Horses and Lineage<br>";
	$stmt ='select name, sire, dam from horse order by name'; 
	$displayQ = $conn->query ($stmt) or die ("ERROR: " . implode (":", $conn->errorInfo()));
	echo '<table border="1">';
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
	$stmt = 'select name, distance from race';
	$displayQ = $conn->query ($stmt) or die ("ERROR: " . implode (":", $conn->errorInfo()));
	echo '<table border="2">';
	while ($row = $displayQ->fetch (PDO::FETCH_ASSOC))
	{
		echo '<tr><td> '.$row['name'].'</td><td> '.$row['distance'].'</td></tr> ';
	}
	echo '</table>';
	include ("includes/footer.html");
?>
