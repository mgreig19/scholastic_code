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
	include("../header.html");
        require("conn.php");

        if ( $_SEVER['REQUEST_METHOD']='POST')
        $origination = $_POST["origination"];
        list($flightnum, $origination) = explode("-", $_POST['origination'],2);

        $sql = "select origination, destination from flight where flight.origination = '$origination'";

        $result = 0;

	echo "<h3>Flight out of $origination</h3>";

        foreach($conn->query($sql) as $row)
        {
        echo $row["origination"]." - ".$row["destination"];
        echo '<br>';
        $result++;
        }

        if($result==0)
                echo "This flight go no where";
        echo '<br><a href=".."> Back</a>';

?>
