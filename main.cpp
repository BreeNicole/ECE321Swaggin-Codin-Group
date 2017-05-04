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
	user *current;
	current = NULL;
	int program = 0;
	

	while (1) // Controls the initial "menu"
	{
		string subChoice;
		cout << endl;
		cout << "Please select what you would like to do" << endl;
		cout << "1: View Timetable" << endl;
		cout << "2: Log In" << endl;
		cout << "3: Exit" << endl;
		getline(cin, subChoice);
		cout << endl;


		if (subChoice == "1") //View Timetable
		{
			ViewTimetable();
		}


		else if (subChoice == "2")
		{
			while (current == NULL)
			{
				current = logIn(userList, program);
			}

			while (current != NULL)
			{
				string input = "";	// organized by each group, this will determine which parts of the menu are shown for each group
				char group = (*current).get_group();
				cout << endl;
				cout << "1: View Timetable" << endl;
				cout << "2: Save Changes and Log out" << endl;
				cout << "3: View your attendance" << endl;
				cout << "4: Submit assignment" << endl;
				cout << "5: Print Vacanies" << endl;
				cout << "6: View all attendance" << endl;
				cout << "7: Join a class" << endl;
				cout << "8: Drop a class" << endl;
				cout << "9: Change Your password" << endl;
				if (group == 'F' || group == 'A')
				{
					cout << "A: Create a new course" << endl;
					cout << "B: Update Timetable" << endl;
					cout << "C: Take attendance" << endl;
				}
				if (group == 'A')
				{
					cout << "D: Post vacancy" << endl;
					cout << "E: Remove a current vacancy posting" << endl;
					cout << "F: Add a new user" << endl;
					cout << "G: Remove an existing student" << endl;
					cout << "H: Print all users" << endl;
				}
				cout << "Enter your choice: ";
				getline(cin, input);
				int numInput = 0;
				char cInput;
				string sInput[5] = { "", "", "", "", "" };
				// These if and else if statements will control which function is being used


				if (input == "1") // View the Time Table
				{
					ViewTimetable();
				}


				else if (input == "2") // Save and Exit Program
				{
					saveUsers(userList);
					saveVacs(vacList);
					saveCourse(courseList);
					program = 0;
					current = NULL;
				}


				else if (input == "3") // View Personal Attendance for a class
				{
					cout << "Enter the name of the class you are taking attendance for: ";
					getline(cin, sInput[0]);
					printAttendence(courseList, sInput[0], (*current).get_ID());
				}


				else if (input == "4") // View the user Submission
				{
					takeSubmission((*current));
				}


				else if (input == "5") // View Vacanies
				{
					int i = 0;
					for (list<vacancy>::iterator it = vacList.begin(); it != vacList.end(); ++it)
					{
						if (it->get_position() != "Temp")
						{
							cout << it->get_position() << endl << it->get_description() << endl;
							i = 1;
						}
					}
					if (i == 0)
					{
						cout << "There are no current vacancies" << endl;
					}
				}


				else if (input == "6") // View Attendance of a student
				{
					cout << "Enter the name of the class you are taking attendance for: ";
					getline(cin, sInput[0]);
					cout << "Enter the ID of the student you want to view: ";
					cin >> numInput;
					cin.ignore();
					printAttendence(courseList, sInput[0], numInput);
				}


				else if (input == "7") // Join a class
				{
					cout << "Enter the Title of the course: ";
					getline(cin, sInput[0]);
					joinCourse(courseList, userList, sInput[0], (*current));
				}

				else if (input == "8") // drop a course
				{
					cout << "Enter the Title of the course: ";
					getline(cin, sInput[0]);
					dropCourse(courseList, userList, sInput[0], (*current));
				}


				else if (input == "9") // change the users password
				{
					changePassword((*current));
				}


				else if (input == "A") //Enter a new course
				{
					if ((*current).get_group() == 'S')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						cout << "Enter the Title of the new course: ";
						getline(cin, sInput[0]);
						if (hasAChar(sInput[0], "/"))
						{
							cout << "You may not enter a course with /" << endl;
						}
						else
						{
							if (hasAChar(sInput[0], "|"))
							{
								cout << "You may not enter a course with |" << endl;
							}
							else
							{
								newCourse(courseList, sInput[0]);
							}
						}
					}
				}


				else if (input == "B") // Update a time in the Timetable
				{
					if ((*current).get_group() == 'S')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
						StoreTimetable();
				}


				else if (input == "C") // Take Attendance
				{
					if ((*current).get_group() == 'S')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
						take_attendence(courseList, (*current));
				}


				else if (input == "D") // Enter a new vacancy 
				{
					if ((*current).get_group() != 'A')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						printf("Enter the position of the new vacancy: ");
						getline(cin, sInput[0]);
						if (hasAChar(sInput[0], "/"))
						{
							cout << "You may not enter a vacancy with /" << endl;
						}
						else
						{
							printf("Enter the description of the new vacancy: ");
							getline(cin, sInput[1]);
							if (hasAChar(sInput[1], "/"))
							{
								cout << "You may not enter a description with /" << endl;
							}
							else
							{
								newVacancy(vacList, sInput[0], sInput[1]);
							}
						}
					}
				}


				else if (input == "E") // Remove a vacancy
				{
					if ((*current).get_group() != 'A')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						cout << "Enter the position of the vacancy you would like to remove: ";
						getline(cin, sInput[1]);
						removeVacancy(vacList, sInput[1]);
					}
				}


				else if (input == "F") // New User 
				{
					if ((*current).get_group() != 'A')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						cout << "Enter the new user's ID (must be an integer): ";
						cin >> numInput;
						cin.ignore();
						cout << "Enter the new user's password: ";
						getline(cin, sInput[1]);
						if (hasAChar(sInput[1], "/"))
						{
							cout << "You may not enter a password with /" << endl;
						}
						else if (sInput[1].length() < 4)
						{
							cout << "A password must be at least four characters long" << endl;
						}
						else
						{
							cout << "Enter the new user's first name: ";
							getline(cin, sInput[2]);
							if (hasAChar(sInput[2], "/"))
							{
								cout << "You may not enter a first name with /" << endl;
							}
							else
							{
								cout << "Enter the new user's last name: ";
								getline(cin, sInput[3]);
								if (hasAChar(sInput[3], "/"))
								{
									cout << "You may not enter a last name with /" << endl;
								}
								else
								{
									cout << "Enter the new user's permissions (A = Admin, F = Faculty, S = Student): ";
									cin >> cInput;
									cin.ignore();
									if (cInput == 'A' || cInput == 'F' || cInput == 'S')
									{
										newUser(userList, numInput, sInput[1], sInput[2], sInput[3], cInput);
									}
									else
									{
										cout << "The users permissions must be A, F, or S" << endl;
									}
								}
							}
						}
					}
				}


				else if (input == "G") // Remove a student
				{
					if ((*current).get_group() != 'A')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						cout << "Enter the ID of the student you would like to remove: ";
						cin >> numInput;
						cin.ignore();
						removeUser(userList, numInput);
					}
				}


				else if (input == "H") // print all users
				{
					if ((*current).get_group() != 'A')
					{
						cout << "You do not have permission to do this." << endl;
					}
					else
					{
						for (list<user>::iterator it = userList.begin(); it != userList.end(); ++it)
						{
							cout << "ID:		" << it->get_ID() << "\nPassword:	" << it->get_password() << "\nFirst:		" << it->get_firstName() << "\nLast:		" << it->get_lastName() << "\nGroup:		" << it->get_group() << endl << endl;
						}
					}
				}


				else
					cout << "Invalid Input! Please select an input from the menu!" << endl;
			}
		}

		else if (subChoice == "3")
			return;
		else
			cout << "Invalid input! Please select an input from the menu!" << endl;
	}
}
