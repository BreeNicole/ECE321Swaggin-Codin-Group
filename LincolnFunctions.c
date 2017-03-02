#include "LincolnFunctions.h"

int run(int x)
{
  return x + 5;
}

void newVacancy()
{
  char posIn[32], disIn[128];
  printf("Enter the position of the new vacancy (32 char limit)");
  gets(posIn);
  printf("Enter the discription of the new vacancy (128 char limit)");
  gets(disIn);
  struct vacancy *link = (struct vacancy*)malloc(sizeof(struct(vacancy));
  link->position = posIn;
  link->discription = disIn;
  link->next = *vhead;
  head = link;
}
