#include "OfficeSim.h"
#include "GenQueue.h"
int main(int argc, char **argv)
{

  GenQueue *test = new GenQueue;
  GenQueue<int> test;
  if(test.isEmpty())
  {
    cout << "yee" << endl;
  }
>>>>>>> 2481561d05d270072bf6332c54db8c2b2c5154e5
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
