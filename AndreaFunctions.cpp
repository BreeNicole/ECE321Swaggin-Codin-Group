#include "AndreaFunctions.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
using namespace std;

void StoreTimetable()
{
	string month;
	int day;
	int testtime; //military time, no colon
	string class_name;
	string description;

	ofstream outfile;
	outfile.open("TimeTable.txt", ofstream::app);

	if (!outfile.is_open())
	{
		cout << "Error. Could not open file." << endl;
		return;
	}
	cout << "Enter the month: ";
	cin >> month;
	while (outfile.is_open())
	{
		if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December")
		{
			break;
		}
		else
		{
			cout << "You entered an invalid month. Please try again." << endl;
			cin >> month;
		}
	}
	cout << "Enter the day: ";
	cin >> day;
	while (day != NULL)
	{
		if (day > 0 || day <= 31)
		{
			break;
		}
		else
		{
			cout << "You entered an invalid day. Please try again." << endl;
			cin >> day;
		}
	}
	cout << "Enter the time in military time (exclude the colon): ";
	cin >> testtime;
	while (testtime != NULL)
	{
		if (testtime >= 0000 || testtime <= 2359)
		{
			break;
		}
		else
		{
			cout << "You entered an invalid test time. Please try again." << endl;
			cin >> testtime;
		}
	}
	cout << "Enter the name of the class: ";
	cin >> class_name;
	cout << "Enter short description, no spaces (ex. Exam1): ";
	cin >> description;
	
	outfile << month << "/" << day << "/" << testtime << "/" << class_name << "/" << description << endl;
	outfile.close();
	cout << "Success!" << endl;
};

void ViewTimetable()
{
	string dataArray[6];
	string info;
	size_t pos = 0;
	string line;
	int i = 0;

	ifstream infile;
	infile.open("TimeTable.txt", ifstream::in | ifstream::out);
	if (!infile.is_open())
	{
		cout << "Error. Could not open file." << endl;
		return;
	}
	while (getline(infile, line))
	{
		while ((pos = line.find("/")) != string::npos)
		{
			info = line.substr(0, pos);
			dataArray[i] = info;
			line.erase(0, pos + 1);
			++i;
		}
		i = 0;
		int dataOne = atoi(dataArray[1].c_str());
		int dataTwo = atoi(dataArray[2].c_str());
		char dataSix = line[0];
		cout << dataArray[0] << "/" << dataOne << "/" << dataTwo << "/" << dataArray[3] << "/" << dataArray[4] << "/" << dataArray[5] << "/" << dataSix << endl;
	}
	infile.close();
};
