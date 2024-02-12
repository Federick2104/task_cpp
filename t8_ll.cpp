//
// Created by Federico Schianchi on 07/12/23.
//
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void addAtTheBeginning(node* &lst, int x) {
    node* new_node = new node;
    new_node->data = x;
    new_node->next = lst;
    lst = new_node;
}

void addAtTheEnd(node* &lst, int x) {
    if (lst == nullptr) {
        addAtTheBeginning(lst, x);
        return;
    }

    node* new_node = new node;
    new_node->data = x;
    new_node->next = nullptr;

    node* cursor = lst;
    while (cursor->next != nullptr)
        cursor = cursor->next;
    cursor->next = new_node;
}

bool containsRec(node* lst, int elem) {
    if (lst == nullptr)
        return false;
    else if (lst->data == elem)
        return true;
    else
        return containsRec(lst->next, elem);
}

node* union_(node* l1, node* l2){
    node* res = nullptr;
    while (l1 != nullptr) {
        if(!containsRec(res,l1->data))
            addAtTheEnd(res, l1->data);
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        if(!containsRec(res,l2->data))
            addAtTheEnd(res, l2->data);
        l2 = l2->next;
    }
    return res;
}

void printRec(node* lst) {
    if (lst == nullptr)
        return;
    cout << lst->data << "  ";
    printRec(lst->next);
}

int main(){
    node* l1 = nullptr;
    node* l2 = nullptr;
    //l1: 1 -> 2 -> 2 -> 3 -> 5 -> 7 -> -4 -> 5 -> 7
    int nl1[] = {1,2,2,3,5,7,-4,5,7};
    for(int i = 0; i < 9; i++)
        addAtTheEnd(l1,nl1[i]);

    //l2: 1 -> 3 -> 6 -> 1 -> 5 -> 12 -> 12
    int nl2[] = {1,3,6,1,5,12,12};
    for(int i = 0; i < 7; i++)
        addAtTheEnd(l2, nl2[i]);

    //union function
    node* l4 = union_(l1,l2);
    printRec(l4);


    return 0;
}