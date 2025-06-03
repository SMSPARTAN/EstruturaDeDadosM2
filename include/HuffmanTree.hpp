// Huffman.hpp
#pragma once

#include "Node.hpp"
#include <iostream>

class Huffman {
private:
  Node *heap[256]; // Vetor para organizar os nós por frequência.
  int heapSize; // Quantidade atual de elementos na heap.
  char *codes[256]; // Vetor que armazena os códigos binários para cada caractere ASCII.
  char buffer[256]; // Usado temporariamente para montar os códigos durante a recursão.

  void swap(int i, int j) {
    Node *temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }

  void heapifyUp(int index) {
    while (index > 0 && heap[index]->frequency < heap[(index - 1) / 2]->frequency) {
      swap(index, (index - 1) / 2);
      index = (index - 1) / 2;
    }
  }

  void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left]->frequency < heap[smallest]->frequency)
      smallest = left;
    if (right < heapSize && heap[right]->frequency < heap[smallest]->frequency)
      smallest = right;

    if (smallest != index) {
      swap(index, smallest);
      heapifyDown(smallest);
    }
  }

  // Insere o nó no heap.
  void insertHeap(Node *node) {
    heap[heapSize] = node;
    heapifyUp(heapSize);
    heapSize++;
  }

  // Extrai o menor nó
  Node* extractMin() {
    Node *min = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return min;
  }

  // Cria o código
  void buildCodes(Node *node, int depth) {
    if (!node)
      return;

    if (!node->left && !node->right) {
      char *code = new char[depth + 1];
      for (int i = 0; i < depth; ++i)
        code[i] = buffer[i];
      code[depth] = '\0';
      codes[(unsigned char)node->data] = code;
      return;
    }

    buffer[depth] = '0';
    buildCodes(node->left, depth + 1);

    buffer[depth] = '1';
    buildCodes(node->right, depth + 1);
  }

public:
  Node *root;
  Huffman() : heapSize(0), root(nullptr) {
    for (int i = 0; i < 256; ++i) {
      codes[i] = nullptr;
    }
  }


  // Cria a árvore e à codifica
  void build(const char *text) {
    int freq[256] = {0};
    for (int i = 0; text[i] != '\0'; ++i) {
      freq[(unsigned char)text[i]]++;
    }

    for (int i = 0; i < 256; ++i) {
      if (freq[i] > 0) {
        insertHeap(new Node((char)i, freq[i]));
      }
    }

    while (heapSize > 1) {
      Node *a = extractMin();
      Node *b = extractMin();
      insertHeap(new Node(a->frequency + b->frequency, a, b));
    }

    root = (heapSize == 1) ? heap[0] : nullptr;
    buildCodes(root, 0);
  }

  // Imprime a string codificada
  void printCodes() {
    char output[8192];
    int index = 0;
    for (int i = 0; i < 256; ++i) {
      if (codes[i]) {
        for (int j = 0; codes[i][j] != '\0'; ++j) {
          output[index++] = codes[i][j];
        }
      }
    }
    output[index] = '\0';
    std::cout << output << '\n';
  }

  // Retorna a codificação da string informada como parâmetro.
  const char* encode(const char *text) {
    static char encoded[8192];
    int index = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
      char *code = codes[(unsigned char)text[i]];
      for (int j = 0; code[j] != '\0'; ++j) {
        encoded[index++] = code[j];
      }
    }
    encoded[index] = '\0';
    return encoded;
  }

  // Decodifica a string informada como parâmetro
  const char* decode(const char *bits) {
    static char decoded[2048];
    int index = 0;
    Node *current = root;
    for (int i = 0; bits[i] != '\0'; ++i) {
      if (bits[i] == '0')
        current = current->left;
      else
        current = current->right;

      if (!current->left && !current->right) {
        decoded[index++] = current->data;
        current = root;
      }
    }
    decoded[index] = '\0';
    return decoded;
  }
};
