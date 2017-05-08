#include <string>
#include <iostream>
#include "structures.h"

using namespace std;


//------------------------------------------------------
//			User member functions
//------------------------------------------------------


user::user(int a, string b, string c, string d, string e, char f)
{
	setUser(a, b, c, d, e, f);
}

user::user()
{
	ID = 0;
}

void user::setUser(int a, string b, string c, string d, string e, char f)
{
	ID = a;
	password = b;
	firstName = c;
	lastName = d;
	classList = e;
	group = f;
}

int user::get_ID()
{
	return ID;
}

string user::get_firstName()
{
	return firstName;
}

string user::get_lastName()
{
	return lastName;
}

string user::get_password()
{
	return password;
}

char user::get_group()
{
	return group;
}

string user::get_classList()
{
	return classList;
}

void user::set_password(string newPass)
{
	password = newPass;
}

void user::set_classList(string a)
{
	classList = a;
}


//------------------------------------------------------
//			Course member functions
//------------------------------------------------------


course::course(string a, string b)
{
	setCourse(a, b);
}

course::course(string a)
{
	title = a;
}

void course::setCourse(string a, string b)
{
	title = a;
	attendance = b;
}

string course::get_title()
{
	return title;
}

string course::get_attendance()
{
	return attendance;
}

void course::setAttendance(string a)
{
	attendance = a;
}


//------------------------------------------------------
//			Vacany member functions
//------------------------------------------------------


vacancy::vacancy(string a, string b)
{
	setVacancy(a, b);
}

void vacancy::setVacancy(string a, string b)
{
	position = a;
	discription = b;
}

string vacancy::get_position()
{
	return position;
}

string vacancy::get_description()
{
	return discription;
}