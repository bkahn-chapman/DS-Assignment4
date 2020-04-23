#include <iostream>
#include "ListNode.h"

using namespace std;


class DoublyLinkedList

{
  private:
    ListNode *front;
    unsigned int size;
    ListNode *back;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(int data); //adds data to front of list, dont need for this assignment, can remove
    void insertBack(int data);
    int removeFront(); //removes front value
    int removeBack(); //dont need for this assignment, can remove
    int search(int val); //can return value or position of node depending on implementation
    // T removeAtPos(int pos); //removes value at given position, not necessary for assignment
    //could implement an insert at position, similar to removeAtPos, also not necessary

    unsigned int getSize();
    int getFront();
    bool isEmpty();
    void printList();
};

DoublyLinkedList::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
  if(!isEmpty())
  {
    ListNode *curr = front;
    ListNode *temp;
  }
  while(curr != 0) //deletes all nodes remaining in the list before deletion
  {
    temp = curr;
    curr = curr->next;
    delete temp;
  }
}

unsigned int DoublyLinkedList::getSize()
{
  return size;
}

bool DoublyLinkedList::isEmpty()
{
  return (size == 0);
}

void DoublyLinkedList::printList()
{
  ListNode *curr = front;
  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void DoublyLinkedList::insertFront(int data)
{
  ListNode *node = new ListNode(data);
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

void DoublyLinkedList::insertBack(int data)
{
  ListNode *node = new ListNode(data);
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

int DoublyLinkedList::removeFront()
{
  ListNode *tempPointer = front;
  //not sure if we need this cuz i cant really figure out what it does
  if(front->next == NULL)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
  tempPointer->next = NULL;
  int tempData = tempPointer->data;
  delete tempPointer;
  size--;
  return tempData;
}

int DoublyLinkedList::search(int val)
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
  return position;
}

int DoublyLinkedList::getFront()
{
  return front->data;
}

int DoublyLinkedList::removeBack()
{
  int tempData = back->data;
  ListNode *backTemp = back;
  back = back->prev;
  backTemp->prev = NULL;
  delete backTemp;
  size--;
  return tempData;
}
