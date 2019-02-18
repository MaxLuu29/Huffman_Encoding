//
// Created by Max Luu on 11/16/18.
//

#include "LLHuff.h"
LLHuff::LLHuff(string f) {
    file = f;
    root = NULL;
    size = 0;
    pq = new LLPQ();
    ascii = new LLPQ();
}

LLHuff::~LLHuff() {

}

void LLHuff::ReadFile() {
    ifstream infile(file.c_str(),ios::in); // open file
    char k;
    while (infile.get(k)) { // loop getting single characters
        pq->insertUnique(k);// inserting the character k into the priority queue
    }
    infile.close();
}

void LLHuff::ReadAscii() {
    cout << file << endl;
    ifstream infile("asciitable.txt",ios::in);
    char ch;
    string asciicode;
    if (!infile.is_open()) {
        return;
    }

    infile >> asciicode;
    pq->addFirst(' ',0,asciicode);
    infile >> asciicode;
    while (infile>>ch) {
        cout << ch;
        infile>>asciicode;
        cout << asciicode << endl;
        pq->addAtFirst(ch,0,asciicode);
    }
    cout << endl;
    infile.close();
    //////////////////////
    ifstream infile2(file.c_str(),ios::in); // open file for reading
    ofstream outfile("asciivsn.txt",ios::out);
    char k;
    string comp;
    while (infile2.get(k)) {
        cout << k;
        comp = pq->findCode(k);
        if (comp == "") {
            cout << "ERROR WITH " << k << endl;
        } else {
            cout << k << ":" << comp << endl;
            outfile << comp << " ";
        }
    }
    cout << endl;
    infile2.close();
    outfile.close();
}

void LLHuff::compressFile() {
    FindCode(root);
    ifstream infile(file.c_str(),ios::in);
    char k;
    ofstream outfile("compressed.txt", ios::out);
    while (infile.get(k)) {
        cout<<k<<endl;
        pq->printLLPQ();
        cout << getCode(pq->first,k) << endl;
        outfile << getCode(pq->first,k)->co << " ";
    }
    infile.close();
    outfile.close();
}
void LLHuff::MakeHuff() {
    LLNode* tmp1;
    LLNode* tmp2;
    LLNode* tmp3;
    while (pq->size > 1) {
        tmp1 = pq->remFirst();
        tmp2 = pq->remFirst();
        int ct = tmp1->count + tmp2->count;
        LLNode* N = new LLNode('*', "", ct);
        N->left = tmp1;
        N->right = tmp2;
        pq->insertInOrder(N);
        N->count = ct;
        tmp3 = N;
    }
    root = tmp3;
}
void LLHuff::FindCode(LLNode *tmp) {
    if (tmp == NULL) {
        return;
    }
    if (tmp->left != NULL) {
        tmp->left->co = tmp->co + "0";
    }
    if (tmp->right != NULL) {
        tmp->right->co = tmp->co + "1";
    }
    FindCode(tmp->left);
    FindCode(tmp->right);
}

LLNode* LLHuff::getCode(LLNode *tmp, char k) {
    if (tmp == NULL) {
        return NULL;
    }
    if (tmp->character == k) {
        return tmp;
    }
    LLNode* output = getCode(tmp->left,k);
    if (output == NULL)
        output = getCode(tmp->right,k);
    return output;
}

void LLHuff::printTreeIO(LLNode* root) {
    if (root == NULL) {
        return;
    } else {
        root->printLLNode();
        printTreeIO(root->left);
        printTreeIO(root->right);

    }
}
