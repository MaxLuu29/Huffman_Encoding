//
// Created by Max Luu on 11/16/18.
//

#ifndef HUFFMAN_LLNODE_H
#define HUFFMAN_LLNODE_H
#include <iostream>
using namespace std;
class LLNode {
    friend class LLPQ;
public:
    //void setCount(int x);
    char character;
    string co;
    int count;
    LLNode* left;
    LLNode* right;
    LLNode* next;
    LLNode();
    ~LLNode();
    LLNode(char x, string co);
    LLNode(char x, string co, int c);

    void printLLNode();
};
#endif //HUFFMAN_LLNODE_H
