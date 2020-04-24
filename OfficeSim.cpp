#include <string>
#include <iostream>
#include "OfficeSim.h"

void OfficeSim::setFileName(string input)
{
  fileName = input;
}

void OfficeSim::start()
{
  ifstream inFS;
  inFS.open(fileName);
  while(!inFS)
  {
    inFS.close();
    cout << "That file could not be found. Please enter another one." << endl;
    cin >> fileName;
    inFS.open(fileName);
  }
  string nextStr = "";
  int nextInt;
  char c;
  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    if(c == '\n')
    {
      if(nextStr != "")
      {
        nextInt = stoi(nextStr);
        fileValues.insert(nextInt);
      }
      nextStr = "";
      nextInt = 0;
    }
    else if(isdigit(c))
    {
      nextStr += c;
    }
  }
}

void OfficeSim::simulate()
{
  //find the number of windows
  numWindows = fileValues.removeFront();

  //finds the first time to insert students
  nextTime = fileValues.removeFront();

  //make a list of the number of windows (can you do this CAM)
  for(int i = 0; i < numWindows; ++i)
  {
    Window(0) w; //time left of 0 to start
    windows.insert(w);
  }

  while(!exitCheck)
  {
    //do all the checks here
    if(time = nextTime)
    {
      numStudents = fileValues.removeFront();
      for(int i = 0; i < numStudents; ++i)
      {
        Student(fileValues.removeFront()) s; //new student with window time set
        line.insert(s);
      }
      nextTime = fileValues.removeFront(); //gets the next time to check
    }
    for(int i = 0; i < windows.size(); i++) //all windows
    {
      if(w.getRemainderTime() == 0) //if a window is empty
      {
        emptyWindows = emptyWindows + 1;
      }
    }
    if(emptyWindows == windows.size() && fileValues.isEmpty() && line.isEmpty()) //all windows empty, no students left
    {
      exitCheck = true;
    }
    else
    {
      for(int i = 0; i < windows.size(); i++) //all windows
      {
        if(w.getRemainderTime() != 0) //if a window is not empty
        {
          w.setRemainderTime(w.getRemainderTime()-1);
        }
        else if(w.getRemainderTime() == 0 && !line.isEmpty()) //if a window is empty, and the line is not empty
        {
          w.setRemainderTime(line.removeFront());
        }
        else //if a window is empty and there is no one in line
        {
          w.setTimeIdle(w.getTimeIdle()+1);
        }
      }
    }
    time = time + 1;
  }
}
