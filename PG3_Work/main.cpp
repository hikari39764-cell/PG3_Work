#include <cstdio>
#include <cstdlib>

void PrintHelloWorld() {
    std::printf("Hello, World!\n");
    std::printf("こんにちは！\n");
}

int main() {
    // コンソールの文字コードをUTF-8に設定する。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    PrintHelloWorld();
    return 0;
}
