#include <iostream>
#include <list>
#include <iterator>
#include <string>

#include "structures.h"
#include "LincolnFunctions.h"
#include "BreannFunctions.h"
#include "AndreaFunctions.h"
#include "SarahFunctions.h"

using namespace std;

void main()
{
	cout << "This is the best program, all others are bad" << endl;
	int num = 3;
	int z = add(num, 3); // This will set z to be num + 5, since the run fuction adds five to whatever number it is passed
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
		switch (input) {

		case '1':
			printf("Run Function 1\n");
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

void readfile() // This function will read the file and input the data in to the program. The .txt file should be saved in a particular order, depending on the type of structure it is
{
	string line;
	ifstream infile;
	int i = 0;
	string dataArray[5]
	size_t pos = 0;
	string token;
	infile.open("users.txt");
	if(infile.is_open())
	{
		while( getline (infile,line))
		{
			while(( pos = s.find("/")) != npos)
			{
				token = line.substr(0,pos);
				dataArray[i] = token;
				s.erase(0,pos + 1);
				++i;
			}
			
		}
		infile.close();
	}
	else
	{
		cout << "File fialed to open" << endl;
	}
}

void savefile()
{

}
