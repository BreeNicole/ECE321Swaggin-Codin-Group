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
	
	outfile << "Month" << "/" << "Day" << "/" << "Test Time" << "/" << "Class Name" << "/" << "Description" << endl;
	outfile << month << "/" << day << "/" << "/" << testtime << "/" << class_name << "/" << description << endl;
	outfile << endl;
	outfile.close();
	cout << "Exam submitted!" << endl;
};

void ViewTimetable()
{
	string dataArray[6];
	string info;
	size_t pos = 0;
	string line;
	int i = 0;

	ifstream infile;
	infile.open("TimeTable.txt");
	if (!infile.is_open())
	{
		cout << "Error. Could not open file." << endl;
		return;
	}
	while (getline(infile, line))
	{
		while (pos = line.find("/") != string::npos)
		{
			info = line.substr(0, pos);
			dataArray[i] = info;
			line.erase(0, pos+1);
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
