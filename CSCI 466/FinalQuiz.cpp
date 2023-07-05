#include "FinalQuiz.hpp"
/**********************************************
 Name: Mason Greig - z1768935
 
 Last Quiz
 
 Instructor: Georgia Brown
 
 Class: CSCI 466
 
 Semester: Fall
 
 Section: 1
 
 Due: 12/06/2017
 **********************************************/
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
        mysql_query(connect,"select flightnum, origination, destination, miles from flight;");
        //res_set is a temporary file for the results of the query
        res_set = mysql_store_result(connect);
        //while not end of the cursor
        while ((row = mysql_fetch_row(res_set)) != NULL)
        {
            //print information
            cout << "Flightnum: " << row[0]  << "\nOrigination: " << row[1] << "\nDestination: " << row[2]  << "\nTotal Miles: " << row[3] << endl;
            //second query for passengers
            string passenger_query;
            passenger_query = "select firstName, lastName from flight, manifest, passenger where passenger.passnum = manifest.passnum and manifest.flightnum = flight.flightnum and flight.flightnum =";
            
            passenger_query += row[0];
            
            mysql_query(connect, passenger_query.c_str());
            passenger_set = mysql_store_result(connect);
            //while the set isn't empty
            while (( passenger_row = mysql_fetch_row(passenger_set))!= NULL)
            {
                //print the row information
                cout << "\t->" << passenger_row[0] << " " << passenger_row[1] << "\n" << endl;
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
