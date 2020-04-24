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
    if(mTime = nextTime)
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
      for(int i = 0; i < windows.size(); ++i) //all windows
      {
        if(w.getRemainderTime() != 0) //if a window is not empty
        {
          w.setRemainderTime(w.getRemainderTime()-1); //lowers the amount of time until the window is empty again
        }
        else if(w.getRemainderTime() == 0 && !line.isEmpty()) //if a window is empty, and the line is not empty
        {
          totalStudents = totalStudents + 1; //counts the student helped
          for(int i = 0; i < 1; ++i)
          {
            Student s = line.peek(); //gets the student at the front
            waitTimes.insert(s.getTimeIdle()); //adds their wait time in line to the list
          }
          w.setRemainderTime(line.removeFront()); //puts the next student in line at the window
        }
        else //if a window is empty and there is no one in line
        {
          w.setTimeIdle(w.getTimeIdle()+1); //makes the window's idle time increase by one
        }
      }
      for(int i = 0; i < line.size(); ++i) //all students still in line
      {
        s.setTimeInQueue(s.getTimeInQueue() + 1); //up their wait times
      }
    }
    mTime = mTime + 1;
  }
}

void OfficeSim::outputResults()
{
  int count = 0;
  ListNode<int> *curr = waitTimes.front;
  while(curr!=NULL)
  {
    curr = curr->next;
    count++;
  }
  curr = waitTimes.front;
  int medianArray[waitTimes];

  for(int i = 0; i < count; i++)
  {
    medianArray[i] = curr->data;
    curr = curr->next;
  }
  int f = sizeof(medianArray)/sizeof(medianArray[0]);
  sort(medianArray, medianArray+f);

  if(sizeof(medianArray)%2 != 0)
  {
    int middle;
    middle = count/2 + 1;
    studentMedian = medianArray[middle];
  }
  else if(sizeof(medianArray) % 2 == 0)
  {
    int n1;
    int n2;
    n1 = medianArray[count/2];
    n2 = medianArray[count/2] + 1;
    studentMedian = (double(n1) + double(n2))/2;
  }

  for(int i = 0; i < waitTimes.size(); ++i)
  {
    studentTemp = waitTimes.removeFront();
    if(studentTemp > studentLong) //long
    {
      studentLong = studentTemp;
    }
    if(studentTemp > 10) //over 10
    {
      studentTen = studentTen + 1;
    }
    studentMean = studentMean + studentTemp; //mean
  }
  studentMean = studentMean / totalStudents;
  cout << "1. The mean student wait time was: " << studentMean << " minutes." << endl;
  cout << "2. The median student wait time was: " << studentMedian << " minutes." << endl;
  cout << "3. The longest student wait time was: " << studentLong << " minutes." << endl;
  cout << "4. There were " << studentTen << " students waiting in line over 10 minutes." << endl;

  for(int i = 0; i < windows.size(); ++i)
  {
    windowTemp = waitTimes.removeFront();
    if(windowTemp.getTimeIdle() > windowLong) //long
    {
      windowLong = windowTemp;
    }
    if(windowTemp.getTimeIdle() > 5) //over 5
    {
      windowFive = windowFive + 1;
    }
    windowMean = windowMean + windowTemp; //mean
  }
  windowMean = windowMean / numWindows;

  cout << "5. The mean window idle time was: " << windowMean << " minutes." << endl;
  cout << "6. The longest window idle time was: " << windowLong << " minutes." << endl;
  cout << "7. There were " << windowFive << " windows idle for over 5 minutes." << endl;
}
