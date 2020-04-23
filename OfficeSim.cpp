#include "OfficeSim.h"

void OfficeSim::setFileName(string input)
{
  fileName = input;
}

void OfficeSim::start()
{
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
  // simulate(); implement a simulate method here
}
