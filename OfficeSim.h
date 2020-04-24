#include "FileNotFoundException.h"
#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class OfficeSim
{
  public:
    void start();
    void setFileName(string input);
    void simulate();
    // void stats();
    // DoublyLinkedList<int> *students;
    string fileName;
    GenQueue<int> fileValues;
    GenQueue<Window> windows;
    GenQueue<Student> line;
    int numWindows = 0;
    int numStudents = 0;
    int nextTime = 0;
    bool exitCheck = false;
    bool windowsCheck = false;
    int emptyWindows = 0;
};
