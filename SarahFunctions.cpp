#include "SarahFunctions.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

user logIn(list<user> userlist, int &prog)
{
	int queryID; //temp ID for comparison
	string queryPass; // temp password for comparison
	string pass; // Variable for current password
	int ID; // variable for current ID
	while (prog == 0)// loop to retry ID and password entry
	{
		cout << "Please enter your ID: ";
		cin >> queryID;
		cin.clear();
		cout << "Please enter your password:  ";
		cin >> queryPass;
		cin.clear();

		for (list<user>::iterator it = userlist.begin(); it != userlist.end(); ++it) // for loop to compare all of the users
		{
			ID = it->get_ID();
			pass = it->get_password();
			if (ID == queryID && pass == queryPass)// makes sure both the ID and password are the same
			{
				cout << "Valid login" << endl;
				prog = 1;
				return *it; // this returns the current user 
			}

		}
		cout << "Invalid Username/Password" << endl;

	}
}
