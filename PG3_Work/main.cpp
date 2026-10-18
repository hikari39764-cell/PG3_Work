#include <cstdio>
#include <cstdlib>

constexpr long long kNormalHourlyWage = 1226;

// 累計が通常の給料を超えるまで再帰する。
int CompareWages(int hours, long long recursiveHourlyWage, long long recursiveTotal) {
    const long long normalTotal = kNormalHourlyWage * hours;
    recursiveTotal += recursiveHourlyWage;

    std::printf("%d時間目: 通常の時給 %lld円 / 再帰の時給 %lld円 / 通常の累計 %lld円 / 再帰の累計 %lld円\n",
        hours, kNormalHourlyWage, recursiveHourlyWage, normalTotal, recursiveTotal);

    if (recursiveTotal > normalTotal) {
        return hours;
    }

    // 次の時給と累計を渡す。
    return CompareWages(hours + 1, recursiveHourlyWage * 2 - 50, recursiveTotal);
}

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    const int hours = CompareWages(1, 100, 0);
    std::printf("\n再帰の累計が通常の累計を初めて超えるのは%d時間働いたときです。\n", hours);

    return 0;
}
