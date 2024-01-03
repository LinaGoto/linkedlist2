#ifndef STUDENT_H
#define STUDENT_H

class Student {
 private:
  int id;
  float gpa;
  char name[50];
  
 public:
  int getid();
  float getgpa();
  char *getname();
  
  void setValue(int id, float gpa, char *name);
};
#endif
