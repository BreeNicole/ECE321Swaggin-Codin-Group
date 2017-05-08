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
	char group; // S (student), F (faculty), A (admin)
public:
	user::user(int a, string b, string c, string d, string e, char f);
	user::user();
	void setUser(int a, string b, string c, string d, string e, char f);
	int get_ID();
	string get_firstName();
	string get_lastName();
	string get_password();
	char get_group();
	string get_classList();
	void set_password(string newPass);
	void set_classList(string a);
};

class course {
	string title;
	string attendance; // ID number goes in the first column, then it will say 1 for present or 2 for not present in the 2nd column
public:
	course::course(string a, string b);
	course::course(string a);
	void setCourse(string a, string b);
	string get_title();
	string get_attendance();
	void setAttendance(string a);
};

class vacancy {
	string position;
	string discription;
public:
	vacancy::vacancy(string a, string b);
	void setVacancy(string a, string b);
	string get_position();
	string get_description();
};


#endif // STRUCTURES_H_

