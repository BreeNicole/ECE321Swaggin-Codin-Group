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
#pragma warning(disable : 4996) // disables a warning for reading the current time




void newVacancy(list<vacancy>& vacList, string positionIn, string discriptionIn)
{
	vacList.push_back(vacancy(positionIn, discriptionIn));
}


//-------------------------------------------------------------------------------------------------
//						New User
//-------------------------------------------------------------------------------------------------


void newUser(list<user>& userList, int ID, string password, string firstName, string lastName, char group)
{
	list<user>::iterator it;
	for (it = userList.begin(); it != userList.end(); ++it) // searches the userlist to find if the ID to be added already exists
	{
		if (ID == it->get_ID())
		{
			cout << "This ID is already taken" << endl;
			return;
		}
	}
	userList.push_back(user(ID, password, firstName, lastName, "", group)); // adds a new user
}


//-------------------------------------------------------------------------------------------------
//						New Course
//-------------------------------------------------------------------------------------------------


void newCourse(list<course>& courseList, string title)
{
	list<course>::iterator it;
	for (it = courseList.begin(); it != courseList.end(); ++it) // searches the course list to find if the course already exists
	{
		if (title == it->get_title())
		{
			cout << "This course already exists" << endl;
			return;
		}
	}
	courseList.push_back(course(title)); // adds a new course
}


//-------------------------------------------------------------------------------------------------
//						Drop Course
//-------------------------------------------------------------------------------------------------


void dropCourse(list<course>& courseList, list<user>& userList, string title, user &current)
{
	list<course>::iterator cit;
	string parse = current.get_classList(); // sets parse to be the users classlist
	size_t val = 0;
	int i = 0;
	string courses[4] = { "","","","" };
	bool inClass = false;
	while ((val = parse.find("|")) != string::npos)
	{
		string token = parse.substr(0, val); // parses the classlist string into individual classes
		if (token == title)
		{
			inClass = true; // will be set to true if the user is in the class they are trying to drop
		}
		else
		{
			courses[i] = token;
			i++;
		}
		parse.erase(0, val + 1);
	}
	if (inClass)
	{
		string newClassList = current.get_classList();
		newClassList.replace(newClassList.find(title), title.length() + 1, ""); // removes the class from the classlist
		current.set_classList(newClassList);
		for (cit = courseList.begin(); cit != courseList.end(); ++cit) // finds the user in the attendence of the course they are dropping
		{
			if (cit->get_title() == title)
			{
				string change = cit->get_attendance();
				change.replace(change.find(to_string(current.get_ID())), to_string(current.get_ID()).length() + 1 ,""); // drops the user from the attendence of the course
				cit->setAttendance(change);
				cout << "You have dropped " << title << endl;
			}
		}

	}
	else
	{
		cout << "You are not in this class" << endl;
		return;
	}
}


//-------------------------------------------------------------------------------------------------
//						Join Course
//-------------------------------------------------------------------------------------------------


void joinCourse(list<course>& courseList, list<user>& userList, string title, user &current)
{
	list<course>::iterator cit;
	string parse = current.get_classList();
	size_t val = 0;
	int i = 0;
	while ((val = parse.find("|")) != string::npos) //parses the classlist
	{
		if (i > 3) // checks if the user is in the maximum classes
		{
			cout << "You may not join more than 5 classes" << endl;
			return;
		}

		string token = parse.substr(0, val);
		if (token == title) // checks if the suer is in the course
		{
			cout << "You are already in this class" << endl;
			return;
		}
		i++;
		parse.erase(0, val + 1);
	}

	for (cit = courseList.begin(); cit != courseList.end(); ++cit)
	{
		if (cit->get_title() == title)
		{
			parse = cit->get_attendance();
			val = 0;
			i = 0;
			while ((val = parse.find("|")) != string::npos) // parses the courses attendence
			{
				if (i > 28) // checks if the class is full
				{
					cout << "This class is full" << endl;
					return;
				}
				string token = parse.substr(0, val);
				if (token == title) // checls if the user is already in this class. This should never happen unless the first check failed for some reason
				{
					cout << "You are already in this class" << endl;
					return;
				}
				i++;
				parse.erase(0, val + 1);
			}
			cit->setAttendance(cit->get_attendance() + to_string(current.get_ID()) + "|");
			current.set_classList(current.get_classList() + title + "|"); // adds the user to the course
			cout << current.get_ID() << " has joined " << title << endl;
			return;
		}
	}
	cout << "Course not found" << endl;
}


//-------------------------------------------------------------------------------------------------
//						Remove Vacancy
//-------------------------------------------------------------------------------------------------


void removeVacancy(list<vacancy>& vacList, string del)
{
	list<vacancy>::iterator it;
	for (it = vacList.begin(); it != vacList.end(); ++it) // finds the course
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


//-------------------------------------------------------------------------------------------------
//						Remove User
//-------------------------------------------------------------------------------------------------


void removeUser(list<user>& userList, int ID)
{
	list<user>::iterator it = userList.begin();
	for (it = userList.begin(); it != userList.end(); ++it) // finds the user
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


//-------------------------------------------------------------------------------------------------
//						Read Users
//-------------------------------------------------------------------------------------------------


list<user> readUsers() // This function will read the user file and input the data in to the program
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
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			while ((pos = line.find("/")) != string::npos) // parses the file line
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
	else // the file failed to open so there is no user data in the program. An admin account is created
	{
		cout << "users.txt failed to open" << endl << "Admin account has been created \n ID is 1 \n password is password" << endl;
		readUser.push_back(user(1, "password", "admin", "", "", 'A'));
	}
	return readUser;
}


//-------------------------------------------------------------------------------------------------
//						Read Courses
//-------------------------------------------------------------------------------------------------


list<course> readCourses() // This function will read the courses file and input the data in to the program
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
			while ((pos = line.find("/")) != string::npos) // parses the file line
			{
				token = line.substr(0, pos);
				dataArray[i] = token;
				line.erase(0, pos + 1);
				++i;
			}
			dataArray[i] = line;
			i = 0;
			readCourse.push_back(course(dataArray[0], dataArray[1]));
		}
		infile.close();
	}
	else
	{
		cout << "courses.txt failed to open" << endl;
		readCourse.push_back(course("Temp", "Please remove this after you add a course"));
	}
	return readCourse;
}


//-------------------------------------------------------------------------------------------------
//						Read Vacanies
//-------------------------------------------------------------------------------------------------


list<vacancy> readVacs() // This function will read the vacancy file and input the data in to the program
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
			while ((pos = line.find("//")) != string::npos) // parses the file line
			{
				token = line.substr(0, pos);
				dataArray[i] = token;
				line.erase(0, pos + 2);
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


//-------------------------------------------------------------------------------------------------
//						Save Users
//-------------------------------------------------------------------------------------------------


void saveUsers(list<user> saveUser)
{
	ofstream outfile;
	outfile.open("users.txt");
	if (outfile.is_open())
	{
		for (list<user>::iterator it = saveUser.begin(); it != saveUser.end(); it++) // saves the userlist
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


//-------------------------------------------------------------------------------------------------
//						Save Courses
//-------------------------------------------------------------------------------------------------


void saveCourse(list<course> saveCourse)
{
	ofstream outfile;
	outfile.open("courses.txt");
	if (outfile.is_open())
	{
		for (list<course>::iterator it = saveCourse.begin(); it != saveCourse.end(); ++it) // saves the courselist
		{
			outfile << it->get_title() << '/';
			outfile << it->get_attendance() << endl;
		}
		cout << "courses.txt saved" << endl;
	}
	else
	{
		cout << "vacancies.txt failed to save" << endl;
	}
}


//-------------------------------------------------------------------------------------------------
//						Save Vacancies
//-------------------------------------------------------------------------------------------------


void saveVacs(list<vacancy> saveVac)
{
	ofstream outfile;
	outfile.open("vacancies.txt");
	if (outfile.is_open())
	{
		for (list<vacancy>::iterator it = saveVac.begin(); it != saveVac.end(); ++it) // saves the vacancy list
		{
			outfile << it->get_position() << "//";
			outfile << it->get_description() << endl;
		}
		cout << "vacancies.txt saved" << endl;
	}
	else
	{
		cout << "vacancies.txt failed to save" << endl;
	}
}


//-------------------------------------------------------------------------------------------------
//						Take Attendence
//-------------------------------------------------------------------------------------------------


void take_attendence(list<course> courses, user current)
{
	if (current.get_group() == 'S') // checks the suers permission, this was done in the main, but I made this function before we had permission checks, might as well leave it in in case the first one fails
	{
		cout << "You do not have permission to do this. Somehow you managed to get past the first check though" << endl;
	}
	else
	{
		string courseRead[5];
		string token;
		size_t pos = 0;
		string buffer = current.get_classList();
		int i = 0;
		
		while ((pos = buffer.find("|")) != string::npos && i < 5) // parses the users classlist
		{
			token = buffer.substr(0, pos);
			courseRead[i] = token;
			cout << courseRead[i];
			buffer.erase(0, pos + 1);
			++i;
		}
		courseRead[i] = buffer;

		list<course>::iterator it;
		int storeAtt[30];
		bool loop = true;
		do // gets a valid course from the user
		{
			cout << endl << "Enter the name of the course you are taking attendence for: ";
			string read;
			bool found = false;
			getline(cin, read);
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
			else
			{
				cout << "Invalid course title. Type Exit to leave." << endl;
			}
		} while (loop);
	
	
		int output[30];
		pos = 0;
		i = 0;
		buffer = it->get_attendance();
		while ((pos = buffer.find("|")) != string::npos && i < 30) // sets output array to the classes attendence
		{
			token = buffer.substr(0, pos);
			output[i] = stoi(token);
			buffer.erase(0, pos + 1);
			++i;
		}

		if (i != 29)
		{
			output[i] = NULL;
		}
	
	
		for (i = 0; i < 30 && output[i] != NULL; i++) // takes attendence
		{
			int readInt;
			do // allows only 1 and 0 as input
			{
				cout << "Is " << output[i] << " present (1 = Yes, 0 = No): ";
				cin >> readInt;
				cin.ignore();
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
		string file = ((it->get_title()) + ("_attendance.txt")); // creates a save file based on the course title
		outfile.open(file, ios_base::app); // sets the file to be appended
		if (!outfile.good())
		{
			cout << "File failed to open" << endl;
			return;
		}
		time_t t = time(0);
		struct tm * now = localtime(&t); // gets the current date
		outfile << "----------------------------------------------" << endl << "DATE" << now->tm_mday << "-" << (now->tm_mon + 1) << "-" << (now->tm_year + 1900) << endl;
		for (int j = 0; j < i; j++) // saves each user as present or not present
		{
			outfile << output[j] << (storeAtt[j] ? (" Present") : (" Not_Present")) << endl;
		}
		outfile << endl << endl;
		outfile.close();
		return;
	}
}
	

//-------------------------------------------------------------------------------------------------
//						Print attendence
//-------------------------------------------------------------------------------------------------

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
			date = line.substr(pos + 3); // remembers the date
		}
		if ((pos) = line.find(to_string(ID)) != string::npos) // gets present or not present
		{
			cout << date << " " << line << endl;
		}
	}
	infile.close();
}


//-------------------------------------------------------------------------------------------------
//						Take Submission
//-------------------------------------------------------------------------------------------------


void takeSubmission(user current)
{
	cout << "Please enter the class you are submitting for: ";
	string classname;
	getline(cin, classname);

	string courseRead[5];
	string token;
	size_t pos = 0;
	string buffer = current.get_classList();
	int i = 0;
	while ((pos = buffer.find("|")) != string::npos && i < 5) // parses the classlist
	{
		token = buffer.substr(0, pos);
		courseRead[i] = token;
		buffer.erase(0, pos + 1);
		++i;
	}
	courseRead[i] = buffer;
	bool found = false;
	for (int i = 0; i < 5; ++i) // checks if the course exists
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
	getline(cin, filename);

	ofstream outfile;
	string file = ((classname) + ("_submissions.txt")); // opens a unique filename to be appended
	outfile.open(file, ios_base::app);
	if (!outfile.good())
	{
		cout << "File failed to open" << endl;
		return;
	}
	outfile << filename << " Submitted by " << current.get_ID() << endl; // writes the file name and who submitted it
	outfile.close();
}


//-------------------------------------------------------------------------------------------------
//						Change Password
//-------------------------------------------------------------------------------------------------


void changePassword(user &current)
{
	string oldPass;
	string newPass;
	string newPassCheck;
	cout << "Please enter your password: ";
	getline(cin, oldPass); // reads the users current password
	while (1)
	{
		if (oldPass == current.get_password())
		{
			cout << "Please enter your new password: ";
			getline(cin, newPass);
			if (newPass.length() < 4) // checks the length of the new password
			{
				cout << "Your password must be more than 4 characters" << endl;
			}
			else
			{
				cout << "Please re enter your new password: ";
				getline(cin, newPassCheck);
				if (newPass != newPassCheck)
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
		}
		else if (oldPass == "Exit")
		{
			return;
		}
		else
		{
			cout << "Incorrect password, type Exit to leave" << endl << "Please enter your new password: ";
			getline(cin, oldPass);
		}
	}
}


//-------------------------------------------------------------------------------------------------
//						Scan string for a char
//-------------------------------------------------------------------------------------------------


bool hasAChar(string check, string find)
{
	size_t found = check.find(find);
	if (found == string::npos)
	{
		return false;
	}
	return true;
}
