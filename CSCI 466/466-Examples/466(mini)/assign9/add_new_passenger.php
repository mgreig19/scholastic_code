<?php
        /*
        May-Myo Khine
        z1785954

        CSCI 466 Section 2
        Assign 10
        MySQL embedded in php
        Due date: Apr 20, 2017

        Instructor Georgia Brown
        TA Kartheek Chintalapati
        Spring 2017
        */

        require("includes/conn.php");

	echo '<br><h3>Add a New Passenger</h3>';

	echo '<form action="index.php" method="post">';
	echo 'Enter the first name of the passenger:
	<input type="text" name="firstName" id="firstName"><br>';

	echo 'Enter the last name of the passenger:
        <input type="text" name="lastName" id="lastName"><br>';

	echo '<br>';
	echo '<input type = "submit" value = "Add a passenger"><br>';
	echo '</form>';


	if($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$firstName = $_POST['firstName'];
		$lastName = $_POST['lastName'];

		$sql = 'insert into passenger(firstName, lastName)
			values (?,?)';

		try
		{
			$stmt = $conn->prepare($sql);
			$stmt->execute (array($firstName,$lastName));
		}

		catch (PDOException $e)
		{
			echo 'Error. Adding a passenger failed!'.$e->getMessage();
		}

	}
?>
