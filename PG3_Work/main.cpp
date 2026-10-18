#include <cstdio>
#include <cstdlib>

class Animal {
public:
    virtual ~Animal() = default;

    virtual void Speak() const {
        std::printf("動物が鳴く\n");
    }
};

class Dog : public Animal {
public:
    void Speak() const override {
        std::printf("犬：ワンワン\n");
    }
};

class Cat : public Animal {
public:
    void Speak() const override {
        std::printf("猫：ニャーニャー\n");
    }
};

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    Animal animal;
    Dog dog;
    Cat cat;
    Animal* animals[] = {&animal, &dog, &cat};

    // 基底クラス経由で別々の処理を呼ぶ。
    for (const Animal* current : animals) {
        current->Speak();
    }
    return 0;
}
