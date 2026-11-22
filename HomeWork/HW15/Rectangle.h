//
// Created by markp on 22/11/2026.
//


#include <iosfwd>
#include <string>

class Rectangle {
private:
    double x_;
    double y_;
    double width_;
    double height_;


    Rectangle(double x, double y, double width, double height, bool allowSentinel);

    static void validateParams(double x, double y, double width, double height);

public:

    Rectangle();


    Rectangle(double x, double y, double width, double height);


    static Rectangle emptySentinel();


    bool isEmptySentinel() const noexcept;


    double getX() const noexcept;
    double getY() const noexcept;
    double getWidth() const noexcept;
    double getHeight() const noexcept;

    double topSide() const noexcept;
    double bottomSide() const noexcept;
    double leftSide() const noexcept;
    double rightSide() const noexcept;


    double area() const noexcept;
    double perimeter() const noexcept;


    Rectangle intersect(const Rectangle& other) const;


    void input(std::istream& in);
    void print(std::ostream& out) const;

    bool operator==(const Rectangle& other) const noexcept;
    bool operator!=(const Rectangle& other) const noexcept;
};

std::istream& operator>>(std::istream& in, Rectangle& rect);
std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

