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
	list<user> userList = readUsers();
	list<vacancy> vacList = readVacs();
	list<course> courseList = readCourses();
	user current;

	int program = 0;
	string posIn, disIn;
	int choice = 0;
	string subChoice;
	while (choice == 0) // Controls the initial "menu"
	{
		cin.clear();
		cout << "Please select what you would like to do" << endl;
		cout << "1: View Timetable" << endl;
		cout << "2: Log In" << endl;
		cout << "3. Save and Exit" << endl;
		cin >> subChoice;
		cin.clear();
		

		if (subChoice == "1") //View Timetable
			ViewTimetable();
		else if (subChoice == "2")
			choice = 1;
		else if (subChoice == "3")
			return;
		else
			cout << "Invalid input! Please select an input from the menu!" << endl;

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
			string input = "";


			char group = current.get_group();
			if (group == 'S' || group == 's' || group == 'F' || group == 'f' || group == 'A' || group == 'a') // organized by each group, this will determine which parts of the menu are viewed
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

			cin >> input;
			cin.clear();
			list <user>::iterator it = userList.begin();
			int numInput = 0;
			char cInput;
			string sInput[5] = { "", "", "", "", "" };
			int val = 0;
// These if and else if statements will control which function is being used
			if (input == "1") // View the Time Table
			{
				ViewTimetable();
				input = "";
			}
			else if (input == "2") // Save and Exit Program
			{
				saveUsers(userList);
				saveVacs(vacList);
				saveCourse(courseList);
				program = 0;
				input = "";
			}
			else if (input == "3") // View Personal Attendance for a class
			{
				cout << "Enter the name of the class you are taking attendance for";
				cin >> sInput[0];
				cin.clear();
				printAttendence(courseList, sInput[0], current.get_ID());
				input = "";
			}
			else if (input == "4") // View the user Submission
			{
				if (current.get_group() != 'F' || current.get_group() != 'A' || current.get_group() != 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					takeSubmission(current);
				input = "";
			}
			else if (input == "5") // Read Vacanies
			{
				readVacs();
				input = "";
			}
			else if (input == "6") // Print Vacanies
			{
				for (list<vacancy>::iterator it = vacList.begin(); it != vacList.end(); ++it)
				{
					cout << it->get_position() << endl << it->get_description() << endl;
				}
				input = "";
			}
			else if (input == "7") // View Attendance of a student
			{
				cout << "Enter the name of the class you are taking attendance for: ";
				cin >> sInput[0];
				cin.clear();
				cout << "Enter the ID of the student you want to view: ";
				cin >> numInput;
				cin.clear();
				printAttendence(courseList, sInput[0], numInput);
				input = "";
			}
			else if (input == "8") // Join a class
			{
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
				input = "";
			}
			else if (input == "9") // Print the users
			{
				for (list<user>::iterator it = userList.begin(); it != userList.end(); ++it)
				{
					cout << it->get_ID() << " ID\n" << it->get_password() << " password\n" << it->get_firstName() << " First\n" << it->get_lastName() << " Last\n" << it->get_group() << endl;
				}
				input = "";
			}
			else if (input == "A") //Enter a new course
			{
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
				input = "";
			}
			else if (input == "B") // Update a time in the Timetable
			{
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					StoreTimetable();
				input = "";
			}
			else if (input == "C") // Take Attendance
			{
				if (current.get_group() == 'S')
				{
					cout << "You do not have permission to do this. How did you even get here?" << endl;
				}
				else
					take_attendence(courseList, current);
				input = "";
			}
			else if (input == "D") // Enter a new vacancy 
			{
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
				input = "";
			}
			else if (input == "E") // Remove a vacancy
			{
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
				input = "";
			}
			else if (input == "F") // New User 
			{
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
				input = "";
			}
			else if (input == "G") // Remove a student
			{
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
				input = "";
			}
			else if (input == "H") // change a password
			{
				changePassword(current);
				input = "";
			}
			else
				cout << "Invalid Input! Please select an input from the menu!"<< endl;




			}
	}



