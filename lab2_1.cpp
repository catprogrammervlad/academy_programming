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

void Add_Node(Node *&head, Node *&end, int x)
{
  Node *current = new Node;
  current->next = NULL;
  current->data = x;
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
}

void Print_List(Node *head)
{
  cout << "The list:" << endl;
  Node *current = head;
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
  
}

void deleteNode(Node *&head, Node *&end, int x)
{
  // Store head node
  Node *temp = head, *prev = NULL;

  // If head node itself holds x (the key to be deleted)
  if (temp != NULL && temp->data == x)
  {
    head = temp->next; // Changed head
    delete temp;       // free old head
    return;
  }

  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (temp != NULL && temp->data != x)
  {
    prev = temp;
    temp = temp->next;
  }

  // If key x was not present in linked list
  if (temp == NULL)
    return;

  // Unlink the node from linked list
  prev->next = temp->next;
  // If key x is the last
  if (temp == end)
    end = prev;

  delete temp; // Free memory
}







int main()
{

  srand(time(0));

  Node *head = NULL;
  Node *current = NULL;
  Node *end = NULL;

  int random_num = 0;
  int quantity_positive = 0;
  int quantity_negative = 0;

  do
  {
    random_num = (rand() % 21) - 10;
    if (random_num>=0)
    {
      ++quantity_positive;
    }else{
      ++quantity_negative;
    }
    Add_Node(head, end, random_num);
  } while (quantity_positive != quantity_negative);



  Print_List(head);
  
  int delete_num;


  current = head;
  while (current != NULL)
  {
    cout << "Hello and also test" << endl;
    if(abs(current->data) < 5){
      delete_num = current->data;
      break;
    } 
    current = current->next;
  }
  

  // head = current;
  deleteNode(head, end, delete_num);
  
  Print_List(head);
  // while (current != NULL)
  // {
  //   cout << current->data << " ";
  //   current = current->next;
  // }

  system("pause");
  return 0;
}