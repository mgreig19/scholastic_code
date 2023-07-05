<!--------------------------------------------
Assignment 8

Mason Greig
Section 1
Georgia Brown
Fall 2017
Due 11/05/2017
--------------------------------------------->
<html>
<head>
<title>Assignment 8</title>
</head>

<!-- This is the beginning of the content of the web page, which includes a background color, font style and size -->
<body style="background-color:grey; font-family:verdana; font-size:15px">                

<!-- These headers are centered, different colors, and a different size -->
<h2 style="text-align: center; color: green">Mason Greig</h2>
<h3 style="text-align: center; color: blue">Section 1</h3>

<!-- Formatting Line -->
<hr>

<!-- Labeling for class list, set color to orange -->
<h4 style="color: orange">Classes Currently Being Taken</h4>

<!-- Ordered list will be purple colored and will list classes being taken -->
<ol style="color: purple">
<li>Programming in Assembler Language</li>
<li>Databases</li>
<li>Introduction to Software Engineering</li>
<li>Psychopathology</li>
<li>Experimental Cognitive Psychology: Human Learning & Memory</li>
<li>Experimental Cognitive Psychology: Lab</li>
</ol>

<!-- This is the beginning of the first form -->
<form name="DropRadio" id="DropRadio">

<!-- Labeling for the drop down list of classes -->
<h4 style="color: pink">Drop Down List</h4>

<!-- Drop down list of classes being set and ready -->
<select name="Classes">
<option value="Programming in Assembler Language">Programming in Assembler Language</option>
<option value="Databases">Databases</option>
<option value="Introduction to Software Engineering">Introduction to Software Engineering</option>
<option value="Psychopathology">Psychopathology</option>
<option value="Experimental Cognitive Psychology: Human Learning & Memory">Experimental Cognitive Psychology: Human Learning & Memory</option>
<option value="Experimental Cognitive Psychology: Lab">Experimental Cognitive Psychology: Lab</option>
</select><br>
<br><!-- Formatting breaks in the page -->

<!-- Labeling for the radio button selection list --> 
<h4 style="color: red">Current Academic Level</h4>

<!-- Radio selections list being created and set -->
<input type="radio" name=:"EDLVL" id="EDLVL" value="Freshman"> Freshman<br>
<input type="radio" name=:"EDLVL" id="EDLVL" value="Sophomore"> Sophomore<br>
<input type="radio" name=:"EDLVL" id="EDLVL" value="Junior"> Junior<br>
<input type="radio" name=:"EDLVL" id="EDLVL" value="Senior"> Senior<br>
<input type="radio" name=:"EDLVL" id="EDLVL" value="Student-at-large"> Student-at-large<br>
<input type="radio" name=:"EDLVL" id="EDLVL" value="Graduate"> Graduate<br>
</form>
<!-- End of first form -->

<!-- Beginning of second form -->
<form name="ChooseMeal" id="ChooseMeal">

<!-- Labeling for meal choices check boxes -->
<h4 style="color: yellow">Meal Options</h4>

<!-- Check boxes being created and set -->
<input type="checkbox" name="mealtype" value="veggie"> Vegetarian<br>
<input type="checkbox" name="mealtype" value="veggie"> Gluten Free<br>
<input type="checkbox" name="mealtype" value="veggie"> Vegan<br>
<input type="checkbox" name="mealtype" value="veggie"> No Nuts<br>

<!-- Formatting break -->
<br>
<!-- Input text box to enter a name -->
Name: <input type="text" name="studentname" id="studentname">

<br>
<!-- Formatting Breaks -->
<br>

<!-- Cancel and submit buttons -->
<input type="button" value="Cancel">
<input type="submit" value="Submit">
</form>
<!-- End of second form -->

</body>
<!-- End of body of content for webpage -->
<!-- End of html program -->
</html>
