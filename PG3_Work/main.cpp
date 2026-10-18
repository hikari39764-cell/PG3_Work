#include <cstdio>
#include <type_traits>

// 2つの型を受け取るクラステンプレート。
template <typename T, typename U>
class Minimum {
public:
    std::common_type_t<T, U> Min(T first, U second) const {
        // 共通の型にして小数を保つ。
        using Result = std::common_type_t<T, U>;
        return first < second ? static_cast<Result>(first) : static_cast<Result>(second);
    }
};

int main() {
    // 同じ型3組と異なる型3組。
    Minimum<int, int> intInt;
    Minimum<float, float> floatFloat;
    Minimum<double, double> doubleDouble;
    Minimum<int, float> intFloat;
    Minimum<int, double> intDouble;
    Minimum<float, double> floatDouble;

    std::printf("int / int: Min(8, 3) = %d\n", intInt.Min(8, 3));
    std::printf("float / float: Min(3.5f, 2.5f) = %.3f\n", floatFloat.Min(3.5f, 2.5f));
    std::printf("double / double: Min(9.75, 4.125) = %.3f\n", doubleDouble.Min(9.75, 4.125));
    std::printf("int / float: Min(4, 3.5f) = %.3f\n", intFloat.Min(4, 3.5f));
    std::printf("int / double: Min(4, 3.25) = %.3f\n", intDouble.Min(4, 3.25));
    std::printf("float / double: Min(4.5f, 3.125) = %.3f\n", floatDouble.Min(4.5f, 3.125));
    return 0;
}
