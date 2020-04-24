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
    void outputResults();
    // void stats();
    // DoublyLinkedList<int> *students;
    string fileName;
    GenQueue<int> fileValues;
    GenQueue<Window> windows;
    GenQueue<Student> line;
    GenQueue<int> waitTimes;
    int mTime = 0;
    int numWindows = 0;
    int numStudents = 0;
    int totalStudents = 0;
    int nextTime = 0;
    bool exitCheck = false;
    bool windowsCheck = false;
    int emptyWindows = 0;
    float studentMean = 0;
    float studentMedian = 0;
    int studentLong = 0;
    int studentTen = 0;
    float windowMean = 0;
    int windowLong = 0;
    int windowFive = 0;
    int studentTemp = 0;
    int windowTemp = 0;
};
