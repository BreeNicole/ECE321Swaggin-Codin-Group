#include "SarahFunctions.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

user * logIn(list<user>& userlist, int &prog)
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
				return &(*it); // this returns the current user 
			}

		}
		cout << "Invalid Username/Password" << endl;
	}
}user * logIn(list<user>& userlist, int &prog)
{
	int queryID; //temp ID for comparison
	string queryPass; // temp password for comparison
	string pass; // Variable for current password
	int ID; // variable for current ID
	int i = 0;

	while (prog == 0)// loop to retry ID and password entry
	{
		cout << "Please enter your ID: ";
		cin >> queryID;
		cin.ignore();
		cin.clear();
		cout << "Please enter your password:  ";
		getline(cin, queryPass);

		
	
		for (list<user>::iterator it = userlist.begin(); it != userlist.end(); ++it) // for loop to compare all of the users
		{
			ID = it->get_ID();
			pass = it->get_password();
			if (ID == queryID && pass == queryPass)// makes sure both the ID and password are the same
			{
				cout << "Valid login" << endl;
				prog = 1;
				return &(*it); // this returns the current user 
			}

		}
		cout << "Invalid Username/Password" << endl;

		if (i >= 5)
		{
			cout << "You've been locked out for 20 seconds because you tried the wrong password too many times" << endl;
			clock_t start = clock();
			clock_t end = 20 * 1000 + start;
			while (clock() != end);
			i = 0;
		}

		i++;
	}
	return NULL;
}

