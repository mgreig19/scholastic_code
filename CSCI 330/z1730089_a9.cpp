/****************************************************************
   FILE:      z1730089.cpp
   AUTHOR:    Katia Gomes
   LOGON ID:  Z1730089
   DUE DATE:  Wednesday, April 15

   FUNCTION:  Create a client program for a server
****************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <limits>

using namespace std;

// Functions for error checking
bool nameCheck (string);
bool cardNumCheck (string);
bool exDateCheck (string);
bool amountCheck (string);

int main () {
  string name, cardNum, exDate, amount;	// Holds the user information
  string datagram;			// Data to sent to the server
  char buffer[256];			// Receives data from server
  int echolen, received = 0;		// Length of data sent and receives from server
  unsigned int addrlen;			// Length of server address
  int sockfd;				// Socket file descriptor
  struct addrinfo *res;			// Structure for server address information
  struct sockaddr_in echoserver;	// Structure for server address

  // Greets user and asks for their name or to quit
  cout << "Welcome to the Credit Card transaction verification utility: " << endl << endl;
  cout << "Enter card holder name (or quit): ";
  getline (cin, name);

  // While the user doesn't wish to quit
  while (name.compare("quit") != 0) {
    // While the user hadn't entered a valid name
    while (!nameCheck(name)) {
      cout << "  ... name invalid, try again (enter first and last name): ";	// Asks user for a valid name
      getline (cin, name);
    }

    // Asks user for their credit card number
    cout << "Enter CC number: ";
    getline (cin, cardNum);

    // While the user hadn't entered a valid cardNum
    while (!cardNumCheck(cardNum)) {
      cout << "  ... card number invalid, try again (must contain 15 or 16 digits): ";	// Asks user for a valid cardNum
      getline (cin, cardNum);
    }

    // Asks user for their credit card expiration date
    cout << "Enter expiration: ";
    getline (cin, exDate);

    // While the user hadn't entered a valid exDate
    while (!exDateCheck(exDate)) {
      cout << "  ... expiration date invalid, try again: ";	// Asks user for a valid exDate
      getline (cin, exDate);
    }

    // Asks user for the amount they wish to withdraw
    cout << "Enter amount: ";
    getline (cin, amount);

    // While the user hadn't entered a valid amount
    while (!amountCheck(amount)) {
      cout << "  ... amount invalid, try again (minimum 0.01): ";	// Asks user for a valid amount
      getline (cin, amount);
    }

    // Constructing datagram to send to server
    datagram = cardNum + ":" + exDate + ":" + amount + ":" + name;

    if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) < 0) {	// Creates UDP socket
      perror ("Failed to create socket");
      exit (-1);
    }

    // Error check
    getaddrinfo("hopper.cs.niu.edu", NULL, NULL, &res);

    struct sockaddr_in *addr = (struct sockaddr_in *) res->ai_addr;	// Gets addresss information

    memset (&echoserver, 0, sizeof(echoserver));	// Clear structure
    echoserver.sin_family = AF_INET;			// IP
    echoserver.sin_addr = addr->sin_addr;		// IP Address
    echoserver.sin_port = htons(4445);			// Server port

    // Sends message to the server
    echolen = datagram.size();
    if (sendto (sockfd, datagram.c_str(), echolen, 0, (struct sockaddr *) &echoserver, sizeof(echoserver)) != echolen) {
      perror ("Mismatch in number of sent bytes");
      exit (-1);
    }

    // Receives message back from the server
    addrlen = sizeof (echoserver);
    received = recvfrom (sockfd, buffer, 256, 0, (struct sockaddr *) &echoserver, &addrlen);

    buffer[received] = '\0';	// Assures null-terminated string

    cout << buffer << endl << endl;	// Displays message from the server

    // Asks user to enter their name or quit
    cout << "Enter card holder name (or quit): ";
    getline (cin, name);
  }

  return 0;
}

/****************************************************************
   FUNCTION:   bool nameCheck (string)

   ARGUMENTS:  A string with the name to check

   RETURNS:    True if the name passes every error check,
		otherwise false

   NOTES:      Checks the the user has entered a valid name
****************************************************************/
bool nameCheck (string name) {
  size_t found;

  // Makes sure the size of the name isn't more than 64 characters
  if (name.size() > 65)
    return false;

  // Finds if there is a space within the name string
  found = name.find_first_of(" ");

  // If there isn't a space, the user didn't enter a first and last name
  if (found == string::npos)
    return false;

  return true;
}

/****************************************************************
   FUNCTION:   bool cardNumCheck (string)

   ARGUMENTS:  A string with the credit card number to check

   RETURNS:    True if the card number passes every error check,
                otherwise false

   NOTES:      Checks the the user has entered a valid creit card number
****************************************************************/
bool cardNumCheck (string card) {
  int count = 0;
  size_t found;

  // Makes sure the card number only contains numbers and spaces
  found = card.find_first_not_of("1234567890 ");
  if (found != string::npos)
    return false;

  // Counts the number of digits in the card number
  for (unsigned int i = 0; i < card.size(); i++) {
    if (isdigit(card[i]))
      count++;
  }

  // Makes sure the card number contains either 15 or 16 digits
  if (count != 15 && count != 16)
    return false;

  return true;
}

/****************************************************************
   FUNCTION:   bool exDateCheck (string)

   ARGUMENTS:  A string with the expiration date to check

   RETURNS:    True if the expiration date passes every error check,
                otherwise false

   NOTES:      Checks the the user has entered a valid expiration date
****************************************************************/
bool exDateCheck (string date) {
  string month, year;
  size_t found;

  // Makes sure the date only contains numbers and a /
  found = date.find_first_not_of("1234567890/");
  if (found != string::npos)
    return false;

  // Makes sure there is a / seperating a month and year
  found = date.find ("/");
  if (found == string::npos)
    return false;
  else {
    month = date.substr(0, found);  // Gets month from date string
    year = date.substr(found+1);    // Gets year from date string
  }

  // If they only entered a single digit for the month
  if (month.size() == 1)
    month.insert(0, "0");	// Inserts a zero before it

  else if (month.size() != 2)	// Makes sure the month is two digits
    return false;

  // Makes sure the month is 1 - 12
  if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
    return false;

  // If they only enter two digits for the year
  if (year.size() == 2)
    year.insert(0, "20");	// Inserts "20" before those two digits

  else if (year.size() != 4)	// Makes sure the year is four digits
    return false;

  // Makes sure the year is after 2014 since we are in 2015
  if (atoi(year.c_str()) <= 2014)
    return false;

  return true;
}

/****************************************************************
   FUNCTION:   bool nameCheck (string)

   ARGUMENTS:  A string with the amount to check

   RETURNS:    True if the amount passes every error check,
                otherwise false

   NOTES:      Checks the the user has entered a valid amount
****************************************************************/
bool amountCheck (string amount) {
  size_t found;

  // Makes sure the amount only contains number and a .
  found = amount.find_first_not_of("1234567890.");
  if (found != string::npos)
    return false;

  // Makes sure the size of amount holds at least four characters
  if (amount.size() > 3) {
    if (amount.at(amount.size()-3) != '.')  // Makes there are two places after the decimal
      return false;
  }
  else
    return false;

  // Makes sure the amount entered by the user isn't less than 0.01
  if (atof(amount.c_str()) < 0.01)
     return false;

  return true;
}
