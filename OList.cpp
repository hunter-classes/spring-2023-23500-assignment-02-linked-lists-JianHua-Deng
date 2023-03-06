#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
  std::cerr << "Calling the destructor\n";
  Node *walker = head;
  Node *trailer = nullptr;
  while (walker != nullptr){
    trailer=  walker;
    walker = walker->getNext();
    std::cerr << "Deleting " << trailer->getData() << ", ";
    delete trailer;
  }
  std::cerr << "\n";
  
  
}

// insert at the "front" (head)
void OList::insert(std::string data){
  Node *newNode = new Node(data);
  //std::cout << "It ran me " << newNode->getData() << "\n";
  if(head == nullptr){
    head = newNode;
  }else{

    Node *trailer, *walker;
    walker = head;
    trailer = nullptr;
    
    while(walker != nullptr && std::stoi(walker->getData()) < std::stoi(newNode->getData())){
      trailer = walker;
      walker = walker->getNext();
    }
    //if none of them are smaller the new insert data, then insert at end
    if(trailer == nullptr){
      newNode->setNext(head);
      head = newNode;
    }else{
      trailer->setNext(newNode);
      newNode->setNext(walker);
    }

  }




}//end of insert









/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 

  Piggybacking 
 */


bool OList::contains(std::string value){
  Node *walker = head;

  while(walker != nullptr){
    if(walker->getData() == value){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}//end contains function


bool OList::remove(int loc){
  Node *walker = head;
  Node *trailer = nullptr;

  
  while(loc > 0 && walker != nullptr){
    loc =- 1;
    trailer = walker;
    walker = walker->getNext();
  }

  if(loc > 0){
    throw std::out_of_range("Our insert is out of range");
  }

  //Node *newnode = new Node();
  //check if trailer is nullptr, if yes, then this mean it is asking to remove element at the index of 0
  if(trailer == nullptr){
    trailer = head;// make the trailer to be the 1st element 
    head = walker->getNext();// make head equals to the second element
    delete trailer; //delete the trailer node as it has now became the first element, delete it to free up memory
    return true;
  }else{
    trailer->setNext(walker->getNext());// since the trailer node is a element behind the walker node, we set trailer's next = to walker's next, then remove it
    delete walker;
    return true;
  }
  return false;
}

/*
  Alternate solution:
    make a private variable to store the length
    and just return it here.

    Change all the insert/delete/remove type
    routines to upate that variable 
 */
int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}



std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}
