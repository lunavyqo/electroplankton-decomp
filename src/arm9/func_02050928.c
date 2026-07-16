// addr 0x02050928 size 0x14

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

void func_02050928(Node **head, Node *node) {
    if (head != 0) {
        node->next = *head;
        *head = node;
    }
}
