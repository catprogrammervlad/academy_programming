///
// Swap the first half of the list with the second half
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
  int j = 0;
  int swap_array[10]; // array to swap
  int a;
  do
  {

    i++;
    current = new Node;
    current->next = NULL;
    current->data = rand() % 10 + 1; // write data
    swap_array[i - 1] = current->data;

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
  } while (i < 10);

  current = head;

  //write to array to swap
  while (current != NULL)
  {

    cout << current->data << " ";
    current = current->next; // next
  }
  cout << endl;
  cout << endl;
  // manipulation of array to swap element
  int swap_array_2[10];
  for (int i = 0; i < 10; i++)
  {
    if (i < 5)
    {
      swap_array_2[i] = swap_array[i + 5];
    }
    else
    {
      swap_array_2[i] = swap_array[i - 5];
    }
  }
  // for (int i = 0; i < 10; i++)
  // {
  //   cout << ' ' << swap_array_2[i];
  // }

  i = 0;
  do
  {

    current = new Node;
    current->next = NULL;
    current->data = swap_array_2[i]; // write data
    i++;
    if (i - 1 == 0)
    {
      head = current;
      end = current;
    }
    else
    {
      end->next = current;
      end = current;
    }
  } while (i < 10);

  current = head;
  // output
  while (current != NULL)
  {

    cout << current->data << " ";
    current = current->next; // next
  }
  cout << endl;
  cout << endl;

  current = head;

  system("pause");
  return 0;
}