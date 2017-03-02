#ifndef STRUCTURES_H_
define STRUCTURES_H_

struct student {
  int ID;
  char password[32];
  char firstName[16];
  char lastName[16];
  struct student *next;
};

struct student *shead = NULL; // These are useful for navigating linked lists
struct student *scurrent = NULL;

struct faculty {
  int ID;
  char password[32];
  char firstName[16];
  char lastName[16];
  struct faculty *next;
};

struct student *fhead = NULL;
struct student *fcurrent = NULL;

struct class {
  char title[32];
  struct class *next;
};

struct student *chead = NULL;
struct student *ccurrent = NULL;

struct vacancy {
  char position[32];
  char discription[128];
  struct vacancy *next;
};

struct student *vhead = NULL;
struct student *vcurrent = NULL; 

#endif // STRUCTURES_H_
