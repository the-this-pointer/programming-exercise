#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <iostream>
#include <utility>
#include "bst.hpp"

template <typename T>
class RBNode {
public:
  enum NodeColor {
    Red,
    Black,
    BlackBlck,
    RedBlack
  };

  explicit RBNode(T&& val):
      value(std::forward<T>(val)), isRed(false),
      left(nullptr), right(nullptr), parent(nullptr)
  {}

  ~RBNode() {
    delete left;
    delete right;
  }

  T value;
  RBNode<T>* left;
  RBNode<T>* right;
  RBNode<T>* parent;
  bool isRed;
};

template <
    template <typename> class N,
    typename V
>
class RB: protected BST<N, V> {
public:
  using value_type [[maybe_unused]] = V;
  using node_type = N<V>;

  RB(): BST<N, V>()
  {}

  virtual ~RB() = default;

  template<typename U>
  void insert(U&& value)
  {
    rb_insert(std::forward<U>(value));
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
    rb_delete(std::forward<U>(value));
  }

  void print_inorder() {
    print_inorder(this->root);
    std::cout << std::endl;
  }

private:
  bool isNodeRed(node_type* node)
  {
    if (!node)
      return false;
    return node->isRed;
  }

  void setNodeColor(node_type* node, bool isRed)
  {
    if (!node)
      return;
    node->isRed = isRed;
  }

  node_type* rotateRight(node_type* nodeX)
  {
    node_type* nodeY = nodeX->left;
    node_type* T2 = nodeY->right;

    nodeX->left = T2;
    if (T2)
      T2->parent = nodeX;

    nodeY->parent = nodeX->parent;
    if (!nodeX->parent)
      this->root = nodeY;
    else if (nodeX == nodeX->parent->left)
      nodeX->parent->left = nodeY;
    else
      nodeX->parent->right = nodeY;

    nodeY->right = nodeX;
    nodeX->parent = nodeY;

    return nodeY;
  }

  node_type* rotateLeft(node_type* nodeX)
  {
    node_type* nodeY = nodeX->right;
    node_type* T2 = nodeY->left;

    nodeX->right = T2;
    if (T2)
      T2->parent = nodeX;

    nodeY->parent = nodeX->parent;
    if (!nodeX->parent)
      this->root = nodeY;
    else if (nodeX == nodeX->parent->left)
      nodeX->parent->left = nodeY;
    else
      nodeX->parent->right = nodeY;

    nodeY->left = nodeX;
    nodeX->parent = nodeY;

    return nodeY;
  }

  bool isLeftChild(node_type* node) {
    return (node == node->parent->left);
  }

  bool hasRedChild(node_type* node) {
    return (node->left && isNodeRed(node->left)) || (node->right && isNodeRed(node->right));
  }

  node_type* getSibling(node_type* node) {
    if (!node->parent)
      return nullptr;
    if (isLeftChild(node))
      return node->parent->right;
    return node->parent->left;
  }

  node_type* getUncle(node_type* node) {
    if (!node->parent || !(node->parent->parent))
      return nullptr;

    if (isLeftChild(node->parent))
      return node->parent->parent->right;
    else
      return node->parent->parent->left;
  }

  void fixInsert(node_type* node)
  {
    while (node != this->root && isNodeRed(node->parent))
    {
      if (isLeftChild(node->parent))
      {
        node_type* uncle = getUncle(node);
        if (isNodeRed(uncle))
        {
          setNodeColor(node->parent, false);
          setNodeColor(uncle, false);
          setNodeColor(node->parent->parent, true);
          node = node->parent->parent;
        }
        else
        {
          if (!isLeftChild(node)) {
            node = node->parent;
            rotateLeft(node);
          }
          setNodeColor(node->parent, false);
          setNodeColor(node->parent->parent, true);
          rotateRight(node->parent->parent);
        }
      }
      else
      {
        node_type* uncle = getUncle(node);
        if (isNodeRed(uncle))
        {
          setNodeColor(node->parent, false);
          setNodeColor(uncle, false);
          setNodeColor(node->parent->parent, true);
          node = node->parent->parent;
        }
        else
        {
          if (isLeftChild(node)) {
            node = node->parent;
            rotateRight(node);
          }
          setNodeColor(node->parent, false);
          setNodeColor(node->parent->parent, true);
          rotateLeft(node->parent->parent);
        }
      }
    }
    setNodeColor(this->root, false);
  }

  template<typename U>
  void rb_insert(U&& value)
  {
    auto* newNode = new node_type(std::forward<U>(value));
    setNodeColor(newNode, true);

    node_type* parent = nullptr;
    node_type* current = this->root;
    while(current)
    {
      parent = current;
      if (newNode->value < current->value)
        current = current->left;
      else if (newNode->value > current->value)
        current = current->right;
    }
    newNode->parent = parent;
    if (!parent) {
      this->root = newNode;
      setNodeColor(newNode, false);
    }
    else if (newNode->value < parent->value)
      parent->left = newNode;
    else if (newNode->value > parent->value)
      parent->right = newNode;

    fixInsert(newNode);
  }

  node_type* replacement(node_type* node) {
    if (!node->left && !node->right)
      return nullptr;

    if (node->left && node->right)
      return this->successor(node->right);

    if (node->left)
      return node->left;
    return node->right;
  }

  template<typename U>
  void rb_delete(U&& value) {
    node_type* current = this->root;
    node_type* v = nullptr;
    while(current)
    {
      if (value < current->value)
        current = current->left;
      else if (value > current->value)
        current = current->right;
      else {
        v = current;
        break;
      }
    }

    if (!v)
      return;

    rb_delete(v);
  }

  void fixDoubleBlack(node_type* node) {
    if (this->root == node)
      return;

    node_type* s = getSibling(node);
    node_type* p = node->parent;

    if (!s) {
      fixDoubleBlack(p);
      return;
    }

    if (isNodeRed(s)) {
      setNodeColor(p, true);
      setNodeColor(s, false);

      if (isLeftChild(s))
        rotateRight(p);
      else
        rotateLeft(p);

      fixDoubleBlack(node);
      return;
    }

    if (hasRedChild(s)) {
      if (s->left && isNodeRed(s->left)) {
        if (isLeftChild(s)) {
          setNodeColor(s->left, s->isRed);
          setNodeColor(s, p->isRed);
          rotateRight(p);
        }
        else {
          setNodeColor(s->left, p->isRed);
          rotateRight(s);
          rotateLeft(p);
        }
      }
      else if (s->right && isNodeRed(s->right)) {
        if (isLeftChild(s)) {
          setNodeColor(s->right, p->isRed);
          rotateLeft(s);
          rotateRight(p);
        }
        else {
          setNodeColor(s->right, s->isRed);
          setNodeColor(s, p->isRed);
          rotateLeft(p);
        }
      }
      setNodeColor(p, false);
      return;
    }

    setNodeColor(s, true);
    if (!isNodeRed(p))
      fixDoubleBlack(p);
    else
      setNodeColor(p, false);
  }

  void rb_delete(node_type* v) {
    node_type* u = replacement(v);
    node_type* p = v->parent;
    bool doubleBlack = !isNodeRed(v) && !isNodeRed(u);

    if (!u) { // v is leaf
      if (v == this->root)
        this->root = nullptr;
      else {
        if (doubleBlack)
          fixDoubleBlack(v);
        else {
          setNodeColor(getSibling(v), true);
        }

        if (isLeftChild(v))
          p->left = nullptr;
        else
          p->right = nullptr;
      }
      delete v;
      return;
    }

    if (v->right || v->left) { // v has one child
      if (v == this->root) {
        v->value = u->value;
        rb_delete(u);
      }
      else {
        if (isLeftChild(v))
          p->left = u;
        else
          p->right = u;
        u->parent = p;

        this->detachNode(v);
        delete v;

        if (doubleBlack)
          fixDoubleBlack(u);
        else
          setNodeColor(u, false);
      }

      return;
    }

    swapValues(v, u);
    rb_delete(u);
  }

  void swapValues(node_type* u, node_type* v) {
    int temp;
    temp = u->value;
    u->value = v->value;
    v->value = temp;
  }

  void print_inorder(node_type* node) {
    if (node != nullptr) {
      print_inorder(node->left);
      std::cout << node->value << " ";
      print_inorder(node->right);
    }
  }
};

#endif //RB_TREE_HPP
