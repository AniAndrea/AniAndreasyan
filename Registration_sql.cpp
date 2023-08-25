#include "/usr/include/mysql/mysql.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <mysql.h>
#include <cstdlib>
#include <ctime>
//#include "utils/Utils.h"

using namespace std;

int  login();
void forgot();
void firstpage();
void firstpage_two();
void profile();
int registration();
string generateID();
string RuserName;

int  main()
{
//string RuserName;
	cout<<"\t\t\t ___________________________________ \n";
	cout<<"\t\t\t ***             WELCOME!        *** \n";
	cout<<"\t\t\t    ______________________________   \n";
	cout<<"\t\t\t     Used Oil Management Programm    \n\n";
firstpage();
}
void firstpage() {	
	int a;	
	cout<<"\t * Press 1 to Login    "<<endl;
	cout<<"\t * Press 2 to Registor "<<endl;
	cout<<"\t * Press 3 if you forgot your password "<<endl;
	cout<<"\t * Press 4 to EXIT \n\n";
	cout<<"\t Enter your  choise: ";
	cin>>a;
	cout<<endl;

	switch(a)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t Thank you! \n\n";
			break;
		default:
			cout<<"\x1B[2J\x1B[H";
			cout<<"\t\t\t Select  from the options given above \n";
			firstpage();
	}
}

void firstpage_two() {
        int a;
        cout<<"\t * Press 1 to Login    "<<endl;
        cout<<"\t * Press 2 to EXIT \n\n";
        cout<<"\t Enter your  choise: ";
        cin>>a;
        cout<<endl;

        switch(a)
        {
                case 1:
                        login();
                        break;
                case 2:
                        cout<<"\t\t\t Thank you! \n\n";
	      		break;
        }
}


void profile(){
	cout<<"\t\t\t\t --------- Hello!--------- \n\n";
	cout<<"\t\t\t\t  Here is your Profile \n\n\n"; }
// ___________________________________________________________ //

string generateID(){

    string ID;
	srand(time(0));
	int random=rand()%1000;
	string str=to_string(random);
	ID=RuserName+str;
	//std::cout<<random<<std::endl;
return ID;
}
// _________________________________________________________________ //


int   registration()
{
	string RestName, RPassword, Address, Email; 
        int a;
        char userrole[20]="User";
	cout<<"\x1B[2J\x1B[H";
        
	cout<<"\t\t\t Create a USERNAME: "<<endl;
        cout<<"\t\t\t _ ";
        cin>>RuserName;
// ************************ //
	
	char server[30] = "sql6.freesqldatabase.com";
        char username[25] = "sql6642308";
        char password[25] = "ZL9cx52cPH";
        char database[25] = "sql6642308";

    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, database, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    if(mysql_query(conn, "SELECT * FROM USER")) {
	    cout<<"Unable to  connect with MySQL server\n";
	    mysql_close(conn);
	    return 1;}
	
	
	MYSQL_RES *result = mysql_store_result(conn);
    	if (result == NULL) {
	 cout << "Result fetching error." <<endl;
       mysql_close(conn);
        return 1; 
    }
	 int num_fields = mysql_num_fields(result);
         MYSQL_ROW row;
    	 while ((row = mysql_fetch_row(result))) {
        	for (int i = 0; i < num_fields; ++i) {
            	if (RuserName==row[i]) {
                cout << "\t\t\t This username already exist! Try again! "<<endl;
		cout<<"\t\t\t __ ";
		cin>>RuserName;
            	}
        }
    }

    mysql_free_result(result);
    mysql_close(conn);
        	
// ************************* //
	cout<<"\n\n\t\t\t Enter your public food place name: "<<endl;
        cout<<"\t\t\t _ ";
        cin>>RestName;

        cout<<"\n\n\t\t\t Create a PASSWORD: "<<endl;
        cout<<"\t\t\t Your  password must  have letters, numbers and minimum 6 symbols "<< endl ;
        cout<<"\t\t\t _ ";
        cin>>RPassword;

        while  (RPassword.length() < 6 ) {
        cout<< "\t\t\t Your password must have minimum 6 symbols . Try again "<< endl ;
        cout<<"\t\t\t Create a PASSWORD: ";
        cout<<"\t\t\t _ ";
        cin >> RPassword ;
        }

        cout<<"\n\n\t\t\t Enter your address: "<<endl;
        cout<<"\t\t\t _ ";
        cin>>Address;

        cout<<"\n\n\t\t\t Enter your email: "<<endl;
        cout<<"\t\t\t _ ";
        cin>>Email;




	//UserRole();
// ____________________________________ //
/*
        cout<<"\t * Press 1 to for ADMIN:    "<<endl;
        cout<<"\t * Press 2 to USER: "<<endl;
        cout<<"\t __ ";
        cin>>a;

        switch(a)
        {
                case 1:
                        userrole="Admin";
                        break;
                case 2:
                        userrole="User";
                        break;
         }*/
// _________________________________________ //

	cout<<"\x1B[2J\x1B[H";
	cout<<"\n\t\t\t Your registration is done! \n";

    MYSQL* connn = mysql_init(NULL);

    if (connn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(connn, server, username, password, database, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(connn);
        return 1;   
    }

  /*  if (mysql_query(conn, "CREATE TABLE USER(Eid INT PRIMARY KEY AUTO_INCREMENT, Ename VARCHAR(16), Salary INT)")) {
        printf("Unable to create database table in MyDb database\n");
        mysql_close(conn);
        return 1;
    }*/
    string userID=generateID();
    cout<<userID<<endl;
    //string userID = generateUniqueID();

    string queryString = "INSERT INTO USER(ID, Username, RestName, Password, Address, Email, MenuID, UserRole) VALUES ('" + userID +  "','" + RuserName + "','" + RestName +"','" + RPassword + "','" + Address + "','" + Email + "','0','" + userrole + "')";
    string insertQuery = queryString;
    if (mysql_query(connn, insertQuery.c_str())) {
        // Handle query execution error
        mysql_close(connn);
        return 1;
    } 

		cout<<"\t\t\t Now you  can login to your profile. \n\n\n";
                firstpage();

}

// ________________________________________________________ //


int login()
{
	int count;
	string UserName, Password;
        	
	cout<<"\x1B[2J\x1B[H";
	cout<<"\t\t\t Enter the USERNAME: ";
	cin>>UserName;
	cout<<"\t\t\t Enter the PASSWORD: ";
    cin>>Password;

// *************************************** //
	char server[30] = "sql6.freesqldatabase.com";
        char username[25] = "sql6642308";
        char password[25] = "ZL9cx52cPH";
        char database[25] = "sql6642308";

    	MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, database, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    if(mysql_query(conn, "SELECT * FROM USER")) {
            cout<<"Unable to  connect with MySQL server\n";
            mysql_close(conn);
            return 1;}
	
	MYSQL_RES *result = mysql_store_result(conn);
        if (result == NULL) {
         cout << "Result fetching error." <<endl;
       	mysql_close(conn);
        return 1;
    }
	

    int num_fields = mysql_num_fields(result);
         MYSQL_ROW row;
    	while ((row = mysql_fetch_row(result))) {
            string rowUsername = row[1];
         string rowPassword = row[3];
            	if (rowUsername.compare(UserName)==0){
                    if(rowPassword.compare(Password)==0){
                    cout<<"\n\n\t\t\tWelcome to your profile! \n\n";
                    profile();
                        }
                else{ 
                cout<<"\x1B[2J\x1B[H";
                cout<<"\n\n\n\t\t\t Incorrect username or password! Try again! \n\n";
                firstpage_two(); }                
                }                       
       }
 
/*
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
	string rowUsername = row[1];
        string rowPassword = row[3];
        if(rowUsername.compare(UserName) == 0 && rowPassword.compare(Password) == 0){
             cout<<"\n\t\t\t Welcome to  your profile! \n\n"<<endl;
	         profile();  }
	      
	     else { 
	cout<< "\t\t\t Incorrect!. Try again! \n "<<endl;
	firstpage_two(); }
	}
*/

    mysql_free_result(result);
    mysql_close(conn);
}
// ******************************************* //
	
// _______________________________________________ //

void forgot()
{
	int version;
	cout<<"\x1B[2J\x1B[H";
	cout<<"\n\n\n\t\t\t Forgot your password? We can help you!\n\n";
	cout<<"\t\t * Press 1 to search your ID by email"<<endl;
    cout<<"\t\t * Press 2 to  go to the main page"<<endl;
	cout<<"\t\t Enter your choise: \n";
    cout<<"\t\t __ ";
	cin>>version;

	switch(version)
	{
		case 1: 
			{
			int count=0;
			string Fuserid, Fid, Fpass;
			cout<<"\t\t\t Enter the USERNAME: ";
			cin>>Fuserid;
			ifstream f3("data.xls");
				if(f3.is_open()){
				while(f3>>Fid>>Fpass) {
					if(Fid==Fuserid){
						count=1; }
				}
			f3.close();}
			if(count==1){
				cout<<"\t\t Your account is found\n";
				cout<<"\t\t Your  password is: "<<Fpass;
				cout<<"\n\n\t\t\t Now you  can login to your profile \n\n";
				firstpage(); }
			else {
				cout<<"\n\t\t Your  account is not  found!\n";
				firstpage();
			}
			break; }
		case 2:
			{
				main(); }
		default:
			cout<<"\t\t Wrong choice! Try  again!";
	}
}













