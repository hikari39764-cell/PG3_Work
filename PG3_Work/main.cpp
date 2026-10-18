#include <cstdio>
#include <cstdlib>

class Enemy {
public:
    void Update() {
        // 現在の行動を呼び出す。
        if (action_ != nullptr) {
            (this->*action_)();
        }
    }

    bool IsFinished() const {
        return action_ == nullptr;
    }

private:
    void Approach() {
        std::printf("接近\n");
        action_ = &Enemy::Shoot;
    }

    void Shoot() {
        std::printf("射撃\n");
        action_ = &Enemy::Retreat;
    }

    void Retreat() {
        std::printf("離脱\n");
        action_ = nullptr;
    }

    // メンバ関数ポインタで状態を持つ。
    using Action = void (Enemy::*)();
    Action action_ = &Enemy::Approach;
};

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    Enemy enemy;
    while (!enemy.IsFinished()) {
        enemy.Update();
    }
    return 0;
}
