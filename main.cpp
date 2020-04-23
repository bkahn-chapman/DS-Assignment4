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
  exit(0);
  return 0;
}
