//
// Created by Max Luu on 11/16/18.
//

#ifndef HUFFMAN_LLPQ_H
#define HUFFMAN_LLPQ_H
#include <iostream>
#include <string>
#include "LLNode.h"
using namespace std;
class LLPQ {
public:
    friend class LLHuff;
    LLNode *first;
    LLNode *last;
    int size;
    LLPQ();
    void sortLL2();
    ~LLPQ();
    void printLLPQ();
    void addFirst(char x, int count, string co = "");
    void addAtFirst(char x, int count, string co = "");
    LLNode *remFirst();
    string findCode(char k);
    void sortLL();
    void insertUnique(char c);
    void insertInOrder(LLNode *n);

};
#endif //HUFFMAN_LLPQ_H
