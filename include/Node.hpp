// Node.hpp
#pragma once

class Node {
public:
  char data; // Armazena o caractere representado por esse nó (só nos nós folha).
  int frequency; // Frequência do caractere (ou soma das frequências dos filhos, se nó interno).
  Node *left; // Ponteiros para os filhos esquerdo e direito.
  Node *right;

  // Construtor folha, cria um nó com caractere e frequência.
  Node(char data, int frequency) {
    this->data = data;
    this->frequency = frequency;
    this->left = nullptr;
    this->right = nullptr;
  }

  // Construtor interno, cria um nó com dois filhos, somando suas frequências. O campo data é ignorado.
  Node(int frequency, Node *left, Node *right) {
    this->data = '\0'; // internal node
    this->frequency = frequency;
    this->left = left;
    this->right = right;
  }
};
