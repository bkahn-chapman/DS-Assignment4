#include "OfficeSim.h"
int main(int argc, char **argv)
{
  OfficeSim os;
  string name;
  if(argv[1]!=NULL)
  {
    name = argv[1];
    os.setFileName(name);
    os.start();
  }
  else
  {
    cout << "Please enter a file name." << endl;
    cin >> name;
    os.setFileName(name);
    os.start();
  }
  os.simulate();
  os.outputResults();
  exit(0);
  return 0;
}
