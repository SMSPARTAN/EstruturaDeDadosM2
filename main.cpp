#include "include/HuffmanTree.hpp"
#include <format>

int main() {
  Huffman huffman;

  const char* str = "Lucas Andre Alexandre";

  huffman.build(str);

  const char* encoded = huffman.encode(str);

  huffman.printCodes();

  const char* decoded = huffman.decode(encoded);

  std::cout << std::format("{}\n", decoded);

  return 0;
}