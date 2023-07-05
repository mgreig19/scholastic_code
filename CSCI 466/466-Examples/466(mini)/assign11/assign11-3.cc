/*
	May-Myo Khine
	z1785954

	CSCI 466 Section 2
	Assign 11
	MySQL embedded in c++
	Due date: Apr 28, 2017

	Instructor Georgia Brown
	TA Kartheek Chintalapati
	Spring 2017
*/

#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;

#define SERVER "courses"
#define USER "z1785954"
#define PASSWORD "1995Mar02"
#define DATABASE "z1785954"

int main()
{

    MYSQL *connect, mysql;
    connect=mysql_init(&mysql); // Initialize the instance
    //log in and connect to the database
    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
    if(connect)
    {
        MYSQL_RES *res_set; /* Create a pointer to receive the return value.*/
        MYSQL_ROW row; /* Assign variable for rows. */
	MYSQL_RES *passenger_set;
	MYSQL_ROW passenger_row;

        mysql_query(connect,"select flightnum, origination, destination, miles from flight;");
	/*run the query*/

        res_set = mysql_store_result(connect); /*res_set is a temporary file for the results of the query, a cursor*/

        while ((row = mysql_fetch_row(res_set)) != NULL)  /*while not end of the cursor */
        {
            cout << "Flightnum: " << row[0]  <<
		"\nOrigination: "<< row[1] << "\nDestination: "<< row[2]  <<
		"\nTotal Miles: "<< row[3] << endl; /* print the items in the row */

	//second query for passengers
	string passenger_query;
	passenger_query="select firstName, lastName from flight, manifest,passenger where passenger.passnum = manifest.passnum and flight.flightnum = manifest.flightnum and flight.flightnum= ";

	passenger_query += row[0];
	mysql_query(connect, passenger_query.c_str());
	passenger_set = mysql_store_result(connect);
	int passenger_count = 0 ;

	while (( passenger_row=mysql_fetch_row(passenger_set))!= NULL)
	{
		cout << "\t->" << passenger_row[0]<< " " <<passenger_row[1]<< endl;
		passenger_count +=1;

	}

	cout << "\tTotal Passengers:" <<passenger_count <<endl;
        mysql_free_result(passenger_set);
        cout << endl;

	}//end while resset
        cout << endl;
        mysql_free_result(res_set);
        mysql_close(connect);
    } //end if connect
    else
    {
        cout << "Connection Failed! Check your login information\n";
    }
     return 0;
}
