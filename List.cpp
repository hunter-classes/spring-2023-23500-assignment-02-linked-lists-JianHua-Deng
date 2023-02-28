#include <iostream>
#include "Node.h"
#include "List.h"

List::List(){
  head = nullptr;
}

List::~List(){
  while(head->getNext() != nullptr){
    //since walker is always one being head
    Node *walker = head
    head = head->getNext();
    delete walker;
  }
  delete head;


}

// insert at the "front" (head)
void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 

  Piggybacking 
 */
void List::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

bool List::contains(std::string item){
  Node *walker = head;

  while(walker != nullptr){
    if(walker->getData() == item){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}//end contains function


bool List::remove(int loc){
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
int List::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}



std::string List::toString(){
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
