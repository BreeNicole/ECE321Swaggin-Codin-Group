#include "LincolnFunctions.h"

int run(int x)
{
  return x + 5;
}

void newVacancy(char posIn[32], char disIn[128])
{
  struct vacancy *link = (struct vacancy*)malloc(sizeof(struct(vacancy));
  link->position = posIn;
  link->discription = disIn;
  link->next = *vhead;
  head = link;
}
