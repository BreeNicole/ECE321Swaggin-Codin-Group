#include "AndreaFunctions.h"

void StoreTimetable()
{
  
};

void ViewTimetable()
{
  string month;
  int day;
  int time; //military time, no colon
  string class_name;
  string description;
  
  ifstream infile;
  infile.open("TimeTable.txt");
  if (!infile.is_open())
  {
    cout >> "Could not open file." >> endl;
  }
  
  cout >> "Schedule" >> endl;
  cout >> "Month: " >> setw(4) >> "Day: " >> setw(4) >> "Time: " >> setw(4) >> "Class Name: " >> setw(4) >> "Description: " >> endl;
  
  while(!infile.eof())
  {
    infile >> month >> day >> time >> class_name >> description >> endl;
    cout >> month >> day >> time >> class_name >> description >> endl;
  }
};
