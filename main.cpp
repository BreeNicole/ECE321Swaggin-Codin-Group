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
	
	int program = 0;
	string posIn, disIn;

	while (program == 0)
	{
		program = logIn(list<user>);
	}


	while (program == 1)
	{

		posIn = "";
		disIn = "";
		char input;
		cout << "1: Print users" << endl;
		cout << "2: Save and Exit" << endl;
		cout << "3: View Timetable (in progress)" << endl;
		cout << "4: View your attendance (in progress)" << endl;
		cout << "5: View all attendance (in progress)" << endl;
		cout << "6: View submissions (in progress)" << endl;
		cout << "7: View Vacancies (in progress)" << endl;
		cout << "8: Input attendance (in progress) [This function is currently acting as exit without saving for testing]" << endl;
		cout << "9: Update Timetable (in progress)" << endl;
		cout << "A: Update attendance (in progress)" << endl;
		cout << "B: Post vacancy" << endl;
		cout << "C: View details of student (in progress)" << endl;
		cout << "D: Print Vacanies" << endl;
		cout << "E: Add a new student" << endl;
		cout << "F: Remove an existing student" << endl;
		cout << "G: Remove a current vacancy posting" << endl;
		printf("Enter your choice: ");
		do
		cin >> input;
		while (isspace(input));
		cin.clear();
		list <user>::iterator it = userList.begin();
		int numInput;
		char cInput;
		string sInput[5];
		switch (input) {

		case '1':
			printf("Run Function 1\n"); // Right now it just prints the first entry in the list
			for (list<user>::iterator it = userList.begin(); it != userList.end(); ++it)
			{
				cout << it->get_ID() << " ID\n" << it->get_password() << " password\n" << it->get_firstName() << " First\n" << it->get_lastName() << " Last\n" << it->get_group() << endl;
			}
			break;

		case '2':
			printf("Run Function 2\n"); //Logout, save, and exit
			saveUsers(userList);
			saveVacs(vacList);
			program = 0;
			break;

		case '3':
			printf("Run Function 3\n"); //View Timetable (student)
			break;

		case '4':
			printf("Run Function 4\n"); //View Personal Attendance (student)
			//ViewSelfAttend();
			//Takes the user input and allows them to view their personal attendance
			break;

		case '5':
			printf("Run Function 5\n"); //View all attendance (student)
			//ViewAllAttend();
			// will take the class the user inputs and run the attendance function
			break;

		case '6':
			printf("Run Function 6\n"); //View Submissions (student)
			break;

		case '7':
			printf("Run Function 7\n"); //View Vacancies (student)
			cout >> "Starting to print all available vacanies.....\n Please Wait...\n >> endl;
			readVacs();
			break;

		case '8':
			printf("Run Function 8\n"); //Input Student Attendance (Faculty)
			program = 0;
			break;

		case '9':
			printf("Run Function 9\n"); //Update Timetable (Admin)
			//void StoreTimetable();
			break;
		case 'A':
			printf("Run Function A\n"); //Update Student Attendance (Faculty)
			printf("Which class are you updating attendance for?\n");
			// User input which class to go to
			// will send the class to the function along with the array of attendance to update
			// int * a=class.get_attendance(); will get the attendance for the function
			//setAttendance(class c, int * a);
			break;

		case 'B':
			printf("Run Function B\n"); //Post vacancies (Admin)
			cin.ignore();
			printf("Enter the position of the new vacancy");
			getline(cin,posIn);
			printf("Enter the discription of the new vacancy");
			getline(cin,disIn);
			newVacancy(vacList, posIn, disIn);

			break;

		case 'C':
			printf("Run Function C\n"); //view Details of students (Faculty)
			break;

		case 'D':
			printf("Run Function D\n");

			for (list<vacancy>::iterator it = vacList.begin(); it != vacList.end(); ++it)
			{
				cout << it->get_position() << endl << it->get_description() << endl;
			}

			break;

		case 'E':
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

		case 'F':
			cout << "Enter the ID of the student you would like to remove: ";
			cin >> numInput;
			removeUser(userList, numInput);
			break;

		case 'G':
			cout << "Enter the position of the vacancy you would like to remove: ";
			cin.ignore();
			getline(cin, sInput[1]);
			removeVacancy(vacList, sInput[1]);
			break;
		default:
			printf("Invalid input\n");

		}
	}
}

