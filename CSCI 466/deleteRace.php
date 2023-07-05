<?php
/**************************
Assignment 11
Mason Greig
z1768935
Georgia Brown
Section 2

Delete a race: php page
***************************/
//includes files to attach and format it to fit the rest of page
include ("includes/horseHeader.html");
include ("includes/conn.php");
include ("menu.html");
echo '<br>';

//Header which gives directions
echo '<h4>Choose a race name from below and click the Delete button to remove.</h4>';

//initialize and set the query statement
$stmt = "select race_id,name from race";

//beginning of drop down selection list
echo '<form action="deleteRace.php" method="post">';
echo "<table><tr><td>";
echo '<select name="race" id="race">';

//for every successful query add a drop down option
foreach($conn->query($stmt) as $row )
{
	echo "<option value='";
	echo $row['race_id'];
	echo "'>";
	echo $row['name']."</option>";
}
echo '</select>';
echo "</td><td>";
//end of the drop down selection area

//submit button
echo '<input type="submit" value="Delete Race"> </td</tr></table>';
echo '</form>';
//end of the delete form

//if the server is attempting to post
if ($_SERVER['REQUEST_METHOD'] =='POST')
{
	//set race_id to passed in value from the selected query
	$race_ID = $_POST['race'];

	//set the delete query statement
	$deleteStmt = "delete from race where race_id = ?";
	//attempt to inject the delete query into the database
	try
	{
		$stmt = $conn->prepare($deleteStmt);
		$ok = $stmt->execute(array($race_ID));
		echo 'Race '.$race_ID.' has been deleted successfully!';
	}
	//error handling
	catch (PDOException $e)
	{
		echo 'Oops, the race could not be deleted.';
		echo 'Error: ' .$e->getMessage();
	}
}
//includes which supplies the footer file
include ("includes/footer.html");
//end of php file
?>

