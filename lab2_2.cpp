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

void Insert_After(Node *prev_node, int new_data)
{
  /*1. check if the given prev_node is NULL */
  if (prev_node == NULL)
  {
    cout << "The given previous node cannot be NULL"<< endl;
    return;
  }
  /* 2. allocate new node */
  Node *new_node = new Node;
  /* 3. put in the data */
  new_node->data = new_data;
  /* 4. Make next of new node as next of prev_node */
  new_node->next = prev_node->next;
  /* 5. move the next of prev_node as new_node */
  prev_node->next = new_node;
}

int main()
{

  srand(time(0));

  Node *head = NULL;
  Node *current = NULL;
  Node *end = NULL;

  int product_positive = 1;
  int random_num;
  int quantity = 0;
  while (product_positive < 78)
  {
    random_num = (rand() % 21) - 10;
    if (random_num >= 0)
    {
      product_positive *= random_num;
    }
    Add_Node(head, end, random_num);
    quantity++;
  }

  Print_List(head);

  // find max element
  current = head;
  int max_element = 0;
  while (current != NULL)
  {
    
    if (current->data > max_element)
    {
      max_element = current->data;
    }
    current = current->next;
  }

  cout << "max_element = " << max_element << endl;



  current = head;

  // calculate quantity odd el
  int quantity_odd = 0;
  while(current != NULL){
    if (current->data % 2 != 0){
      quantity_odd++;
    }
    current = current->next;
  }

  cout << quantity_odd << endl;

  Node *prev_node = head;
  int i = 0;
  while (i < quantity_odd)
  {
    if(i == 0){
      while (prev_node->data % 2 == 0)
        prev_node = prev_node->next;
      Insert_After(prev_node, max_element);
    }else{
      prev_node = prev_node->next;

      while (prev_node->data % 2 == 0)
        prev_node = prev_node->next;
      Insert_After(prev_node, max_element);
    }
    i++;
  }
    


    Print_List(head);

    system("pause");
    return 0;
}