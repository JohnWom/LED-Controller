#ifndef LINKED_LIST
#define LINKED_LIST
// DOUBLY LINKED LIST 

// Struct that is Linked Lists Nodes
struct List_Node {
  int self;
  int last;
  int next;
  void function;
  char display_text[10];
}

// Class for Linked List
class Linked_List
{
private:
  List_Node current_node;
public:
  void go_to_next();          // Goes to next node
  void go_to_last();          // Goes to previous node
  void new_node(auto, void);  // Adds a new node and updates ends
  void call_f();              // Calls function stored in node

}


#endif