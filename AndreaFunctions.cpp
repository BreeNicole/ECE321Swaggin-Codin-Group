#include "AndreaFunctions.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void StoreTimetable()
{
	string month;
	int day;
	int testtime; //military time, no colon
	string class_name;
	string description;

	ofstream outfile;
	outfile.open ("TimeTable.txt", ofstream::app);

	if (!outfile.is_open())
	{
		cout << "Error. Could not open file." << endl;
	}
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the day: ";
	cin >> day;
	cout << "Enter the time in military time (exclude the colon): ";
	cin >> testtime;
	cout << "Enter the name of the class: ";
	cin >> class_name;
	cout << "Enter the description of the test, no spaces (ex. Exam1): ";
	cin >> description;
	
	outfile << "Month" << " " << setw(12) << "Day" << " " << setw(12) << "Test Time" << " " << setw(12) << "Class Name" << " " << setw(12) << "Description" << endl;
	outfile << month << setw(12) << day << setw(12) << testtime << setw(12) << class_name << setw(12) << description << endl;
	outfile << endl;
	outfile.close();
	cout << "Exam submitted!" << endl;
};
/* Have not gotten this function to work yet, Need to fix the infile
void ViewTimetable()
{
string month;
int day;
int testtime; //military time, no colon
string class_name;
string description;

ifstream infile;
infile.open("TimeTable.txt");
if (!infile.is_open())
{
cout << "Error. Could not open file." << endl;
return;
}
while (getline(infile, line))
{
while (position = line.find("\n")) != string::npos)
{

}
}
infile.close();

};
*/
