<?php
/**************************
Assignment 11
Mason Greig
z1768935
Georgia Brown
Section 2

Add a new race: php page
***************************/
//includes files to attach and format it to fit the rest of page
include ("includes/horseHeader.html");
include ("includes/conn.php");
include ("menu.html");
echo '<br>';

echo '<h4>Please enter the following information to add a new race.</h4>';
//This is the start of the text input form
echo '<form name="newRace" id="newRace" action="addRace.php" method="post">';

//new track name input
echo "<label for='rName'>Track Name </label><br>";
echo "<input type='text' name='rName' id='rName' size='35'><br><br>";
//New distance input
echo "<label for='rDist'>Track Distance</label><br>";
echo "<input type='text' name='rDist' id='rDist' size='35'><br><br>";

//clear and submit buttons
echo '<br><input type="reset" value="Clear"> <input type="submit" value="Add Race"><br>';

//end of the input form
echo "</form>";

//beginning of stmt execution
if ($_SERVER['REQUEST_METHOD']=='POST')
{
	//initialize variables to hold the values of text input
	$trackName = $_POST['rName'];
	$trackDist = $_POST['rDist'];

	//initialize and assign a SQL statement variable
	$insertSTMT = "insert into race (name, distance) values (?,?)";

	//attempt to insert the SQL statement into the database
	try
	{
		$stmt = $conn->prepare($insertSTMT);
		$ok = $stmt->execute(array($trackName,$trackDist));
		echo 'The race '.$trackName.' has been added successfully!';
	}
	//error handling
	catch (PDOException $e)
	{
		echo 'Oops, race could not be added.';
		echo 'Error: '.$e->getMessage();
	}
}
//footer of the webpage
include ("includes/footer.html");
?>
