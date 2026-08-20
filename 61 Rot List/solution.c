#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;


typedef struct {
    ListNode** nodes;
    size_t capacity;
    size_t count;
} Nodes;


Nodes* init_nodes(){
    Nodes* out = (Nodes*) malloc(sizeof(Nodes));
    out->capacity = 128;
    out->count = 0;
    out->nodes = (ListNode**) malloc(sizeof(ListNode*) * out->capacity);
    return out;
}


void push(Nodes* nodes, ListNode* val){
    if(nodes->count == nodes->capacity){
        nodes->capacity *= 2;
        nodes->nodes = (ListNode**) realloc(nodes->nodes, sizeof(ListNode*) * nodes->capacity);
    }
    nodes->nodes[nodes->count] = val;
    nodes->count++;
}

void delete_nodes(Nodes* nodes){
    free(nodes->nodes);
}


ListNode* rotateRight(ListNode* head, int k){
    if(!head) return NULL;
    Nodes* nodes = init_nodes();
    ListNode* curr_node = head;
    ListNode* out = head;
    while(curr_node){
        push(nodes, curr_node);
        curr_node = curr_node->next;
    }
    unsigned int shift_amount = k - (nodes->count * (int)(k / nodes->count));
    
    if(shift_amount){
        nodes->nodes[nodes->count - 1]->next = nodes->nodes[0];
        out = nodes->nodes[nodes->count - shift_amount];
        nodes->nodes[nodes->count - (shift_amount + 1)]->next = NULL;
    }
    
    delete_nodes(nodes);
    free(nodes);
    return out;
}   


void printf_nodes(ListNode* head){
    ListNode* curr_node = head;
    while(curr_node){
        printf("%d ", curr_node->val);
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

    printf("Before rotating:\n");
    printf_nodes(&a);

    ListNode* rot_head = rotateRight(&a, 7);
    printf("After rotating:\n");
    printf_nodes(rot_head);

    return 0;
}