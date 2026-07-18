// addr 0x0205081c size 0x18

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

extern Node *data_0209472c;
void func_02050894(Node **head, Node *target);

void func_0205081c(Node *target) {
    func_02050894(&data_0209472c, target);
}
