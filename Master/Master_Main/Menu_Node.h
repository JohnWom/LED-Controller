#ifndef MENU_NODE
#define MENU_NODE
#include <ArduinoSTL.h>

using namespace std;
/*
Tree ADT

Takes in Nodes
Allows for:
   Moving up and down the tree
   Calling functions on nodes

*/
struct Tree_Node{
  char[7] Name;
  auto function;
}

#endif