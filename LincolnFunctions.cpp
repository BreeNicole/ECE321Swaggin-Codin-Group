#include "LincolnFunctions.h"
#include "structures.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <cstddef>
#include <locale>
#include <time.h>
#pragma warning(disable : 4996)

void newVacancy(list<vacancy>& vacList, string positionIn, string discriptionIn)
{
	vacList.push_back(vacancy(positionIn, discriptionIn));
}

void newUser(list<user>& userList, int ID, string password, string firstName, string lastName, char group)
{
	userList.push_back(user(ID, password, firstName, lastName, "", group));
}

void newCourse(list<course>& courseList, string title)
{
	courseList.push_back(course(title));
}

void joinCourse(list<course>& courseList, string title, int ID)
{
	list<course>::iterator it;
	for (it = courseList.begin(); it != courseList.end(); ++it)
	{
		if (it->get_title() == title)
		{
			it->setAttendance(it->get_attendance() + to_string(ID)+ "|");
			cout << ID << " has joined " << title;
			return;
		}
	}
	cout << "Course not found" << endl;
}

void userJoinCourse(list<user>& userList, string title, int ID)
{
	list<user>::iterator it;
	for (it = userList.begin(); it != userList.end(); ++it)
	{
		if (it->get_ID() == ID)
		{
			it->set_classList(it->get_classList() + title + "|");
			return;
		}
	}
	cout << "ID not found" << endl;
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

list<course> readCourses()
{
	list<course> readCourse;
	list <course>::iterator p = readCourse.begin();
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5];
	size_t pos = 0;
	string token;
	infile.open("courses.txt");
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
			readCourse.push_back(course(dataArray[0], dataArray[1], dataArray[2]));
		}
		infile.close();
	}
	else
	{
		cout << "courses.txt failed to open" << endl;
		readCourse.push_back(course("Temp", "Please remove this after you add a course", ""));
	}
	return readCourse;
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

void saveCourse(list<course> saveCourse)
{
	ofstream outfile;
	outfile.open("courses.txt");
	if (outfile.is_open())
	{
		for (list<course>::iterator it = saveCourse.begin(); it != saveCourse.end(); ++it)
		{
			outfile << it->get_title() << '/';
			outfile << it->get_attendance() << '/';
			outfile << it->get_submission() << endl;
		}
		cout << "courses.txt saved" << endl;
	}
	else
	{
		cout << "vacancies.txt failed to save" << endl;
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

void take_attendence(list<course> courses, user current)
{
	if (current.get_group() == 'S')
	{
		cout << "You do not have permission to do this. How did you even get here?" << endl;
	}
	else
	{
		//string * readIn = parseLine(current.get_classList());


		string courseRead[5];
		string token;
		size_t pos = 0;
		string buffer = current.get_classList();
		int i = 0;
		while ((pos = buffer.find("|")) != string::npos && i < 5)
		{
			token = buffer.substr(0, pos);
			courseRead[i] = token;
			buffer.erase(0, pos + 1);
			++i;
		}
		courseRead[i] = buffer;

list<course>::iterator it;
int storeAtt[30];
bool loop = true;
do
{
cout << "Enter the name of the course you are taking attendence for: ";
string read;
bool found = false;
cin >> read;
for (int i = 0; i < 5; i++)
{
if (read == "Exit")
{
	return;
}
if (read == courseRead[i])
{
	found = true;
	break;
}
}
if (found)
{
	for (it = courses.begin(); it != courses.end(); ++it)
	{
		if (it->get_title() == read)
		{
			loop = false;
			break;
		}
	}
}
cout << "Invalid course title. Type Exit to leave." << endl;
} while (loop);
//int * currentAtt = parseAtt(it->get_attendance());


int output[30];
pos = 0;
i = 0;
buffer = it->get_attendance();
while ((pos = buffer.find("|")) != string::npos && i < 30)
{
	token = buffer.substr(0, pos);
	output[i] = stoi(token);
	buffer.erase(0, pos + 1);
	++i;
}
//output[i] = stoi(input);
if (i != 29)
{
	output[i] = NULL;
}


for (i = 0; i < 30 && output[i] != NULL; i++)
{
	int readInt;
	do
	{
		cout << "Is " << output[i] << " present (1 = Yes, 0 = No): ";
		cin >> readInt;
		if (readInt == 1 || readInt == 0)
		{
			storeAtt[i] = readInt;
			break;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	} while (1);
}
ofstream outfile;
string file = ((it->get_title()) + ("_attendance.txt"));
outfile.open(file, ios_base::app);
if (!outfile.good())
{
	cout << "File failed to open" << endl;
	return;
}
time_t t = time(0);
struct tm * now = localtime(&t);
outfile << "----------------------------------------------" << endl << "DATE" << now->tm_mday << "-" << (now->tm_mon + 1) << "-" << (now->tm_year + 1900) << endl;
for (int j = 0; j < i; j++)
{
	outfile << output[j] << (storeAtt[j] ? (" Present") : (" Not_Present")) << endl;
}
outfile << endl << endl;
outfile.close();
return;
	}
}

void printAttendence(list<course>, string courseTitle, int ID)
{
	ifstream infile;
	string line;
	size_t pos;
	string date;
	string file = (courseTitle + "_attendance.txt");
	infile.open(file);
	if (!infile.good())
	{
		cout << "File failed to open" << endl;
		return;
	}
	while (infile.good())
	{
		getline(infile, line);
		if ((pos) = line.find("DATE") != string::npos)
		{
			date = line.substr(pos + 3);
		}
		if ((pos) = line.find(to_string(ID)) != string::npos)
		{
			cout << date << " " << line << endl;
		}
	}
	infile.close();
}

void takeSubmission(user current)
{
	cout << "Please enter the class you are submitting for: ";
	string classname;
	cin >> classname;

	string courseRead[5];
	string token;
	size_t pos = 0;
	string buffer = current.get_classList();
	int i = 0;
	while ((pos = buffer.find("|")) != string::npos && i < 5)
	{
		token = buffer.substr(0, pos);
		courseRead[i] = token;
		buffer.erase(0, pos + 1);
		++i;
	}
	courseRead[i] = buffer;
	bool found = false;
	for (int i = 0; i < 5; ++i)
	{
		if (classname == courseRead[i])
			found = true;
	}
	if (!found)
	{
		cout << "Course not found" << endl;
		return;
	}
	cout << "Please enter the file name you would like to submit: ";
	string filename;
	cin >> filename;

	ofstream outfile;
	string file = ((classname) + ("_submissions.txt"));
	outfile.open(file, ios_base::app);
	if (!outfile.good())
	{
		cout << "File failed to open" << endl;
		return;
	}
	outfile << filename << " Submitted by " << current.get_ID() << endl;
	outfile.close();
}

void changePassword(user &current)
{
	string oldPass;
	string newPass;
	string newPassCheck;
	cout << "Please enter your password: ";
	cin >> oldPass;
	while (1)
	{
		if (oldPass == current.get_password())
		{
			cout << "Please enter your new password: ";
			cin >> newPass;
			cout << "Please re enter your new password: ";
			cin >> newPassCheck;
			if(newPass != newPassCheck)
			{
				cout << "The passwords did not match" << endl;
			}
			else
			{
				current.set_password(newPass);
				cout << "Your password has been updated" << endl;
				return;
			}
		}
		else if (oldPass == "Exit")
		{
			return;
		}
		else
		{
			cout << "Incorrect password, type Exit to leave" << endl << "Please enter your new password: ";
			cin >> oldPass;
		}
	}
}

