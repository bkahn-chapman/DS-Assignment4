#include "Student.h"


Student::Student(int input)
{
  timeAtWindow = input;
}

void Student::setWindowTime(int input)
{
  timeAtWindow = input;
}

int Student::getWindowTime()
{
  return timeAtWindow;
}

void Student::setTimeInQueue(int input)
{
  timeInQueue = input;
}

int Student::getTimeInQueue()
{
  return timeInQueue;
}
