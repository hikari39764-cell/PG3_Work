#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <Windows.h>

void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
    // 待機後にラムダ式を呼ぶ。
    Sleep(delayMs);
    fn(roll, userGuess);
}

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int userGuess = 0;
    std::printf("半（奇数）は1、丁（偶数）は0を入力してください：");
    std::fflush(stdout);
    if (scanf_s("%d", &userGuess) != 1 || (userGuess != 0 && userGuess != 1)) {
        std::printf("0または1を入力してください。\n");
        return 1;
    }

    const int roll = std::rand() % 6 + 1;
    const auto ShowResult = [](int resultRoll, int guess) {
        std::printf("出目は %d でした。\n", resultRoll);
        std::printf("%s\n", resultRoll % 2 == guess ? "正解" : "不正解");
    };

    std::printf("サイコロを振っています……\n");
    std::fflush(stdout);
    DelayReveal(ShowResult, 3000, roll, userGuess);
    return 0;
}
