// addr 0x02050834 size 0x18

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

extern Node *data_02094734;
void func_020508e0(Node **head, Node *node);

void func_02050834(Node *node) {
    func_020508e0(&data_02094734, node);
}
