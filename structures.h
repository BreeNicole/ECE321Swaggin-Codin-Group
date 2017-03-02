#ifndef STRUCTURES_H_
define STRUCTURES_H_

struct student {
  int ID;
  char password[32];
  char firstName[16];
  char lastName[16];
  struct student *next;
};

struct faculty {
  int ID;
  char password[32];
  char firstName[16];
  char lastName[16];
  struct faculty *next;
};

struct class {
  char title[32];
  struct class *next;
};

struct vacancy {
  char position[32];
  char discription[128];
  struct vacancy *next;
};

#endif // STRUCTURES_H_
