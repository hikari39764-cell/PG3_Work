#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
    // 待機後にコールバックを呼ぶ。
    Sleep(delayMs);
    fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
    std::printf("出目は %d でした。\n", roll);
    std::printf("%s\n", roll % 2 == userGuess ? "正解" : "不正解");
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
    std::printf("サイコロを振っています……\n");
    std::fflush(stdout);
    DelayReveal(ShowResult, 3000, roll, userGuess);
    return 0;
}
