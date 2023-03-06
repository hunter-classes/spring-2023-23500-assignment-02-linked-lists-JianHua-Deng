#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
  /*
  List *l = new List();
  //std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  //std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"b");
  l->insert(0,"c");
  l->insert(0,"d");
  try {
    l->insert(10,"x");
  } catch (std::exception e){
    std::cout << "Insert x didn't work\n";
  }
  //std::cout << l->toString() << "\n";
  l->insert(2,"inserted at 2");
  //std::cout << l->toString() << "\n";
  l->insert(5,"inserted at end");
  std::cout << l->toString() << " " << l->length() << "\n";
  std::cout << "Did it contain b?" << "\n" << l->contains("b") << "\n";
  std::cout << "Did it contain v?" << "\n" << l->contains("v") << "\n";

  l->remove(0);
  std::cout << l->toString() << " " << l->length() << "\n";
  l->remove(2);
  std::cout << l->toString() << " " << l->length() << "\n";
  std::cout << l->remove(10) << "\n";
  std::cout << l->toString() << " " << l->length() << "\n";
  delete l;
  */

  OList *olist = new OList();
  olist->insert("10");
  olist->insert("7");
  olist->insert("7");
  olist->insert("8");
  olist->insert("11");
  std::cout << olist->toString() << " " << olist->length() << "\n";

  return 0;

  
}
