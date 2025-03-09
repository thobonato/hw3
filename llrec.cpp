#include "llrec.h"

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
        Node* tmp = head->next;
        smaller = head;
        head = nullptr;
        llpivot(tmp, smaller->next, larger, pivot);
    }
    else{
        Node* tmp = head->next;
        larger = head;
        head = nullptr;
        llpivot(tmp, smaller, larger->next, pivot);
    }
}