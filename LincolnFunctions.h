#include "structures.h"
#include <list>

#ifndef LINCOLNFUNCTIONS_H_
#define LINCOLNFUNCTIONS_H_


list<user> readUsers();
list<course> readCourses();
list<vacancy> readVacs();
void saveUsers(list<user> saveUser);
void saveCourse(list<course> saveCourse);
void joinCourse(list<course>& courseList, string title, int ID);
void newVacancy(list<vacancy>& vacList, string positionIn, string discriptionIn);
void newUser(list<user>& userList, int ID, string password, string firstName, string lastName, char group);
void removeVacancy(list<vacancy>& vacList, string del);
void removeUser(list<user>& userList, int ID);
void saveVacs(list<vacancy> saveVac);
void take_attendence(list<course> courses, user current);
void printAttendence(list<course>, string courseTitle, int ID);
void takeSubmission(user current);
void changePassword(user &current);

#endif // LINCOLNFUNCTIONS_H_
