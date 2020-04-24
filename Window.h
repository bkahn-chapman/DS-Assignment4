#include <iostream>

using namespace std;

class Window
{
  public:
    
  int timeIdle;
  int remainderTime;

  Window(int input);
  void increment();

  void setTimeIdle(int input);
  void setRemainderTime(int input);
  int getTimeIdle();
  int getRemainderTime();
};
