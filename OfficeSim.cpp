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
      cout << "test" << endl;
      nextInt = stoi(nextStr);
      fileValues.insert(nextInt);
      nextStr = "";
      nextInt = 0;
    }
    else if(isdigit(c))
    {
      nextStr += c;
      cout << nextStr << endl;
    }
  }
  for(int i = 0; i < fileValues.size(); i++)
  {
    cout << fileValues.remove() << endl;
  }
  /*
  try
  {
    ifstream inFile;
    inFile.open(fileName);
    string line;

    int lineCount = 0;
    int windowCount = 0;
    int timeArrived = 0;
    int peopleArrived = 0;

    while(getline(inFile, line))
    {
      if(lineCount == 0)
      {
        windowCount = stoi(line); //reads number of windows
        cout << "windows: " << line << endl;
      }
      else if(lineCount == 1)
      {
        timeArrived = stoi(line); //reads at what time people arrive
        cout << "people time: " << line << endl;
      }
      else
      {
        peopleArrived = stoi(line); //reads number of people arrived
        cout << "people: " << line << endl;
        for(int i = 0; i < peopleArrived; i++) //loops through the people that will arrive at that time
        {
          getline(inFile, line);
          cout << "time: " << line << endl;
          // students->insert(new Student(timeArrived, stoi(line))); //adds a student with what time they enter
        }                                                         //and how much time needed at window
        lineCount = 0;
      }
      lineCount++;
    }
  }
  catch(FileNotFoundException e)
  {
    cout << e.what() << endl;
  }
  */
  // simulate(); implement a simulate method here
}
