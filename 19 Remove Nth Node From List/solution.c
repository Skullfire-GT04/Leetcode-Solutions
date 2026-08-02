#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;


ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode** nodes = NULL;
    ListNode* curr_node = head;
    int count = 0;
    while(curr_node){
        nodes = (ListNode**) realloc(nodes, sizeof(ListNode*) * (count + 1));
        nodes[count++] = curr_node;
        curr_node = curr_node->next;
    }
    int index = count - n;
    if(!index){
        if(count < 2) return NULL;
        else return nodes[1];
    }else{
        if(index + 1 < count){
            nodes[index - 1]->next = nodes[index + 1];
        }else{
            nodes[index - 1]->next = NULL;
        }
    }
    return head;
}


void print_list(ListNode* head){
    ListNode* curr_node = head;
    while(curr_node){
        printf("%d", curr_node->val);
        if(curr_node->next){
            printf(", ");
        }
        curr_node = curr_node->next;
    }
    printf("\n");
}


int main(){
    ListNode e = {5, NULL};
    ListNode d = {4, &e};
    ListNode c = {3, &d};
    ListNode b = {2, &c};
    ListNode a = {1, &b};

    printf("List before removing: \n");
    print_list(&a);
    ListNode* head = removeNthFromEnd(&a, 5);
    printf("List after removing: \n");
    print_list(head);

    return 0;
}