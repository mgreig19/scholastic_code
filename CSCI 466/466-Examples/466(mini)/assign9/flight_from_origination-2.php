
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

        $sql = 'select distinct(origination) from flight';
        echo '<h3>Show the Flights leave from this Origination</h3>';

        echo '<form action = "includes/flight_from_origination_show_flight.php" method = "post">';
        echo '<select name = "origination">';

        foreach($conn->query($sql) as $row)
        {
        echo '<option value="';
        echo $row["flightnum"]."-".$row["origination"];
        echo ' ">';
        echo $row["origination"];
        echo '</option>';
        }

        echo '</select>';
        echo '<br><input type= "submit" name = "submit" value = "show" <br>';
        echo '</form>';

?>

