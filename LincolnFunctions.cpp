#include "LincolnFunctions.h"
#include "structures.h"
#include <iostream>
#include <string>
#include <fstream>

int run(int x)
{
  return x + 5;
}

void newVacancy(string posIn, string disIn)
{

}

list<user> readUsers() // This function will read the file and input the data in to the program. The .txt file should be saved in a particular order, depending on the type of structure it is
{
	list<user> readUser;
	list<user>::iterator p = readUser.begin();
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5];
	size_t pos = 0;
	string token;
	infile.open("users.txt");
	if(infile.is_open()) // This is going to be a problem if the file exists but it's empty (which shouldn't happen unless you manually edit the txt file), I'll look into a fix
	{
		while( getline (infile,line))
		{
			while(( pos = line.find("/")) != string::npos) // Nobody can have a / in their name, that will screw up the parsing. If it becomes a problem I will change the delimiter
			{
				token = line.substr(0,pos);
				dataArray[i] = token;
				line.erase(0,pos + 1);
				++i;
			}
			int dataZero = atoi(dataArray[0].c_str());
			char dataFive = line[0];
			readUser.push_back(user(dataZero, dataArray[1], dataArray[2], dataArray[3], dataFive));
		}
		infile.close();
	}
	else
	{
		cout << "File fialed to open" << endl;
		readUser.push_back(user(1, "password", "admin", "", 'A'));
	}
	return readUser;
}
