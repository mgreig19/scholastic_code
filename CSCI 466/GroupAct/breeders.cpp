#include <mysql.h>
#include <iostream>

#define SERVER "courses"
#define USER "z1768935"
#define PASSWORD "1991Apr09"
#define DATABASE "z1768935"

using namespace std;

int main(){

MYSQL *connect, mysql;
connect = mysql_init(&mysql);

connect = mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

if(connect){
MYSQL_RES *res_set;
MYSQL_ROW row;
mysql_query(connect,"select breed_id, name from breed;");
res_set = mysql_store_result(connect);

while((row = mysql_fetch_row(res_set)) != NULL){

cout << row[0]
