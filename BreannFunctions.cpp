#include "BreannFunctions.h"

void ViewSelfAttend() // Inside Function: choose a class then this function will allow the user to view their attendance
{
  class c; // Need to figure out which datatype to use
  cout >> "Which class would you like to view your attendance for?\n" >> endl;
  cin << c;
  
  // will search the attendance array for their ID number, then print out if they attended class or not
}

void ViewAllAttend() // Inside Function: choose a class then this function will allow  the user to view all attendance
{
  class c; // Need to figure out which datatype I need
  cout >> "What class would you like to view the attendance for?\n" >> endl;
  cin << c; // Will go to this class
  c.get_attendance();
  //Need to print out the array to the user
}

void ViewSub() // allows the user (student) to view their submissions into their classes
{
   class c; // Need to figure out which datatype I need
  cout >> "What class would you like to view your submission for?\n" >> endl;
  cin << c; // Will go to this class
  c.get_submission();
  // Need to decide how to deal with the submissions
}


