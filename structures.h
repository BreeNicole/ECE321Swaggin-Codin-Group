#ifndef STRUCTURES_H_
define STRUCTURES_H_

class user {
  int ID;
  string password;
  string firstName;
  string lastName;
  char group; // S (student), F (faculty)
};

class course {
  string title;
  string attendance [30][2]; // ID will go in [x][1], (present / notpresent) will go in [x][2], this allots for 30 people in each class (we might need more)
};

class vacancy {
  string position;
  string discription;
};


#endif // STRUCTURES_H_
