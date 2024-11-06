#include "avl_tree.hpp"

int main() {
  AVL<AvlNode, int> b{};
  b.insert(10);
  b.insert(20);
  b.insert(30);
  b.insert(40);
  b.insert(50);
  b.insert(25);

  b.print_inorder();
//  std::cout << std::boolalpha;
//  std::cout << "find17 " << b.search(17) << std::endl;
//  std::cout << "find18 " << b.search(18) << std::endl;

  b.delete_(25);
  b.print_inorder();

  getchar();
  return 0;
}