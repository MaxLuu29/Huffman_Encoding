/*
 * File: main.cpp
 * Author: Max Luu
 */
#include <iostream>
#include <stdlib.h>
#include "LLHuff.h"
#include "LLNode.h"
#include "LLPQ.h"
using namespace std;
int main() {
    cout<<"reading file"<<endl;
    LLHuff code("Monet.txt");
    code.ReadFile();
    code.pq->sortLL();
    code.pq->printLLPQ();
    code.MakeHuff();
    code.compressFile();
    //code.printTreeIO(code.root);
    code.ReadAscii();
    return 0;
}
