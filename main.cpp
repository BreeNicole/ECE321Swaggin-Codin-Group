#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <fstream>

#include "structures.h"
#include "LincolnFunctions.h"
#include "BreannFunctions.h"
#include "AndreaFunctions.h"
#include "SarahFunctions.h"

using namespace std;

list<user> readUsers();

void main()
{
	cout << "This is the best program, all others are bad" << endl;
	list<user> userList = readUsers();
	char input;
	int program = 0;

	while (program == 0)
	{
		printf("Login Function\n");
		program = 1;
	}


	while (program == 1)
	{
		printf("Enter your choice: ");
		do
		cin >> input;
		while (isspace(input));
		list <user>::iterator it = userList.begin();
		switch (input) {

		case '1':
			printf("Run Function 1\n"); // Right now it just prints the first entry in the list
			cout << it->get_ID() << " ID\n" << it->get_password() << " password\n" <<it->get_firstName() << " First\n" << it->get_lastName() << " Last\n" << it->get_group() << endl;
			break;

		case '2':
			printf("Run Function 2\n"); //Logout, save, and exit
			program = 0;
			break;

		case '3':
			printf("Run Function 3\n"); //View Timetable (student) Bree
			break;

		case '4':
			printf("Run Function 4\n"); //View Personal Attendance (student) Bree
			break;

		case '5':
			printf("Run Function 5\n"); //View all attendance (student) Bree 
			break;

		case '6':
			printf("Run Function 6\n"); //View Submissions (student)  Bree
			break;

		case '7':
			printf("Run Function 7\n"); //View Vacancies (student) Bree
			break;

		case '8':
			printf("Run Function 8\n"); //Input Student Attendance (Faculty)
			break;

		case '9':
			printf("Run Function 9\n"); //Update Timetable (Admin)
			break;

		case 'A':
			printf("Run Function A\n"); //Post vacancies (Admin)

			/*string posIn, disIn;
			printf("Enter the position of the new vacancy");
			cin >> posIn;
			printf("Enter the discription of the new vacancy");
			cin >> disIn;*/
			//newVacancy(posIn, disIn);

			break;

		case 'B':
			printf("Run Function B\n"); //view Details of students (Faculty)
			break;

		case 'C':
			printf("Run Function C\n"); //Edit exam timetable (Faculty)
			break;

		default:
			printf("Invalid input\n");

		}
	}
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

/*list<course> readCourses() //Don't use this function yet
{
	list<user> readCourse;
	list<user>::iterator p = readCourse.begin();
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5]
	size_t pos = 0;
	string token;
	infile.open("courses.txt");
	if(infile.is_open())
	{
		while( getline (infile,line))
		{
			while(( pos = line.find("/")) != string::npos)
			{
				token = line.substr(0,pos);
				dataArray[i] = token;
				line.erase(0,pos + 1);
				++i;
			}
		//readUser.push_back(course(dataArray[0],dataArray[1],dataArray[2]));
		}
		infile.close();
		return readCourse;
	}
	else
	{
		cout << "File fialed to open" << endl;
	}
}

list<vacancy> readVacs()
{
	list<user> readVac;
	list<user>::iterator p = readVac.begin();
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5]
	size_t pos = 0;
	string token;
	infile.open("vacancies.txt");
	if(infile.is_open())
	{
		while( getline (infile,line))
		{
			while(( pos = line.find("/")) != string::npos)
			{
				token = line.substr(0,pos);
				dataArray[i] = token;
				line.erase(0,pos + 1);
				++i;
			}
		readVac.push_back(user(dataArray[0],dataArray[1]));
		}
		infile.close();
		return readUser;
	}
	else
	{
		cout << "File fialed to open" << endl;
	}
}*/

void saveUsers()
{

}
