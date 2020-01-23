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
    current->data = rand() % 10 + 1;
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

  //output and write to array
  int arr_swap[10];
  int j = 0;
  while (current != NULL)
  {
    cout << current->data << " ";
    arr_swap[j] = current->data;
    j++;
    current = current->next;
  }
  cout << endl;

  //rewrite
  int arr_swap_1[10] = {1, 4, 2, 5, 4, 3, 2, 5, 4, 10};
  j = 0;
  while (current != NULL)
  {

    current->data = arr_swap_1[j];
    j++;
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;

  cout << "Show array:" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << arr_swap[i] << " ";
  }
  cout << endl;

  // double x = head->data;
  // head->data = end->data;
  // end->data = x;
  cout << "Show array2:" << endl;
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;

  system("pause");
  return 0;
}