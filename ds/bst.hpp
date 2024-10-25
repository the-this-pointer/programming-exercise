#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <utility>

template <typename T>
class Node {
public:
  explicit Node(T&& val):
      value(std::forward<T>(val)), left(nullptr), right(nullptr)
  {}

  ~Node() {
    delete left;
    delete right;
  }

  T value;
  Node<T>* left;
  Node<T>* right;
};

template <
    template <typename> class N,
    typename V
>
class BST {
public:
  using value_type = V;
  using node_type = N<V>;

  BST() {
    root = nullptr;
  }

  ~BST() {
    delete root;
  }

  template<typename U>
  void insert(U&& value)
  {
    insert(&root, std::forward<U>(value));
  }

  template<typename U>
  [[maybe_unused]]
  bool search(U&& value)
  {
    return search(root, std::forward<U>(value));
  }

  template<typename U>
  [[maybe_unused]]
  void delete_(U&& value)
  {
    root = delete_(root, std::forward<U>(value));
  }

  void print_inorder() {
    print_inorder(root);
    std::cout << std::endl;
  }

private:
  template<typename U>
  void insert(node_type** node, U&& value)
  {
    if (*node == nullptr)
    {
      *node = new Node<value_type>(std::forward<U>(value));
      return;
    }

    if (value < (*node)->value)
    {
      if (!(*node)->left)
        (*node)->left = new Node<value_type>(std::forward<U>(value));
      else
        insert(&((*node)->left), std::forward<U>(value));
    }

    if (value > (*node)->value)
    {
      if (!(*node)->right)
        (*node)->right = new Node<value_type>(std::forward<U>(value));
      else
        insert(&((*node)->right), std::forward<U>(value));
    }
  }

  template<typename U>
  bool search(node_type* node, U&& value)
  {
    if (!node)
      return false;

    if (value == node->value)
      return true;

    if (value < node->value)
      return search(node->left, std::forward<U>(value));
    else if (value > node->value)
      return search(node->right, std::forward<U>(value));

    return false;
  }

  template<typename U>
  node_type* delete_(node_type* node, U&& value) {
    if (!node)
      return nullptr;

    if (value < node->value)
      node->left = delete_(node->left, std::forward<U>(value));
    else if (value > node->value)
      node->right = delete_(node->right, std::forward<U>(value));
    else
    {
      // if the node is a leaf we simply delete it.
      if (!node->left && !node->right)
      {
        detachNode(node);
        delete node;
        return nullptr;
      }

      if (!node->left) {
        node_type* res = node->right;
        detachNode(node);
        delete node;
        return res;
      }
      else if (!node->right) {
        node_type* res = node->left;
        detachNode(node);
        delete node;
        return res;
      }

      // find the inorder successor (smallest in the right subtree)
      node_type* min = minimum(node->right);
      node->value = std::forward<U>(min->value);
      node->right = delete_(node->right, min->value);
    }
    return node;
  }

  node_type* minimum(node_type* node)
  {
    while(node->left)
      node = node->left;
    return node;
  }

  void detachNode(node_type* node)
  {
    node->left = nullptr;
    node->right = nullptr;
  }

  void print_inorder(node_type* node) {
    if (node != nullptr) {
      print_inorder(node->left);
      std::cout << node->value << " ";
      print_inorder(node->right);
    }
  }

  node_type* root;
};

#endif // BST_HPP