#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For some reason LeetCode won't accept this answer, because it is too memory expensive
// the real solution is in the javascript file


typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


typedef struct{
    TreeNode** arr;
    size_t size;
    size_t start;
} Queue;

typedef struct{
    int* arr;
    size_t size;
    size_t start;
} ParentQueue;


#define isEmpty(queue) ((queue)->start >= (queue)->size) 
#define peek(queue) ((queue)->start >= (queue)->size ? 0 : (queue)->arr[(queue)->start])
#define get(queue, index) ((index) < (queue)->size ? (queue)->arr[(index)] : NULL)
#define dequeue(queue) \
    do{ \
        if((queue)->start < (queue)->size){ \
        (queue)->start++;        \
        }                        \
    } \
    while(0)



Queue* init_queue(){
    Queue* out = (Queue*) malloc(sizeof(Queue));
    out->size = 0;
    out->arr = NULL;
    out->start = 0;
    return out;
}

ParentQueue* init_parent_queue(){
    ParentQueue* out = (ParentQueue*) malloc(sizeof(ParentQueue));
    out->arr = NULL;
    out->size = 0;
    out->start = 0;
    return out;
}

void enqueue(Queue* queue, TreeNode* val) {
    queue->size++;  
    (queue)->arr = (TreeNode**) realloc((queue)->arr, sizeof(TreeNode*) * (queue)->size); 
    (queue)->arr[(queue)->size - 1] = val;  
}

void parent_enqueue(ParentQueue* queue, int val){
    queue->size++;
    queue->arr = (int*) realloc(queue->arr, sizeof(int) * queue->size);
    queue->arr[queue->size - 1] = val;
}



void add_value(char* val, char** builder, int* len, int val_len){
    (*len) += val_len;
    *builder = (char*) realloc((*builder), (*len) * sizeof(char));
    for(int i = 0; i < val_len; i++){
        (*builder)[(*len) - val_len + i] = val[i];
    }
}


char* int_to_str(int val, int* size){
    char* out = NULL;
    *size = 0;
    int div = 1;
        if(val < 0) {
        val = -val;
        out = (char*) malloc(sizeof(char));
        out[0] = '-';
        (*size)++;
    }
    while((int) (val / div) > 0) div *= 10;
    div /= 10;
    if(!val) div = 1;
    while(div > 0){
        (*size)++;
        char num = ((int) (val / div)) % 10 + '0';
        out = (char*) realloc(out, (*size) * sizeof(char));
        out[(*size) - 1] = num;
        div /= 10;
    }
    return out;
}

int str_to_int(char* data, int start, int end){
    int out = 0;
    int power = 1;
    int start_index = data[start] != '-' ? start : start + 1;
    for(int i = end; i >= start_index; --i){
        out += (data[i] - '0') * power;
        power *= 10;
    }
    return data[start] != '-' ? out : -out;
}


char* serialize(TreeNode* root){
    char* out = NULL;

    if(!root){
        out = (char*) malloc(sizeof(char));
        out[0] = '\0';
        return out;
    }
    int len = 0;
    Queue* nodes = init_queue();
    ParentQueue* parents  = init_parent_queue();
    ParentQueue* left_right_map = init_parent_queue();
    enqueue(nodes, root);
    parent_enqueue(parents, -1);
    parent_enqueue(left_right_map, -1);
    while(!isEmpty(nodes)){
        TreeNode* curr_node = peek(nodes);
        int parent = peek(parents);
        int left_or_right = peek(left_right_map);
        int curr_index = nodes->start;
        dequeue(nodes);
        dequeue(parents);
        dequeue(left_right_map);
        int val_len = 0, parent_len = 0, left_or_right_len = 0;
        char* str_val = int_to_str(curr_node->val, &val_len);
        char* str_parent = int_to_str(parent, &parent_len);
        char* str_left_or_right = int_to_str(left_or_right, &left_or_right_len);
        add_value(str_val, &out, &len, val_len);
        add_value(";", &out, &len, 1);
        add_value(str_parent, &out, &len, parent_len);
        add_value(";", &out, &len, 1);
        add_value(str_left_or_right, &out, &len, left_or_right_len);
        if(curr_node->left){
            enqueue(nodes, curr_node->left);
            parent_enqueue(parents, curr_index);
            parent_enqueue(left_right_map, 'l');
        }
        if(curr_node->right){
            enqueue(nodes, curr_node->right);
            parent_enqueue(parents, curr_index);
            parent_enqueue(left_right_map, 'r');
        }
        if(!isEmpty(nodes)) add_value(",", &out, &len, 1);
        free(str_val);
        free(str_parent);
        free(str_left_or_right);
    }
    add_value("\0", &out, &len, 1);
    free(nodes->arr);
    free(nodes);
    free(parents->arr);
    free(parents);
    free(left_right_map->arr);
    free(left_right_map);
    return out;
}

TreeNode* deserialize(char* data){
    Queue* nodes = init_queue();
    int len = strlen(data);
    if(!len) return NULL;
    int index = 0;
    while(index < len){
        int val_start_index = index;
        while(index < len && data[index] != ';') index++;
        int val_end_index = index - 1;
        int val = str_to_int(data, val_start_index, val_end_index);
        index++;
        int parent_start_index = index;
        while(index < len && data[index] != ';') index++;
        int parent_end_index = index - 1;
        int parent = str_to_int(data, parent_start_index, parent_end_index);
        index++;
        int left_or_right_start_index = index;
        while(index < len && data[index] != ',') index++;
        int left_or_right_end_index = index - 1;
        int left_or_right = str_to_int(data, left_or_right_start_index, left_or_right_end_index);
        index++;
        TreeNode* curr_node = (TreeNode*) malloc(sizeof(TreeNode));
        curr_node->val = val;
        curr_node->left = NULL;
        curr_node->right = NULL;
        if(parent >= 0){
            TreeNode* parent_node = get(nodes, parent);
            if(left_or_right == 'l'){
                parent_node->left = curr_node;
            }else if(left_or_right == 'r'){
                parent_node->right = curr_node;
            }
        }
        enqueue(nodes, curr_node);
    }

    TreeNode* root = get(nodes, 0);
    free(nodes->arr);
    free(nodes);
    return root;
}


void print_btree(TreeNode* root){
    Queue* nodes = init_queue();
    enqueue(nodes, root);
    printf("[ ");
    while(!isEmpty(nodes)){
        TreeNode* curr_node = peek(nodes);
        printf("%d", curr_node->val);
        dequeue(nodes);
        if(curr_node->left)
        enqueue(nodes, curr_node->left);
        if(curr_node->right)
        enqueue(nodes, curr_node->right);
        if(!isEmpty(nodes)) printf(", ");
    }
    printf(" ]\n");
    free(nodes);
}


int main(){

    TreeNode a = {5, NULL, NULL};
    TreeNode b = {4, NULL, NULL};
    TreeNode c = {3, &b, &a};
    TreeNode d = {2, NULL, NULL};
    TreeNode root = {1, &d, &c};
    printf("Original tree:\n");
    print_btree(&root);
    char* data = serialize(&root);
    printf("Serialized tree: %s\n", data);    
    TreeNode* copy_root = deserialize(data);
    printf("Deserialized tree:\n");
    print_btree(copy_root);
    return 0;
}