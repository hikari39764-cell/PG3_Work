#include <cstdio>
#include <cstdlib>

// 小さい方の値を返す。
template <typename T>
T Min(T first, T second) {
    return first < second ? first : second;
}

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    std::printf("int型: Min(10, 20) = %d\n", Min(10, 20));
    std::printf("float型: Min(3.5f, 2.5f) = %.2f\n", Min(3.5f, 2.5f));
    std::printf("double型: Min(1.25, 4.75) = %.2f\n", Min(1.25, 4.75));

    return 0;
}
