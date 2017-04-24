#include <string>
#include <iostream>

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

using namespace std;

class user {
  int ID;
  string password;
  string firstName;
  string lastName;
  string classList; //Will store the class list for the student
  char group; // S (student), F (faculty)
public:
  user::user(int a, string b, string c, string d, string e, char f)
	{
		setUser(a, b, c, d, e, f);
	}
  void setUser(int a, string b, string c, string d, string e, char f)
  {
    ID = a;
    password = b;
    firstName = c;
    lastName = d;
    classList = e;
	group = f;
  }
  int get_ID()
  {
    return ID;
  }
  string get_firstName()
  {
    return firstName;
  }
  string get_lastName()
  {
    return lastName;
  }
  string get_password()
	{
	return password;
	}
  char get_group()
  {
    return group;
  }
  string get_classList()
  {
	  return classList;
  }
};

class course {
	string title;
	int attendance[30][2]; // ID number goes in the first column, then it will say 1 for present or 2 for not present in the 2nd column
	string submission; // may change from string (I dont know how we want to deal with this)
public:
	course::course(string a, string b, int c[30][2])
	{
		setCourse(a, b, c);
	}
	void setCourse(string a, string b, int c[30][2])
	{
		title = a;
		submission = b;
		memcpy(c, attendance, sizeof(c));
	}
	string get_title()
	{
		return title;
	}
	string get_submission()
	{
		return submission;
	}
	int * get_attendance() // How would I return the whole array?
	{
		return attendance;
	}
	void get_course(int * setData)
	{
		memcpy(attendance, &setData, sizeof(attendance));
	}
  	int * setAttendance(class c, int *a) // Faculty function for their class attendance 
  	{
	   for(int i = 0; i < 30 && a[i][0] != NULL; i++)
  	 {
	   cout << "Was " << a[i][0] << "in class today? Press 1 for Present and 2 for Not Present. \n" << endl;
	   cin << a[i][1];
  	 }
	  return a;
  	}
};

class vacancy {
	string position;
	string discription;
public:
	vacancy::vacancy(string a, string b)
	{
		setVacancy(a, b);
	}
  void setVacancy(string a, string b)
	{
		position = a;
		discription = b;
	}
	string get_position()
	{
		return position;
	}
	string get_description()
	{
		return discription;
	}
};


#endif // STRUCTURES_H_
