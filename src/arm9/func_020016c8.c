// addr 0x020016c8 size 0x60

typedef struct {
    int pad00;
    int pad04;
    void *buf;
    int off;
    int size;
    int pad14;
    int pad18;
} Msg_020016c8; // 0x1c

extern void (*data_0205d020[])(Msg_020016c8 *);
extern void (*data_0205d05c[])(Msg_020016c8 *);

void func_020016c8(int mode, int idx, void *buf, int off, int size) {
    Msg_020016c8 msg;

    msg.buf = buf;
    msg.off = off;
    msg.size = size;
    if (mode == 1) {
        data_0205d020[idx](&msg);
    } else {
        data_0205d05c[idx](&msg);
    }
}
