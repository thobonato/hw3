#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

    // base case: head is nullptr, return
    if(head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    else if(head->val <= pivot){ // smaller than or eq to pivot
        smaller = head;
        llpivot(head->next, smaller->next, larger, pivot);
    }
    else{
        larger = head;
        llpivot(head->next, smaller, larger->next, pivot);
    }
}