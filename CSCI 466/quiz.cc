/**********************************************
 Name: Mason Greig - z1768935
 Last Quiz
 Instructor: Georgia Brown
 Class: CSCI 466
 Semester: Fall
 Section: 1
 Due: 12/06/2017
 **********************************************/
//required libraries
#include <stdio.h>
#include <mysql.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//symbolic constants for accessing mySQL
#define SERVER "courses"
#define USER "z1768935"
#define PASSWORD "1991Apr09"
#define DATABASE "z1768935"

//main program
int main(){
    //try to connect to mySQL server
    MYSQL *connect, mysql;
    connect=mysql_init(&mysql);
    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
    if(connect)
    {
        //return value pointer
        MYSQL_RES *res_set, *passenger_set;
        //variable to hold row
        MYSQL_ROW row, passenger_row;
        //run the query
        mysql_query(connect,"select * from breed group by name;");
        //res_set is a temporary file for the results of the query
        res_set = mysql_store_result(connect);
        //while not end of the cursor
        while ((row = mysql_fetch_row(res_set)) != NULL)
        {
            //print information
            cout << "Breed: " << row[1];
            //second query for passengers
            string passenger_query;
            passenger_query = "select dog.name from dog, breed where id =";
            passenger_query += row[1];
            mysql_query(connect, passenger_query.c_str());
            passenger_set = mysql_store_result(connect);
            //while the set isn't empty
            while (( passenger_row = mysql_fetch_row(passenger_set))!= NULL)
            {
                //print the row information
                cout << "\t->" << passenger_row[1] << "\n" << endl;
            }
            cout << endl;
            mysql_free_result(passenger_set);
        }
        //end of while loop
        cout << endl;
        mysql_free_result(res_set);
        mysql_close(connect);
    }
    //end of connection
    //if no connection is made then print an error message
    else
    {
        cout << "Connection Failed! Check your login information\n";
    }
    return 0;
}

