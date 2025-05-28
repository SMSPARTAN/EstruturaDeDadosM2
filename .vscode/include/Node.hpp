#pragma once

template<typename T>
class Node {
public:
  T data;
  T* left;
  T* right;

  explicit Node(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};