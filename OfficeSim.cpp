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
  cout << fileValues.size() << endl;
  int thing = fileValues.size();
  for(int i = 0; i < thing; i++)
  {
    cout << fileValues.removeFront() << endl;
  }
}
