#pragma once

template<typename T>
class Node {
public:
  T data;
  Node<T>* left;
  Node<T>* right;

  explicit Node(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};