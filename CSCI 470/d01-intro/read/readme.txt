What Scanner cares about (numeric) and what Scanner does not care
  about (correct line format)

The expected format of the pgm is an alpha + a number on each line.

Read1.java - shows two ways to check for numeric before using a number

ReadA.java shows that Java will accept a bad file
- same as Read1 except that it uses data3.txt

--

Try/catch required for file open, not for keyboard use

Read2.java - shows that try/catch is not required when the input comes
from the keyboard instead of from a file
- in fact, try/catch can't be used w/ keyboard input
- same as Read1.java except for KB input

Read3.java - shows how to throw an exception for problems opening the
file. Gives NoSuchFileException.
- same as Read1.java except for 'throws' instead of try/catch
  and different input file
   
--

Throwing exceptions is the lazy approach

Read4.java - throws exception for bad file formatting. Generally not a
good idea because it's better to have more specific errors.
(used in class as example of exceptions 10/10/2017)

--

Two ways to check for numeric throw 2 different exceptio

Read5.java - another version of Read1.java used for future
  experiments (separates 2 ways of converting to numeric)

Read6.java - parseInt throws NumberFormatException
- same as Read5.java but does not check for numeric before
  calling parseInt

Read7.java - nextInt (NoSuchElementException) error handled by
  try/catch
- same as Read5.java but does not check for numeric before
  calling nextInt

Read6 and Read7 show that the 2 different ways of converting string
  to number fail differently if the input is not numeric

--

Two kinds of line formatting errors and how to check for them

Read8.java - "next" error (NoSuchElementException) handled by
  try/catch
- same as Read7 but uses data2.txt instead of data.txt

Read7 and Read8 show that there are 2 kinds of malformed files:
  wrong type of value on a line and wrong number of values on a line

--

ReadB - Scanner + regex
doesn't handle empty line at eof properly

ReadC - BufferedReader + regex
reads Ascii file as UTF8
works because Ascii is a subset of UTF8

ReadC0
reads Ascii file, no encoding specified
so it defaults to encoding specified by operating system locale
works regardless of locale (i.e., whether we choose UTF8 or not)
  because Ascii is a subset of UTF8

--

data8.txt is an ISO-8859-1 file

ReadC1 is the same as ReadC but it reads data8.txt
fails because the regex can't handle non-Ascii chars

ReadE correctly opens data8.txt as ISO-8859-1
it correctly handles the regex
it has unnecessary p{ALPHA}
it works correctly

ReadD correctly opends data8.txt as ISO-8859-1
it correctly handles the regex
it works correctly

