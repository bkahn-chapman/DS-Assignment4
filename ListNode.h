#include <iostream>
using namespace std;

///header (.h) file for my doubly linked list
class ListNode
{
  public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(); // default constructor
    ListNode(int d); //overloaded constructor
    ~ListNode(); //destructor
};

///ListNode implementation file (.cpp)
ListNode::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

ListNode::ListNode(int d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode()
{
  //I'll let you do some research
  //AKA build some character
}
