#pragma once

#include "Node.hpp"
#include <iostream>

template <typename T>
class HuffmanTree {
private:
  Node<T> *root;

  Node<T> *insert(Node<T> *node, T data) {
    if (!node) {
      return new Node<T>(data);
    }

    if (data < node->data) {
      node->left = insert(node->left, data);
    } else if (data > node->data) {
      node->right = insert(node->right, data);
    }

    return node;
  }

  bool search(Node<T> *node, T data) {
    if (!node) {
      return false;
    }

    if (data == node->data) {
      return true;
    }

    if (data < node->data) {
      return search(node->left, data);
    }

    return search(node->right, data);
  }

  void inorder(Node<T> *node) {
    if (!node) {
      return;
    }

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
  }

  void preorder(Node<T> *node) {
    if (!node) {
      return;
    }

    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }

  void postorder(Node<T> *node) {
    if (!node) {
      return;
    }

    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
  }

public:
  explicit HuffmanTree(T rootData) {
    root = new Node<T>(rootData);
  }

  void insert(T data) {
    insert(root, data);
  }

  void display(const int &type) {
    switch (type) {
    case 1:
      preorder(root);
      break;
    case 2:
      postorder(root);
      break;
    case 3:
      inorder(root);
      break;
    default:
      std::cout << "Invalid display type!\nPlease select either 1 - Preorder | 2 - Postorder | 3 - Inorder\n";
      break;
    }

    std::cout << std::endl;
  }

  bool search(T data) {
    return search(root, data);
  }

  friend Node<T>;
};