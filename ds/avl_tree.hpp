#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include <utility>
#include "bst.hpp"

template <typename T>
class AvlNode {
public:
  explicit AvlNode(T&& val):
      value(std::forward<T>(val)), height(1),
      left(nullptr), right(nullptr)
  {}

  ~AvlNode() {
    delete left;
    delete right;
  }

  T value;
  AvlNode<T>* left;
  AvlNode<T>* right;
  int height;
};

template <
    template <typename> class N,
    typename V
>
class AVL: protected BST<N, V> {
public:
  using value_type [[maybe_unused]] = V;
  using node_type = N<V>;

  AVL(): BST<N, V>()
  {}

  virtual ~AVL() = default;

  template<typename U>
  void insert(U&& value)
  {
    this->root = avl_insert(this->root, std::forward<U>(value));
//    this->root->height = std::max(height(this->root->left), height(this->root->right)) + 1;
  }

  template<typename U>
  [[maybe_unused]]
  bool search(U&& value)
  {
    return bst_search(this->root, std::forward<U>(value));
  }

  template<typename U>
  [[maybe_unused]]
  void delete_(U&& value)
  {
    this->root = avl_delete(this->root, std::forward<U>(value));
  }

  void print_inorder() {
    BST<N,V>::print_inorder();
    std::cout << std::endl;
  }

  void print_preorder() {
    this->print_preorder(this->root);
    std::cout << std::endl;
  }

private:
  int height(node_type* node)
  {
    if (!node) return 0;
    return node->height;
  }

  int balance(node_type* node)
  {
    if (!node) return 0;
    return height(node->left) - height(node->right);
  }

  template <typename U>
  node_type* performBalance(node_type* node, U&& value)
  {
    int b = balance(node);

    // Left Left Case
    if (b > 1 && value < node->left->value)
      return rotateRight(node);

    // Right Right Case
    if (b < -1 && value > node->right->value)
      return rotateLeft(node);

    // Left Right Case
    if (b > 1 && value > node->left->value) {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }

    // Right Left Case
    if (b < -1 && value < node->right->value) {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  node_type* rotateRight(node_type* nodeY)
  {
    node_type* nodeX = nodeY->left;
    node_type* T2 = nodeX->right;

    nodeY->left = T2;
    nodeX->right = nodeY;

    nodeY->height = std::max(height(nodeY->left), height(nodeY->right)) + 1;
    nodeX->height = std::max(height(nodeX->left), height(nodeX->right)) + 1;

    return nodeX;
  }

  node_type* rotateLeft(node_type* nodeX)
  {
    node_type* nodeY = nodeX->right;
    node_type* T2 = nodeY->left;

    nodeX->right = T2;
    nodeY->left = nodeX;

    nodeY->height = std::max(height(nodeY->left), height(nodeY->right)) + 1;
    nodeX->height = std::max(height(nodeX->left), height(nodeX->right)) + 1;

    return nodeY;
  }

  template<typename U>
  node_type* avl_insert(node_type* node, U&& value)
  {
    if (node == nullptr)
      return new node_type(std::forward<U>(value));

    if (value < node->value)
      node->left = avl_insert(node->left, std::forward<U>(value));
    else if (value > node->value)
      node->right = avl_insert(node->right, std::forward<U>(value));
    else
      return node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    return performBalance(node, std::forward<U>(value));
  }

  template<typename U>
  node_type* avl_delete(node_type* node, U&& value) {
    if (!node)
      return nullptr;

    if (value < node->value)
      node->left = avl_delete(node->left, std::forward<U>(value));
    else if (value > node->value)
      node->right = avl_delete(node->right, std::forward<U>(value));
    else
    {
      // if the node is a leaf we simply delete it.
      if (!node->left && !node->right)
      {
        this->detachNode(node);
        delete node;
        return nullptr;
      }
      else if (!node->left) {
        node_type* tmp = node->right;
        this->detachNode(node);
        delete node;
        node = tmp;
      }
      else if (!node->right) {
        node_type* tmp = node->left;
        this->detachNode(node);
        delete node;
        node = tmp;
      }
      else {
        // find the inorder successor (smallest in the right subtree)
        node_type *min = this->successor(node->right);
        node->value = std::forward<U>(min->value);
        node->right = avl_delete(node->right, min->value);
      }
    }

    node->height = 1 + std::max(height(node->left), height(node->right));
    return performBalance(node, std::forward<U>(value));
  }

  void print_preorder(node_type* node) {
    if (node != nullptr) {
      std::cout << "[" << node->value << " " << node->height << "]";
      print_preorder(node->left);
      print_preorder(node->right);
    }
  }
};

#endif //AVL_TREE_HPP
