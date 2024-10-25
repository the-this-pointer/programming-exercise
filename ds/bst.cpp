#include <iostream>
#include "bst.hpp"

int main() {
  BST<Node, int> b{};
  b.insert(10);
  b.insert(2);
  b.insert(5);
  b.insert(4);
  b.insert(15);
  b.insert(17);

  b.print_inorder();
  std::cout << std::boolalpha;
  std::cout << "find17 " << b.search(17) << std::endl;
  std::cout << "find18 " << b.search(18) << std::endl;

  b.delete_(10);
  b.delete_(2);
  b.print_inorder();

  getchar();
  return 0;
}