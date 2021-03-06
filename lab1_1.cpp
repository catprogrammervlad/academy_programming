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

  int i = 0;
  do
  {

    i++;
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

  double sum = 0;

  


  //output
  while (current != NULL)
  {
    if (current->data >= 3 && current->data <= 6)
    {
      sum += current->data;
    }
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
  cout << "Sum \t" << sum << endl;
  system("pause");
  return 0;
}