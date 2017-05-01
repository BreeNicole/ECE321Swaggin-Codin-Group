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
	int choice = 0;
	int subChoice;
	while (choice == 0)
	{
		cout << "Please select what you would like to do" << endl;
		cout << "1: View Timetable" << endl;
		cout << "2: Log In" << endl;
		cout << "3. Save and Exit" << endl;
		cin >> subChoice;

		switch (subChoice) {

		case 1: //View Timetable
			ViewTimetable();
			break;
		case 2: 
			choice = 1;
			break;
		case 3: //save and logout
			return;
		}
	}
		while (program == 0)
		{
			current = logIn(userList, program);
			program = 1;
		}


		while (program == 1)
		{
			cin.clear();
			posIn = "";
			disIn = "";
			char input;


			char group = current.get_group();
			if (group == 'S' || group == 's' || group == 'F' || group == 'f' || group == 'A' || group == 'a')
			{
				cout << "1: View Timetable" << endl;
				cout << "2. Save and Exit" << endl;
				cout << "3: View your attendance" << endl;
				cout << "4: Submit assignment" << endl;
				cout << "5: View Vacancies" << endl;
				cout << "6: Print Vacanies" << endl;
				cout << "7: View all attendance" << endl;
				cout << "8: Join a class" << endl;
			}
			if (group == 'F' || group == 'f' || group == 'A' || group == 'a')
			{
				cout << "9: Print users" << endl;
				cout << "A: Create a new course" << endl;
				cout << "B: Update Timetable" << endl;
				cout << "C: Take attendance" << endl;
				cout << "D: Post vacancy" << endl;
				cout << "E: Remove a current vacancy posting" << endl;


			}
			if (group == 'A' || group == 'a')
			{
				cout << "F: Add a new student" << endl;
				cout << "G: Remove an existing student" << endl;
				cout << "H: Change Password" << endl;
			}
			cout << "Enter your choice: ";

			do
			cin >> input;
			while (isspace(input));
			cin.clear();
			list <user>::iterator it = userList.begin();
			int numInput = 0;
			char cInput;
			string sInput[5] = { "", "", "", "", "" };

			switch (input) {

			case '1': //View Timetable
				ViewTimetable();
				break;

			case '2': //save and logout
				saveUsers(userList);
				saveVacs(vacList);
				saveCourse(courseList);
				program = 0;
				break;


			case '3': // prints attendance for the user
				cout << "Enter the name of the class you are taking attendance for";
				cin >> sInput[0];
				cin.clear();
				printAttendence(courseList, sInput[0], current.get_ID());
				break;

			case '4': // Takes a user submission
				if (current.get_group() != 'F' || current.get_group() != 'A' || current.get_group() != 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					takeSubmission(current);
				break;

			case '5': // Prints all vacancies
				readVacs();
				break;

			case '6': // prints all vacancies
				for (list<vacancy>::iterator it = vacList.begin(); it != vacList.end(); ++it)
				{
					cout << it->get_position() << endl << it->get_description() << endl;
				}
				break;

			case '7': // prints attendance for a student
				cout << "Enter the name of the class you are taking attendance for: ";
				cin >> sInput[0];
				cin.clear();
				cout << "Enter the ID of the student you want to view: ";
				cin >> numInput;
				cin.clear();
				printAttendence(courseList, sInput[0], numInput);
				break;
			case '8': // joins a course
				if (current.get_group() != 'F' || current.get_group() != 'A' || current.get_group() != 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cout << "Enter Your ID: ";
					cin >> numInput;
					cin.clear();
					cout << "Enter the Title of the course: ";
					cin >> sInput[0];
					cin.clear();
					joinCourse(courseList, sInput[0], numInput);
					userJoinCourse(userList, sInput[0], numInput);
				}
				break;
			case '9': // Prints the userlist
				for (list<user>::iterator it = userList.begin(); it != userList.end(); ++it)
				{
					cout << it->get_ID() << " ID\n" << it->get_password() << " password\n" << it->get_firstName() << " First\n" << it->get_lastName() << " Last\n" << it->get_group() << endl;
				}
				break;


			case 'A': // creates a new course
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cout << "Enter the Title of the new course: ";
					cin >> sInput[0];
					cin.clear();
					newCourse(courseList, sInput[0]);
				}
				break;

			case 'B': // Update Timetable
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					StoreTimetable();
				break;

			case 'C': // Takes attendence
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					take_attendence(courseList, current);
				break;


			case 'D': //Post a new vacancy
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cin.ignore();
					printf("Enter the position of the new vacancy");
					getline(cin, posIn);
					printf("Enter the discription of the new vacancy");
					getline(cin, disIn);
					newVacancy(vacList, posIn, disIn);
				}
				break;
			case 'E': // Removes a vacancy
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cout << "Enter the position of the vacancy you would like to remove: ";
					cin.ignore();
					getline(cin, sInput[1]);
					removeVacancy(vacList, sInput[1]);
				}
				break;

			case 'F': // creates a new user
				if (current.get_group() != 'A')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cout << "Enter the new user's ID: ";
					cin >> numInput;
					cin.clear();
					cout << "Enter the new user's password: ";
					cin >> sInput[1];
					cin.clear();
					cout << "Enter the new user's first name: ";
					cin >> sInput[2];
					cin.clear();
					cout << "Enter the new user's last name: ";
					cin >> sInput[3];
					cin.clear();
					cout << "Enter the new user's permissions (A = Admin, F = Faculty, S = Student): ";
					cin >> cInput;
					cin.clear();
					newUser(userList, numInput, sInput[1], sInput[2], sInput[3], cInput);
				}
				break;



			case 'G': // Removes a user
				if (current.get_group() != 'A')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
				{
					cout << "Enter the ID of the student you would like to remove: ";
					cin >> numInput;
					cin.clear();
					removeUser(userList, numInput);
				}
				break;

			case 'H': //Changes curent users password
				changePassword(current);
				break;



			default:
				printf("Invalid input\n");

			}
		}
	}

