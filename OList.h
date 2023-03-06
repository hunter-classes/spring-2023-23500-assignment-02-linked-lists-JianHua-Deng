#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
  Node *head;
 public:
  OList();
  ~OList();
  void insert(std::string data);
  void insert(int loc, std::string data); //0 indexed
  bool contains(std::string value);
  bool remove(int loc);
  int length();
  std::string get(int loc);
  void reverse();

  std::string toString(); // for testing purposes

  
  

};
