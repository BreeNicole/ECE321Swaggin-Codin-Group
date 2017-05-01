#include "AndreaFunctions.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void StoreTimetable()
{
	string month; //month of the exam
	int day; //day of the exam
	int testtime; //military time, no colon
	string class_name; //name of the class

	ofstream outfile;
	outfile.open("TimeTable.txt", ofstream::app);

	if (!outfile.is_open()) //this will stop the function if the file couldn't be opened
	{
		cout << "Error. Could not open file." << endl;
		return;
	}
	cout << "Enter the month: ";
	cin >> month;
	cin.ignore();
	while (outfile.is_open()) //this makes sure you actually entered the name of a month
	{
		if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December")
		{
			break;
		}
		else
		{
			cout << "You entered an invalid month. Please try again." << endl;
			cin >> month;
			cin.ignore();
		}
	}
	cout << "Enter the day: ";
	cin >> day;
	cin.ignore();
	while (day != NULL)
	{
		if(month == "February")
		{
			if (day > 0 || day <= 28) //this ensures that you entered a valid day for February, ignoring the chance of it being a leap year
			{
				break;
			}
			else
			{
				cout << "You entered an invalid day. Please try again." << endl;
				cin >> day;
				cin.ignore();
			}
		}
		else if (month == "January" || month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December")
		{
			if (day > 0 || day <= 31) //this ensures that you entered a valid day for months with 31 days
			{
				break;
			}
			else
			{
				cout << "You entered an invalid day. Please try again." << endl;
				cin >> day;
				cin.ignore();
			}
		}
		else
		{
			if (day > 0 || day <= 30) //this ensures that you entered a valid day for months with 30 days
			{
				break;
			}
			else
			{
				cout << "You entered an invalid day. Please try again." << endl;
				cin >> day;
				cin.ignore();
			}
		}
	}
	cout << "Enter the time in military time (exclude the colon): ";
	cin >> testtime;
	cin.ignore();
	while (testtime != NULL)
	{
		if (testtime >= 0000 || testtime <= 2359) //ensures the user entered a valid time
		{
			break;
		}
		else
		{
			cout << "You entered an invalid test time. Please try again." << endl;
			cin >> testtime;
			cin.ignore();
		}
	}
	cout << "Enter the name of the class: ";
	cin >> class_name;
	cin.ignore();

	outfile << month << "/" << day << "/" << testtime << "/" << class_name << endl;
	outfile.close();
	cout << "Success!" << endl;
};

void ViewTimetable()
{
	string dataArray[5];
	string info;
	size_t pos = 0;
	string line;
	string dataSix;
	int i = 0;

	ifstream infile;
	infile.open("TimeTable.txt", ifstream::in | ifstream::out);
	if (!infile.is_open()) //exits the function if the file didn't open
	{
		cout << "Error. Could not open file." << endl;
		return;
	}
	while (getline(infile, line)) //this reads the file
	{
		while ((pos = line.find("/")) != string::npos) //when it reaches a / it stops reading
		{
			info = line.substr(0, pos); //this stores the read info
			dataArray[i] = info;
			line.erase(0, pos + 1); //this deletes what was just read, plus the /
			++i;
		}
		i = 0;
		int dataOne = atoi(dataArray[1].c_str());
		int dataTwo = atoi(dataArray[2].c_str());
		string dataFive = line;
		cout << dataArray[0] << "/" << dataOne << "/" << dataTwo << "/" << dataArray[3] << dataArray[4] << dataFive << endl;
	}
	infile.close();
};
