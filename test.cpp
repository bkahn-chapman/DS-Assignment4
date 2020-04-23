#include "GenQueue.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  GenQueue<char> q;

  q.insert('r');
  q.insert('e');
  q.insert('p');

  cout << "peek: " << q.peek() << endl;
  cout << "remove: " << q.remove() << endl;
  cout << "inserting b, d, p into the queue" << endl;

  q.insert('b');
  q.insert('d');
  q.insert('p');

  cout << "purging the queue" << endl;
  while(!q.isEmpty())
  {
    cout << "remove: " << q.remove() << endl;
  }
  q.~GenQueue();
  exit(0);
}
