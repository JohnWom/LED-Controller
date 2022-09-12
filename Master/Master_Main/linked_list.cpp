#include "linked_list.h"

struct List_Node {
  int prev;
  int next;
  void function;
  char display_text[10];
}


class Linked_List
{
private:
  List_Node current_node;
public:

  Linked_List(void f, char d[10]) {
    List_Node Head = { None, None, f}, d;
  }

  void go_to_next() {
    current_node = current_node.next;
  }

  void go_to_prev() {
    current_node = current_node.prev;
  }

  void new_node(auto name, void f) {
    List_Node name = {head.prev, head.self,f};
    head.prev.next = name;
    head.prev = name;
  }

  void call_f() {
    current_node.f;
  }


}
