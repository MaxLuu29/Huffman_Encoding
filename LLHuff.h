//
// Created by Max Luu on 11/16/18.
//

#ifndef HUFFMAN_LLHUFF_H
#define HUFFMAN_LLHUFF_H
#include <iostream>
#include <fstream>
#include "LLPQ.h"
using namespace std;
class LLHuff {
public:
    string file;
    LLNode *root;
    int size;

    LLPQ *pq;
    LLPQ *ascii;
    LLHuff(string f);
    ~LLHuff();
    void MakeHuff();
    void FindCode(LLNode *root);
    LLNode* getCode(LLNode *tmp, char k);
    void ReadFile();
    void compressFile();
    void ReadAscii();
    void printTreeIO(LLNode* root);

};

#endif //HUFFMAN_LLHUFF_H
