/**********************************************
Name: Mason Greig - z1768935

Assignment 12:  This assignment uses c++ and php
		to give the user a basic menu from which they can
		choose a few different options which display the associated
		information.

Instructor: Georgia Brown

Class: CSCI 466

Semester: Fall

Section: 1

Due: 12/06/2017
**********************************************/

//required libraries
#include <mysql.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//symbolic constants for accessing mySQL
#define SERVER "courses"
#define USER "z1768935"
#define PASSWORD "1991Apr09"
#define DATABASE "z1768935"

//user input variable
string userChoice;

//main program
int main()
{
    //try to connect to mySQL server
    MYSQL *connect, mysql;
    connect=mysql_init(&mysql);
    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

    //if the connection is successful
    if(connect)
    {
	//variables to hold result of queries and row information from the results
	MYSQL_RES *res_set;
        MYSQL_ROW row;
	//do-while loop which exits when user exits appropiate exit menu entry
	do
	{
		//output menu for user
		cout << "\nMenu options:\n";
		cout << "---------------------\n";
		cout << "H - List all Horses\n\n";
		cout << "R - List all Races\n\n";
		cout << "X - Exit the Program\n\n";
		cout << "Please make a selection: ";
		//user input
		getline(cin, userChoice);

		//if the menu entry is H or h
		if(userChoice == "H" or userChoice == "h")
		{
			//submit query to get horse information
        		mysql_query(connect,"select name, sire, dam from horse order by name;");
			//store query result in res_set
        		res_set = mysql_store_result(connect);
			//information header
			cout << "\nHorse Directory\n";
			cout << "--------------------\n";
        		//information print loop
			while ((row = mysql_fetch_row(res_set)) != NULL)
        		{
            			cout << "Horse: " << row[0]  << "\nSire: " << row[1] << "\nDam: " << row[2] << "\n" << endl;
			}
		}
		//if the menu entry is R or r
		if(userChoice == "R" or userChoice == "r")
                {
			//submit query to get race information
                        mysql_query(connect,"select name, distance from race order by name;");
			//store query result in res_set
                        res_set = mysql_store_result(connect);
			//information header
			cout << "\nRace Directory\n";
                        cout << "--------------------\n";
			//information print loop
                        while ((row = mysql_fetch_row(res_set)) != NULL)
                        {
                                cout << "Race: " << row[0]  << "\nDistance: " << row[1] << "\n" << endl;
                        }
                }
		//if the menu entry is an invalid entry display an error message
		if(userChoice != "X" and userChoice != "x" and userChoice != "R" and userChoice != "r" and userChoice != "H" and userChoice != "h")
		{
			cout << "\nError: Incorrect Menu Entry!\nPlease try again.\n";
		}
	}
	while(userChoice != "X" and userChoice != "x");
	//end of program loop
	cout << endl;

	//clear active query and close connection
        mysql_free_result(res_set);
        mysql_close(connect);
    }
    //if the connection to mySQL fails display an error message
    else
    {
        cout << "Connection Failed! Check your login information\n";
    }
    //end of program
    return 0;
}
