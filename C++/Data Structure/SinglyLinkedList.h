// Copyright(C) Utkarsh Nagdev;
// Header file for an implementation of singly linked list in C++;
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
class List {
 protected:
  struct Node {
    int info;
    struct Node* next;
  };
  typedef Node* NODEPTR;
  NODEPTR head;
  inline int emptyList() const;
 public:
  List();
  ~List();
  int insertAfter(int,int);
  int push(int insertValue);
  int pop();
  void del(int delVal);
  inline void print() const;
};
#endif
