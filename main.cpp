#include "OfficeSim.h"
#include "GenQueue.h"
int main(int argc, char **argv)
{

  GenQueue<int> test;
  if(test.isEmpty())
  {
    cout << "yee" << endl;
  }

  OfficeSim os;
  string name;
  if(argv[1]!=NULL)
  {
    name = argv[1];
    os.setFileName(name);
    os.start();
  }
  exit(0);
  return 0;
}
