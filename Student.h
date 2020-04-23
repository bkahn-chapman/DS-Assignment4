#include <iostream>

using namespace std;

class Student
{
  public:
    int timeAtWindow;
    int timeInQueue;
    Student(int input);
    void setWindowTime(int input);
    int getWindowTime();
    void setTimeInQueue(int input);
    int getTimeInQueue();
};

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
  setTimeInQueue = input;
}

int Student::getTimeInQueue()
{
  return setTimeInQueue;
}
