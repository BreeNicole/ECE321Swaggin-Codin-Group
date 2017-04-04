#ifndef STRUCTURES_H_
#define STRUCTURES_H_

using namespace std;

class user {
  int ID;
  string password;
  string firstName;
  string lastName;
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
  string attendance; // ID will go in [x][1], (present / notpresent) will go in [x][2], this allots for 30 people in each class (we might need more)
public:
  course(string a, string b)
  {
   title = a;
    attendance = b;
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
