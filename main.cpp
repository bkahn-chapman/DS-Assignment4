#include "OfficeSim.h"
#include "GenQueue.h"
int main(int argc, char **argv)
{
  GenQueue<int> test;
  test.insert(10);
  test.remove();
  if(test.isEmpty())
  {
    cout << "yee" << endl;
  }
  else
  {
    cout << "nah" << endl;
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
