<?php
/**************************
Assignment 11
Mason Greig
z1768935
Georgia Brown
Section 2

Add a new horse: php page
***************************/
//includes files to attach and format it to fit the rest of page
include ("includes/horseHeader.html");
include ("includes/conn.php");
include ("menu.html");
echo '<br>';

echo '<h4>Please enter the following information to add a new horse.</h4>';
//This is the start of the text input form
echo '<form name="newHorse" id="newHorse" action="addHorse.php" method="post">';

//new horse name input
echo "<label for='hName'>Horse Name </label><br>";
echo "<input type='text' name='hName' id='hName' size='35'><br><br>";

//New sire name input
echo "<label for='hSire'>Sire Name</label><br>";
echo "<input type='text' name='hSire' id='hSire' size='35'><br><br>";

//New dam name input
echo "<label for='hDam'>Dam Name</label><br>";
echo "<input type='text' name='hDam' id='hDam' size='35'><br><br>";

//clear and submit buttons
echo '<br><input type="reset" value="Clear"> <input type="submit" value="Add Horse"><br>';

//end of the input form
echo "</form>";

//beginning of stmt execution
if ($_SERVER['REQUEST_METHOD']=='POST')
{
	//initialize variables to hold the values of text input
	$horseName = $_POST['hName'];
	$sireName = $_POST['hSire'];
	$damName = $_POST['hDam'];

	//initialize and assign a SQL statement variable
	$insertSTMT = "insert into horse (name, sire, dam) values (?,?,?)";

	//attempt to insert the SQL statement into the database
	try
	{
		$stmt = $conn->prepare($insertSTMT);
		$ok = $stmt->execute(array($horseName,$sireName,$damName));
		echo 'Horse '.$horseName.' has been added successfully!';
	}
	//error handling
	catch (PDOException $e)
	{
		echo 'Oops, Horse could not be added.';
		echo 'Error: '.$e->getMessage();
	}
}
//footer of the webpage
include ("includes/footer.html");
?>
