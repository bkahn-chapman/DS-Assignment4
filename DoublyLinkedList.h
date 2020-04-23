#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList

{
  private:
    ListNode *front;
    unsigned int size;
    ListNode *back;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T data); //adds data to front of list, dont need for this assignment, can remove
    void insertBack(T data);
    T removeFront(); //removes front value
    T removeBack(); //dont need for this assignment, can remove
    T search(T val); //can return value or position of node depending on implementation
    // T removeAtPos(int pos); //removes value at given position, not necessary for assignment
    //could implement an insert at position, similar to removeAtPos, also not necessary

    unsigned int getSize();
    T getFront();
    bool isEmpty();
    void printList();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  if(!isEmpty())
  {
    ListNode<T> *curr = front;
    ListNode<T> *temp;
  }
  while(curr != 0) //deletes all nodes remaining in the list before deletion
  {
    temp = curr;
    curr = curr->next;
    delete temp;
  }
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode *curr = front;
  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T dataInput)
{
  ListNode *node = new ListNode(dataInput);
  //Check if empty
  if(isEmpty())
  {
    back = node;
  }
  else
  {
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <class T>
void DoublyLinkedList::insertBack(T dataInput)
{
  ListNode *node = new ListNode(dataInput);
  //Check if empty
  if(isEmpty())
  {
    front = node;
  }
  else
  {
    //not empty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront()
{
  ListNode<T> *tempPointer = front;
  // if(front->next == NULL)     not sure if we need this cuz i cant really figure out what it does
  // {
  //   back = NULL;
  // }
  // else
  // {
  //   front->next->prev = NULL;
  // }
  front = front->next;
  tempPointer->next = NULL;
  T tempData = tempPointer->data;
  delete tempPointer;
  size--;
  return tempData;
}

template <class T>
int DoublyLinkedList<T>::search(T val)
{
  int position = -1; //negative positions will output a ValueNotFound
  ListNode *curr = front;
  while(curr != NULL)
  {
    //iterate and attempt to find value
    position++;
    if(curr->data == val)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }
  if(curr == NULL)
    position = -1; //we did not find the value
  return position
}

template <class T>
T DoublyLinkedList<T>::getFront()
{
  return front->data;
}

template <class T>
T DoublyLinkedList<T>::removeBack()
{
  T tempData = back->data;
  ListNode<T> *backTemp = back;
  back = back->prev;
  backTemp->prev = NULL;
  delete backTemp;
  size--;
  return tempData;
}
