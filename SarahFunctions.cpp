#include "SarahFunctions.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

user logIn(list<user> userlist, int *prog)
{
	int queryID;
	string queryPass;
	string pass;
	int ID;
	cout << "Please enter your ID: ";
	cin >> queryID;
	cout << "Please enter your password:  ";
	cin >> queryPass;

	for (list<user>::iterator it = userlist.begin(); it != userlist.end(); ++it)
	{
		ID = it->get_ID();
		pass = it->get_password();
		if (ID == queryID && pass == queryPass)
		{
			cout << "Valid login" << endl;
			*prog = 1;
			return *it;
		}

	}
	cout << "Invalid Username/Password" << endl;
	*prog = 0;
}
