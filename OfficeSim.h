#include "FileNotFoundException.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class OfficeSim
{
  public:
    void start();
    void setFileName(string input);
    // void stats();
    // DoublyLinkedList<int> *students;
    string fileName;
};
