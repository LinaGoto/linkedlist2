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
    current -> setNext(newnode);
  }
}

//delete number in node
void del(int id){
  Node *current = head;

  while ((current != NULL) && (current -> getStudent() -> getid() != id)) current = current -> getNext();

  if (current == NULL) return;

  if (current == head) {
    /* if data is at head */
    head = current -> getNext();
    delete current;
  } else if (current -> getNext() == NULL) {
    /* if data is at tail */
    Node *prev = head;
    while (prev -> getNext() != current) prev = prev -> getNext();
    prev -> setNext(NULL);
    delete current;
  } else {
    /* otherwise */
    Node *prev = head;
    while (prev -> getNext() != current) prev = prev -> getNext();
    prev -> setNext(current -> getNext());
    delete current;
  }
}

//printing the node
void print (Node *next) {
  //if the node is very first print list:
  if (next == head){
    cout << "ID  GPA  NAME " << endl;
  }
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    Student *student = next -> getStudent();
    
    cout << student -> getid() << "  " << student -> getgpa() <<  " "  << student -> getname() << endl;

    //recursive call
    print (next -> getNext());
    if (next -> getNext() == NULL) {
      cout << endl;
    }
  }
}

int main() {
  Student *student;
  char input[10];
  
  do {
    cout << "ADD/PRINT/DELETE/QUIT: " << endl;
    cin.get(input,10);
    cin.get();
    
    //if add
    if ((input[0] == 'A') || (input[0] == 'a')){
      int id;
      float gpa;
      char name[20];
      
      cout << "Name:" << endl;
      cin.get(name, 10);
      cin.get();
      
      cout << "ID:" << endl;
      cin >> id;
      cin.get();
      
      cout << "GPA:" << endl;
      cin >> gpa;
      cin.get();
      student = new Student();
      
      student -> setValue(id, gpa, name);
      add(student);
    }
    
    //if print
    if ((input[0] == 'P') || (input[0] == 'p')){
      print (head);
    }
    
    //if delete
    if((input[0] == 'D') || (input[0] == 'd')){
      int id;
      cout << "Enter student id: " << endl;
      cin >> id;
      cin.get();
      del(id);
    }
    
  } while ((input[0] != 'Q') && (input[0] != 'q'));
  //end with quit
  
  return 0;
}

