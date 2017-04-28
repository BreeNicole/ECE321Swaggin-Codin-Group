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
  user::user()
  {
	  ID = 0;
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
  void set_password(string newPass)
  {
	  password = newPass;
  }
  void set_classList(string a)
  {
	  classList = a;
  }
};

class course {
	string title;
	string attendance; // ID number goes in the first column, then it will say 1 for present or 2 for not present in the 2nd column
	string submission; // may change from string (I dont know how we want to deal with this)
public:
	course::course(string a, string b, string c)
	{
		setCourse(a, b, c);
	}
	course::course(string a)
	{
		title = a;
	}
	void setCourse(string a, string b, string c)
	{
		title = a;
		attendance = c;
		submission = b;
	}
	string get_title()
	{
		return title;
	}
	string get_submission()
	{
		return submission;
	}
	string get_attendance()
	{
		return attendance;
	}
	void setAttendance(string a)
	{
		attendance = a;
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

