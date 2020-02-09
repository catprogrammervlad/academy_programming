///
// Calculate the sum of list elements, which values belong to the interval[3, 6]
///

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

int main()
{

  srand(time(0));

  Node *head = NULL;
  Node *current = NULL;
  Node *end = NULL;

  int quantity = 0;
  do
  {
    quantity++;
    current = new Node;
    current->next = NULL;
    current->data = rand() % 10; // write data
    if (head == NULL)
    {
      head = current;
      end = current;
    }
    else
    {
      end->next = current;
      end = current;
    }
  } while (current->data != 9);

  current = head;

  if (quantity % 2 != 0)
  {
    cout << "The quantity is odd" << endl;
    return 0;
  }
 

  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl
       << endl;
  current = head;

  int index_middle = quantity / 2 ;
  cout << "test-1" << endl;
  int i = 0;
  int buffer_1;
  int buffer_2;
  cout << "test-2" << endl;
  while(true){
    cout << "test-3" << endl;
    // find second element
    for (int j = 0; j < index_middle + i; j++)
    {
      current = current->next; // find
    }

    cout << "test-4" << endl;
    buffer_2 = current->data; // assign
    cout << "test-5" << endl;
    current = head; // back
    cout << "test-6" << endl;

    // find first element
    for (int j = 0; j < i; j++)
    {
      cout << "test-7" << endl;
      current = current->next; // find
    }

    buffer_1 = current->data;
    current->data = buffer_2; // assign
    cout << "test-8" << endl;
    current = head; // back

    cout << "test-9" << endl;
    cout << "index_middle = " << index_middle << endl;
    // find second element
    for (int j = 0; j < index_middle + i; j++)
    {
      cout << "test-10" << endl;
      current = current->next; // find
    }

    current->data = buffer_1;
    cout << "test-11" << endl;

    current = head; // back
    if (i+1>=index_middle){
      cout << "test-12" << endl;
      break;
    }
      i++;
  }

  current = head;
  cout << "output" << endl;
  //output
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }

  system("pause");
  return 0;
}