int main() {
    asm ("KHANH_LABEL_1");
    int a{123};
    asm ("KHANH_LABEL_2");
    for (int i=0; i<10; i++) {
        a+=i;
    }
    return a-a;
}