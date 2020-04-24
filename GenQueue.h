#include <iostream>
using namespace std;

template <class T>
class GenQueue
{
  public:
    GenQueue(); //default constructor
    // GenQueue(int maxSize); //overloaded constructor
    ~GenQueue(); //destructor

    //core functions
    T insert(T data); //enqueue
    T remove(); //dequeue

    //aux functions
    // T peek();
    // bool isFull();
    bool isEmpty();
    // int getSize();

    //vars
    int front; //aka head
    int rear; //aka tail
    int mSize;
    int numElements;

    DoublyLinkedList<T> *myList; //array
};

template <class T>
GenQueue<T>::GenQueue() //default constructor
{
  myList = new DoublyLinkedList<T>;
  mSize = 10;
  front = 0;
  rear = -1;
  numElements = 0;
}

/*
template <class T>
GenQueue<T>::GenQueue(int maxSize) //overloaded constructor
{
  myQueue = new char [maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}
*/

template <class T>
GenQueue<T>::~GenQueue()
{
  cout << "The list has been deleted." << endl;
  delete myList;
}

template <class T>
void GenQueue<T>::insert(T data)
{
  //add error checking
  myList[++rear] = d;
  ++numElements;
}

template <class T>
T GenQueue<T>::remove()
{
  //add error checking
  char c = '\0'; //null character
  c = myList[front];
  ++front;
  --numElements;
  return c;
}

/*
template <class T>
T GenQueue<T>::peek()
{
  return myQueue[front];
}
*/

/*
template <class T>
bool GenQueue<T>::isFull()
{
  return (numElements == mSize);
}
*/

template <class T>
bool GenQueue<T>::isEmpty()
{
  return (numElements == 0);
}

/*
template <class T>
int GenQueue<T>::getSize()
{
  return numElements;
}
*/
