#include "../include/HuffmanTree.hpp"

int main() {
  HuffmanTree<int> HTree(50);

  HTree.insert(10);
  HTree.insert(30);
  HTree.insert(60);
  HTree.insert(20);
  HTree.insert(40);

  HTree.display(3);

  return 0;
}