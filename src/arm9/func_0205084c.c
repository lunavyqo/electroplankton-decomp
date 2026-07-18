// addr 0x0205084c size 0x18

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

extern Node *data_0209472c;
void func_02050928(Node **head, Node *node);

void func_0205084c(Node *node) {
    func_02050928(&data_0209472c, node);
}
