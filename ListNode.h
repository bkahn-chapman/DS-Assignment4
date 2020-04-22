#include <iostream>

using namespace std;

template <class T>
class ListNode
{
  public:
    T data;
    ListNode *next;
    ListNode *prev;

    ListNode(); //default
    ListNode(T); //overload
    ~ListNode(); //destructor
};

template <class T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T dataInput)
{
  data = dataInput;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{
  //delete thingy
}
