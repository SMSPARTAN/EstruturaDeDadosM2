#include "include/HuffmanTree.hpp"

int main() {
  HuffmanTree<int> HTree(50);

  HTree.insert(30);
  HTree.insert(10);
  HTree.insert(20);
  HTree.insert(60);
  HTree.insert(70);
  HTree.insert(65);

  HTree.display(1);

  return 0;
}