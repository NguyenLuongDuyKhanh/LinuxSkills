#include <iostream>

int main() {
    register int result asm ("r1");
    std::cout << result;
    return 0;
}