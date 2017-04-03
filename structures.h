#ifndef STRUCTURES_H_
define STRUCTURES_H_

class user {
  int ID;
  string password;
  string firstName;
  string lastName;
  char group; // S (student), F (faculty)
public:
  user(int a, string b, string c, string d, char e)
  {
    ID = a;
    password = b;
    firstName = c;
    lastname = d;
    group = e;
  }
  get_ID();
  {
    return ID;
  }
  get_firstName()
  {
    return firstName;
  }
  get_lastName()
  {
    return lastName;
  }
  get_group()
  {
    return group;
  }
};

class course {
  string title;
  string attendance [30][2]; // ID will go in [x][1], (present / notpresent) will go in [x][2], this allots for 30 people in each class (we might need more)
public:
  course(string a, string b[30][2])
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
