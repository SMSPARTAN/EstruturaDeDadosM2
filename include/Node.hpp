// Node.hpp
#pragma once

class Node {
public:
  char data;
  int frequency;
  Node *left;
  Node *right;

  Node(char data, int frequency) {
    this->data = data;
    this->frequency = frequency;
    this->left = nullptr;
    this->right = nullptr;
  }

  Node(int frequency, Node *left, Node *right) {
    this->data = '\0'; // internal node
    this->frequency = frequency;
    this->left = left;
    this->right = right;
  }
};
