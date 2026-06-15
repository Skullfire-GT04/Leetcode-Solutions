#include <stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;


ListNode* deleteMiddle(ListNode* head){
    int len = 0;
    ListNode* curr_node = head;
    while(curr_node){
        len++;
        curr_node = curr_node->next;
    }
    if(len <= 1) return NULL;
    
    curr_node = head;
    ListNode* prev_node = NULL;
    int count = 0;
    while(count != len / 2){
        count++;
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    prev_node->next = curr_node->next;
    return head;
}


int main(){
    
    ListNode g = {6, NULL};
    ListNode f = {2, &g};
    ListNode e = {1, &f};
    ListNode d = {7, &e};
    ListNode c = {4, &d};
    ListNode b = {3, &c};
    ListNode a = {1, &b};

    ListNode* curr_node = deleteMiddle(&f);
    while(curr_node){
        printf("%d ", curr_node->val);
        curr_node = curr_node->next;
    }
    printf("\n");

    return 0;
}