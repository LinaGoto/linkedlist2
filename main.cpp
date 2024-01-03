#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
Lina Goto
12/4/23
Linked list
 */

void add(Student *newstudent);
void print(Node* next);

static Node *head = NULL;

//add number in node
void add(Student *newstudent){
  Node *current = head;
  Node *newnode;
  //very first node; add new node and set value
  if (current == NULL) {
    head = new Node(newstudent);
  } else {//find node which next is NULL - set new node by pointer and set value
    while (current -> getNext() != NULL){
      current = current -> getNext();
    }
    newnode = new Node(newstudent);
    current -> getNext() -> setNext(newnode);
  }
}

//del number in node
void del(Student *newstudent){
  Node *current = head;
  Node *newnode;
  //very first node; del new node and set value
  if (current == NULL) {
    head = new Node(newstudent);
  } else {//find node which next is NULL - set new node by pointer and set value
    while (current -> getNext() != NULL){
      current = current -> getNext();
    }
    newnode = new Node(newstudent);
    current -> getNext() -> setNext(newnode);
  }
}

//printing the node
void print (Node *next) {
  //if the node is very first print list:
  if (next == head){
    cout << "list: ";
  }
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    cout << next -> getStudent() -> getValue() << " ";
    //recursive call
    print (next -> getNext());
    if (next -> getNext() == NULL) {
      cout << endl;
    }
  }
}

int main() {
  Student student1;
  Student student2;
  Student student3;
  Student student4;

  student1.setValue(3);
  student2.setValue(5);
  student3.setValue(1);
  student4.setValue(2);

  add(&student1);
  print(head);
  add(&student2);
  print(head);
  add(&student3);
  print(head);
  add(&student4);
  print(head);

  return 0;
}

