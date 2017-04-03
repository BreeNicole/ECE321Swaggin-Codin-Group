#ifndef STRUCTURES_H_
define STRUCTURES_H_

struct student {
  int ID;
  string password;
  string firstName;
  string lastName;
  struct student *next;
};

struct student *shead = NULL; // These are useful for navigating linked lists
struct student *scurrent = NULL;

struct faculty {
  int ID;
  string password;
  string firstName;
  string lastName;
  struct faculty *next;
};

struct student *fhead = NULL;
struct student *fcurrent = NULL;

struct class {
  string title;
  char roster[30][32]; // we need struct inside this struct to keep track of attendance???
  struct class *next;
};

struct student *chead = NULL;
struct student *ccurrent = NULL;

struct vacancy {
  string position;
  string discription;
  struct vacancy *next;
};

struct student *vhead = NULL;
struct student *vcurrent = NULL; 

#endif // STRUCTURES_H_
