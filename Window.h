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

int getTimeIdle()
{
  return timeIdle;
}

int getRemainderTime()
{
  return remainderTime;
}

void increment()
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
