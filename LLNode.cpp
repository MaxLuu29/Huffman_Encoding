//
// Created by Max Luu on 11/16/18.
//

#include "LLNode.h"
LLNode::LLNode() {
    character = '*';
    co = "-1";
    count = 0;
    left = NULL;
    right = NULL;
    next = NULL;
}

LLNode::LLNode(char x, string code) {
    character = x;
    co = code;
    count = 1;
    left = NULL;
    right = NULL;
    next = NULL;
}

LLNode::LLNode(char x, string code, int c) {
    character = x;
    co = code;
    count = c;
    left = NULL;
    right = NULL;
    next = NULL;
}
LLNode::~LLNode() {
    cout<<"deleting "<< character << ", " << co << endl;
}

void LLNode::printLLNode() {
    cout << "char: " << character << ",";
    cout << "code: " << co << ", ";
    cout << "count: " << count << ", "<<endl;
}
