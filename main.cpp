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


void main()
{
	cout << "This is the best program, all others are bad" << endl;
	list<user> userList = readUsers();
	list<vacancy> vacList = readVacs();
	list<course> courseList = readCourses();
	user current;
	
	int program = 0;
	string posIn, disIn;
	while (program == 0)
	{
		current = logIn(userList, program);
		program =1;
	}


	while (program == 1)
	{

		posIn = "";
		disIn = "";
		char input;
		cout << "1: Print users" << endl;
		cout << "2: Save and Exit" << endl;
		cout << "3: View Timetable (in progress)" << endl;
		cout << "4: View your attendance" << endl;
		cout << "5: View all attendance" << endl;
		cout << "6: Submit assignment" << endl;
		cout << "7: View Vacancies" << endl;
		cout << "8: Create a new course" << endl;
		cout << "9: Update Timetable (in progress)" << endl;
		cout << "A: Take attendance" << endl;
		cout << "B: Post vacancy" << endl;
		cout << "C: Join a class" << endl;
		cout << "D: Print Vacanies" << endl;
		cout << "E: Add a new student" << endl;
		cout << "F: Remove an existing student" << endl;
		cout << "G: Remove a current vacancy posting" << endl;
		cout << "H: Change Password" << endl;
		cout << "Enter your choice: ";
		do
		cin >> input;
		while (isspace(input));
		cin.clear();
		list <user>::iterator it = userList.begin();
		int numInput = 0;
		char cInput;
		string sInput[5] = { "","","","","" };

		switch (input) {

		case '1': // Prints the userlist
			for (list<user>::iterator it = userList.begin(); it != userList.end(); ++it)
			{
				cout << it->get_ID() << " ID\n" << it->get_password() << " password\n" << it->get_firstName() << " First\n" << it->get_lastName() << " Last\n" << it->get_group() << endl;
			}
			break;



		case '2': //save and logout
			saveUsers(userList);
			saveVacs(vacList);
			saveCourse(courseList);
			program = 0;
			break;



		case '3':
			break;



		case '4': // prints attendance for the user
			cout << "Enter the name of the class you are taking attendece for"; 
			cin >> sInput[0];
			printAttendence(courseList, sInput[0], current.get_ID());
			break;



		case '5': // prints attendance for a student
			cout << "Enter the name of the class you are taking attendece for: ";
			cin >> sInput[0];
			cout << "Enter the ID of the student you want to view: ";
			cin >> numInput;
			printAttendence(courseList, sInput[0], numInput);
			break;



		case '6': // Takes a user submission
			takeSubmission(current);
			break;



		case '7': // Prints all vacancies
			readVacs();
			break;



		case '8': // creates a new course
			cout << "Enter the Title of the new course: ";
			cin >> sInput[0];
			newCourse(courseList, sInput[0]);
			break;



		case '9':
			break;



		case 'A': // Takes attendence
			take_attendence(courseList, current);
			break;
			


		case 'B': //Post a new vacancy
			cin.ignore();
			printf("Enter the position of the new vacancy");
			getline(cin,posIn);
			printf("Enter the discription of the new vacancy");
			getline(cin,disIn);
			newVacancy(vacList, posIn, disIn);
			break;



		case 'C': // joins a course
			cout << "Enter Your ID: ";
			cin >> numInput;
			cout << "Enter the Title of the course: ";
			cin >> sInput[0];
			joinCourse(courseList, sInput[0], numInput);
			userJoinCourse(userList, sInput[0], numInput);
			break;



		case 'D': // prints all vacancies
			for (list<vacancy>::iterator it = vacList.begin(); it != vacList.end(); ++it)
			{
				cout << it->get_position() << endl << it->get_description() << endl;
			}
			break;



		case 'E': // creates a new user
			cout << "Enter the new student's ID: ";
			cin >> numInput;
			cout << "Enter the new student's password: ";
			cin >> sInput[1];
			cout << "Enter the new student's first name: ";
			cin >> sInput[2];
			cout << "Enter the new student's last name: ";
			cin >> sInput[3];
			cout << "Enter the new students permissions (A = Admin, F = Faculty, S = Student): ";
			cin >> cInput;
			newUser(userList, numInput, sInput[1], sInput[2], sInput[3], cInput);
			break;



		case 'F': // Removes a user
			cout << "Enter the ID of the student you would like to remove: ";
			cin >> numInput;
			removeUser(userList, numInput);
			break;



		case 'G': // Removes a vacancy
			cout << "Enter the position of the vacancy you would like to remove: ";
			cin.ignore();
			getline(cin, sInput[1]);
			removeVacancy(vacList, sInput[1]);
			break;



		case 'H': //Changes curent users password
			changePassword(current);
			break;



		default:
			printf("Invalid input\n");

		}
	}
}
