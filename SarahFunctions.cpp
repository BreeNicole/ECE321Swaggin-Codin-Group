#include "SarahFunctions.h"
#include "structures.h"
#include <list>
#include <iostream>
#include <iterator>
#include <string>

int logIn(list<q>)
{
  string queryID;
  string queryPass;
  cout<<"Please enter your ID: ";
  getline(cin, queryID);
  cout<<"Please enter your password:  ";
  getline(cin, queryPass);
  
  for (list<q>::iterator it = q.begin(); it != q.end(); ++it)
	{
		if(it->ID ==queryID && strcmp(it->password, queryPass)==0)
		{
			return 1;
		}
	}
}
