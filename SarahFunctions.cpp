#include "SarahFunctions.h"
#include "structures.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

int logIn(list<user> userlist)
{
  int queryID;
  string queryPass;
  cout<<"Please enter your ID: ";
  cin >> queryID;
  cout<<"Please enter your password:  ";
  cin >> queryPass;
  
  for (list<user>::iterator it = userlist.begin(); it != userlist.end(); ++it)
	{
		if(it->ID == queryID && it->password == queryPass)
		{
			cout << "Valid login" << endl;
			return 1;
			break;
		}
		  
   }
cout<<"Invalid Username/Password"<<endl;
return 0;
}
