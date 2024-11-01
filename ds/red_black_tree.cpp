#include "red_black_tree.hpp"

int main() {
  RB<RBNode, int> b{};
  b.insert(10);
  b.insert(20);
  b.insert(30);
  b.insert(40);
  b.insert(50);
  b.insert(25);
  b.print_inorder();

  b.delete_(30);
  b.print_inorder();

  getchar();
  return 0;
}