// addr 0x020508e0 size 0x48

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

void func_020508e0(Node **head, Node *node) {
    Node *cur;
    Node *n;
    if (head == 0) {
        return;
    }
    cur = *head;
    if (cur == 0) {
        cur = 0;
        node->next = cur;
        *head = node;
        return;
    }
    n = cur->next;
    if (n != 0) {
        do {
            cur = n;
            n = n->next;
        } while (n != 0);
    }
    node->next = n;
    cur->next = node;
}
