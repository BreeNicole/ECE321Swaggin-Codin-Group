#include "SarahFunctions.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

user logIn(list<user> userlist, int &prog)
{
	int queryID;
	string queryPass;
	string pass;
	int ID;
	while (prog == 0)
	{
		cout << "Please enter your ID: ";
		cin >> queryID;
		cin.clear();
		cout << "Please enter your password:  ";
		cin >> queryPass;
		cin.clear();

		for (list<user>::iterator it = userlist.begin(); it != userlist.end(); ++it)
		{
			ID = it->get_ID();
			pass = it->get_password();
			if (ID == queryID && pass == queryPass)
			{
				cout << "Valid login" << endl;
				prog = 1;
				return *it;
			}

		}
		cout << "Invalid Username/Password" << endl;

	}
}
