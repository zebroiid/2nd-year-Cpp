//
// Created by markp on 22/11/2026.
//
#include "Rectangle.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>



Rectangle::Rectangle(double x, double y, double width, double height, bool allowSentinel)
    : x_(x), y_(y), width_(width), height_(height) {
    if (!allowSentinel) {
        validateParams(x, y, width, height);
    }
}

void Rectangle::validateParams(double x, double y, double width, double height) {

    if (width <= 0.0 || height <= 0.0) {
        throw std::invalid_argument("Length must be greater than 0.");
    }
}

Rectangle::Rectangle() : x_(0.0), y_(0.0), width_(1.0), height_(1.0) {}

Rectangle::Rectangle(double x, double y, double width, double height)
    : x_(x), y_(y), width_(width), height_(height) {
    validateParams(x, y, width, height);
}

Rectangle Rectangle::emptySentinel() {
    return Rectangle(-1.0, -1.0, -1.0, -1.0, true);
}

bool Rectangle::isEmptySentinel() const noexcept {
    return x_ == -1.0 && y_ == -1.0 && width_ == -1.0 && height_ == -1.0;
}

double Rectangle::getX() const noexcept { return x_; }
double Rectangle::getY() const noexcept { return y_; }
double Rectangle::getWidth() const noexcept { return width_; }
double Rectangle::getHeight() const noexcept { return height_; }

double Rectangle::topSide() const noexcept { return isEmptySentinel() ? -1.0 : width_; }
double Rectangle::bottomSide() const noexcept { return isEmptySentinel() ? -1.0 : width_; }
double Rectangle::leftSide() const noexcept { return isEmptySentinel() ? -1.0 : height_; }
double Rectangle::rightSide() const noexcept { return isEmptySentinel() ? -1.0 : height_; }

double Rectangle::area() const noexcept {
    if (isEmptySentinel()) {
        return 0.0;
    }
    return width_ * height_;
}

double Rectangle::perimeter() const noexcept {
    if (isEmptySentinel()) {
        return 0.0;
    }
    return 2.0 * (width_ + height_);
}

Rectangle Rectangle::intersect(const Rectangle& other) const {
    if (isEmptySentinel() || other.isEmptySentinel()) {
        return emptySentinel();
    }

    const double leftA = x_;
    const double rightA = x_ + width_;
    const double topA = y_;
    const double bottomA = y_ - height_;

    const double leftB = other.x_;
    const double rightB = other.x_ + other.width_;
    const double topB = other.y_;
    const double bottomB = other.y_ - other.height_;

    const double interLeft = std::max(leftA, leftB);
    const double interRight = std::min(rightA, rightB);
    const double interTop = std::min(topA, topB);
    const double interBottom = std::max(bottomA, bottomB);

    const double interWidth = interRight - interLeft;
    const double interHeight = interTop - interBottom;


    if (interWidth <= 0.0 || interHeight <= 0.0) {
        return emptySentinel();
    }


    return Rectangle(interLeft, interTop, interWidth, interHeight);
}

void Rectangle::input(std::istream& in) {
    double x = 0.0;
    double y = 0.0;
    double width = 0.0;
    double height = 0.0;

    if (!(in >> x >> y >> width >> height)) {
        in.setstate(std::ios::failbit);
        throw std::invalid_argument("Error reading rectangle.");
    }

    validateParams(x, y, width, height);

    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
}

void Rectangle::print(std::ostream& out) const {
    out << "(" << x_ << ", " << y_ << ", " << width_ << ", " << height_ << ")";
}

bool Rectangle::operator==(const Rectangle& other) const noexcept {
    constexpr double eps = 1e-9;
    return std::fabs(x_ - other.x_) < eps &&
           std::fabs(y_ - other.y_) < eps &&
           std::fabs(width_ - other.width_) < eps &&
           std::fabs(height_ - other.height_) < eps;
}

bool Rectangle::operator!=(const Rectangle& other) const noexcept {
    return !(*this == other);
}

std::istream& operator>>(std::istream& in, Rectangle& rect) {
    rect.input(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
    rect.print(out);
    return out;
}