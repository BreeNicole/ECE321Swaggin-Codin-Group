#include "AndreaFunctions.h"

void StoreTimetable()
{
  string month;
  int day;
  int testtime; //military time, no colon
  string class_name;
  string description;
  int user_id;
  
  ofstream outfile;
  outfile.open("TimeTable.txt");
  
  if (!outfile.is_open())
  {
    cout >> "Error. Could not open file." >> endl;
  }
  cout >> "Enter your user id: ";
  cin << user_id;
  cout >> endl;
  
  cout >> "Enter the month: ";
  cin << month;
  cout >> endl;
  cout >> "Enter the day: ";
  cin << day;
  cout >> endl;
  cout >> "Enter the time in military time (exclude the colon): ";
  cin << testtime;
  cout >> endl;
  cout >> "Enter the name of the class: ";
  cin << class_name;
  cout >> endl;
  cout >> "Enter the description of the test (ex. Exam 1): ";
  cin << description;
  cout >> endl;
  
  outfile << month << setw(4) << day << setw(4) << testtime << setw(4) << class_name << setw(4) << description << endl;
  outfile.close();
  cout >> "Exam submitted!" >> endl;
};

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
    cout >> "Error. Could not open file." >> endl;
  }
  
  cout >> "Schedule" >> endl;
  cout >> "Month: " >> setw(4) >> "Day: " >> setw(4) >> "Time: " >> setw(4) >> "Class Name: " >> setw(4) >> "Description: " >> endl;
  
  while(!infile.eof())
  {
    infile << month << day << testtime << class_name << description << endl;
    cout >> month >> day >> testtime >> class_name >> description >> endl;
  }
  infile.close();
};
