#include "LincolnFunctions.h"
#include "structures.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>

void newVacancy(list<vacancy>& vacList, string positionIn, string discriptionIn)
{
	vacList.push_back(vacancy(positionIn,discriptionIn));
}

void newUser(list<user>& userList, int ID, string password, string firstName, string lastName, char group)
{
	userList.push_back(user(ID, password, firstName, lastName, "", group));
}

void removeVacancy(list<vacancy>& vacList, string del)
{
	list<vacancy>::iterator it;
	for (it = vacList.begin(); it != vacList.end(); ++it)
	{
		if (del == it->get_position())
		{
			vacList.erase(it);
			cout << del << " has been removed" << endl;
			return;
		}
	}
	cout << "Position not found, no changes have been made." << endl;
}

void removeUser(list<user>& userList, int ID)
{
	list<user>::iterator it = userList.begin();
	for (it = userList.begin(); it != userList.end(); ++it)
	{
		if (ID == it->get_ID())
		{
			userList.erase(it);
			cout << ID << " has been deleted" << endl;
			return;
		}
	}
	cout << "ID not found, no changes have been made." << endl;
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
	if (infile.is_open()) // This is going to be a problem if the file exists but it's empty (which shouldn't happen unless you manually edit the txt file), I'll look into a fix
	{
		while (getline(infile, line))
		{
			while ((pos = line.find("/")) != string::npos) // Nobody can have a / in their name, that will screw up the parsing. If it becomes a problem I will change the delimiter
			{
				token = line.substr(0, pos);
				dataArray[i] = token;
				line.erase(0, pos + 1);
				++i;
			}
			i = 0;
			int dataZero = atoi(dataArray[0].c_str());
			char dataFive = line[0];
			readUser.push_back(user(dataZero, dataArray[1], dataArray[2], dataArray[3], dataArray[4], dataFive));
		}
		infile.close();
	}
	else
	{
		cout << "users.txt failed to open" << endl;
		readUser.push_back(user(1, "password", "admin", "", "", 'A'));
	}
	return readUser;
}

list<vacancy> readVacs()
{
	list<vacancy> readVac;
	list<vacancy>::iterator p = readVac.begin();
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5];
	size_t pos = 0;
	string token;
	infile.open("vacancies.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			while ((pos = line.find("/")) != string::npos)
			{
				token = line.substr(0, pos);
				dataArray[i] = token;
				line.erase(0, pos + 1);
				++i;
			}
			dataArray[i] = line;
			i = 0;
			readVac.push_back(vacancy(dataArray[0], dataArray[1]));
		}
		infile.close();
	}
	else
	{
		cout << "vacancies.txt failed to open" << endl;
		readVac.push_back(vacancy("Temp", "Please remove this after you add a vacancy"));
	}
	return readVac;
}

void saveUsers(list<user> saveUser)
{
	ofstream outfile;
	outfile.open("users.txt");
	if (outfile.is_open())
	{
		for (list<user>::iterator it = saveUser.begin(); it != saveUser.end(); it++)
		{
			outfile << it->get_ID() << '/';
			outfile << it->get_password() << '/';
			outfile << it->get_firstName() << '/';
			outfile << it->get_lastName() << '/';
			outfile << it->get_classList() << '/';
			outfile << it->get_group() << endl;
		}
		cout << "users.txt saved" << endl;
	}
	else
	{
		cout << "users.txt failed to save" << endl;
	}
}

void saveVacs(list<vacancy> saveVac)
{
	ofstream outfile;
	outfile.open("vacancies.txt");
	if (outfile.is_open())
	{
		for (list<vacancy>::iterator it = saveVac.begin(); it != saveVac.end(); ++it)
		{
			outfile << it->get_position() << '/';
			outfile << it->get_description() << endl;
		}
		cout << "vacancies.txt saved" << endl;
	}
	else
	{
		cout << "vacancies.txt failed to save" << endl;
	}
}

