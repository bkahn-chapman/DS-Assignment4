#include <iostream>

using namespace std;

class Window
{
  int timeIdle;
  int remainderTime;

  Window(int input);
  void increment();

  void setTimeIdle(int input);
  void setRemainderTime(int input);
  int getTimeIdle();
  int getRemainderTime();
};

Window::Window(int input)
{
  remainderTime = input;
}

void Window::setTimeIdle(int input)
{
  timeIdle = input;
}

void Window::setRemainderTime(int input)
{
  remainderTime = input;
}

int Window::getTimeIdle()
{
  return timeIdle;
}

int Window::getRemainderTime()
{
  return remainderTime;
}

void Window::increment() //decreases remainder time, or increases idle time if a student is present
{
  if(remainderTime != 0)
  {
    remainderTime--;
  }
  else if(remainderTime == 0)
  {
    timeIdle++;
  }
  else
  {
    cout << "problem with window logic" << endl;
  }
}
