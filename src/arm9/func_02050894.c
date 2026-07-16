// addr 0x02050894 size 0x4c

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

void func_02050894(Node **head, Node *target) {
    Node *cur;
    Node *prev;
    if (head == 0) {
        return;
    }
    cur = *head;
    prev = cur;
    if (cur == 0) {
        return;
    }
    while (1) {
        if (cur == target) {
            if (cur == prev) {
                *head = cur->next;
            } else {
                prev->next = cur->next;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
        if (cur == 0) {
            return;
        }
    }
}
