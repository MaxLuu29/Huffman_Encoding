//
// Created by Max Luu on 11/16/18.
//

#include "LLPQ.h"
LLPQ::LLPQ() {
    first = NULL;
    last = NULL;
    size = 0;
}
LLPQ::~LLPQ() {
    LLNode *tmp = first;
    for (int i = 0; i < size; i++) {
        tmp = tmp->next;
        delete first;
        first = tmp;
    }
}

void LLPQ::printLLPQ() {
    LLNode* tmp = first;
    while(tmp != NULL) {
        tmp->printLLNode();
        tmp = tmp->next;
    }
    cout<<endl;
}

void LLPQ::addAtFirst(char x, int count, string co) {
    LLNode *tmp = first;
    first = new LLNode(x, co, count);
    first->next = tmp;
    size++;
}

void LLPQ::addFirst(char x, int count, string co) {
    first = new LLNode(x, co, count);
    last = first;
    size++;
}

LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd) {
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->count < pivot->count) {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;
    return pivot;
}

LLNode *getTail(LLNode *cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

LLNode *quickSortRecur(LLNode *head, LLNode *end) {
    if (!head || head == end)
        return head;

    LLNode *newHead = NULL, *newEnd = NULL;
    LLNode *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void LLPQ::sortLL() {
    first = quickSortRecur(first, getTail(first));
    LLNode* n = first;
    while (n->next != NULL) {
        n = n->next;
    }
    last = n;
}

string LLPQ::findCode(char k) {
    for (LLNode* tmp = first; tmp != NULL; tmp = tmp->next) {
        if (tmp->character == k) {
            return tmp->co;
        }
    }
    return "";

}

void LLPQ::sortLL2() {
    LLNode *current;
    LLNode *tmp;
    LLNode *tmpPar;
    LLNode *tmp2;
    LLNode *position;

    position = first;
    current = position;
    tmpPar = first;

    while (current != NULL && current->next != NULL) {
        tmp = current->next;
        if (tmp->count < current->count) {
            if (current == first) {
                tmp2 = tmp->next;
                first = tmp;
                tmp->next = current;
                current->next = tmp2;
            } else {
                tmp2 = tmp->next;
                tmpPar->next = tmp;
                tmp->next = current;
                current->next = tmp2;

            }
            position = first;
            current = position;
        } else {
            tmpPar = position;
            position = position->next;
            current = position;
        }
    }

    LLNode* tmp5 = first;
    while (tmp5->next != NULL) {
        tmp=tmp->next;
    }
    last = tmp;
}

void LLPQ::insertUnique(char c) {
    LLNode* tmp = first;
    bool dup = false;
    while (tmp != NULL) {
        if (tmp->character == c) {
            dup = true;
            tmp->count++;
            return;
        }
        tmp = tmp->next;
    }
    if (!dup) {
        addAtFirst(c, 1, "-1");
    }

}

void LLPQ::insertInOrder(LLNode *n) {
    if (size == 0) {
        first = n;
        last = first;
        size++;
        return;
    } else {
        if (n->count < first->count) {
            addAtFirst(n->character, n->count, n->co);
        } else if (last->count < n->count) {
            last->next = n;
            size++;
            last = n;
        } else {
            LLNode *tmp = first;
            while (n->count > tmp->next->count) {
                tmp = tmp->next;
            }
            LLNode *tmp2 = tmp->next;
            tmp->next = n;
            n->next = tmp2;
            size++;
        }
    }
}

LLNode* LLPQ::remFirst() {
    LLNode* r = first;
    first = first->next;
    size--;
    return r;
}
