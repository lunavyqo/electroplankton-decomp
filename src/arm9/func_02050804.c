// addr 0x02050804 size 0x18

typedef struct Node {
    int pad0;
    int pad1;
    struct Node *next;
} Node;

extern Node *data_02094734;
void func_02050894(Node **head, Node *target);

void func_02050804(Node *target) {
    func_02050894(&data_02094734, target);
}
