#include <cstdio>
#include <cstdlib>

// 図形の共通インターフェイス。
class IShape {
public:
    virtual ~IShape() = default;
    virtual void Size() = 0;
    virtual void Draw() = 0;

protected:
    double area_ = 0.0;
};

class Circle : public IShape {
public:
    explicit Circle(double radius) : radius_(radius) {}

    void Size() override {
        area_ = 3.141592653589793 * radius_ * radius_;
    }

    void Draw() override {
        std::printf("円（半径 %.1f）：面積 %.2f\n", radius_, area_);
    }

private:
    double radius_;
};

class Rectangle : public IShape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    void Size() override {
        area_ = width_ * height_;
    }

    void Draw() override {
        std::printf("矩形（幅 %.1f、高さ %.1f）：面積 %.2f\n", width_, height_, area_);
    }

private:
    double width_;
    double height_;
};

int main() {
    // コンソールをUTF-8にする。
    if (std::system("chcp 65001 > nul") != 0) {
        std::fprintf(stderr, "Failed to set the console code page to UTF-8.\n");
        return 1;
    }

    Circle circle(2.0);
    Rectangle rectangle(3.0, 4.0);
    IShape* shapes[] = {&circle, &rectangle};

    // 面積を計算してから表示する。
    for (IShape* shape : shapes) {
        shape->Size();
        shape->Draw();
    }
    return 0;
}
