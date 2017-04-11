#ifndef STRUCTURES_H_
#define STRUCTURES_H_

using namespace std;

class user {
  int ID;
  string password;
  string firstName;
  string lastName;
  char classList[5]; //Will store the class list for the student
  char group; // S (student), F (faculty)
public:
  user::user(int a, string b, string c, string d, char e)
	{
		setUser(a, b, c, d, e);
	}
  void setUser(int a, string b, string c, string d, char e)
  {
    ID = a;
    password = b;
    firstName = c;
    lastName = d;
    group = e;
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
};

class course {
  string title;
  int attendance[30][2]; // ID number goes in the first column, then it will say 1 for present or 2 for not present in the 2nd column
  string submission; // may change from string (I dont know how we want to deal with this)
public:
  course(string a)
  {
   title = a;
	  // Will need to find a way to set the students into the course
  }
  setAttendance(int *a) // Faculty function for their class attendance 
  {
   for(int i = 0; i < 30 && a[i][0] != NULL; i++)
   {
	   cout << "Was " << a[i][0] << "in class today? Press 1 for Present and 2 for Not Present. \n" << endl;
	   cin << a[i][1];
   }
	  return a;
  }
  viewAttendance() // will allow us to return the full attendance for a class.
  {
	return attendance;
  }
};

class vacancy {
  string position;
  string discription;
public:
  vacancy(string a, string b)
  {
    position = a;
    discription = b;
  }
};


#endif // STRUCTURES_H_
