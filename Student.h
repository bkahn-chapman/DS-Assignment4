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
