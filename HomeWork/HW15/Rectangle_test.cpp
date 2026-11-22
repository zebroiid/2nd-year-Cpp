//
// Created by markp on 22/11/2026.
//
#include "Rectangle.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {
bool approxEqual(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

void testConstructorsAndGetters() {
    Rectangle defRect;
    assert(approxEqual(defRect.getX(), 0.0));
    assert(approxEqual(defRect.getY(), 0.0));
    assert(approxEqual(defRect.getWidth(), 1.0));
    assert(approxEqual(defRect.getHeight(), 1.0));

    Rectangle r(2.0, 5.0, 4.0, 3.0);
    assert(approxEqual(r.topSide(), 4.0));
    assert(approxEqual(r.bottomSide(), 4.0));
    assert(approxEqual(r.leftSide(), 3.0));
    assert(approxEqual(r.rightSide(), 3.0));
    assert(approxEqual(r.area(), 12.0));
    assert(approxEqual(r.perimeter(), 14.0));
}

void testInvalidDataRejected() {

    bool thrown = false;
    try {
        Rectangle bad1(0.0, 0.0, 0.0, 5.0);
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try {
        Rectangle bad2(1.0, 1.0, 4.0, -2.0);
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);


    std::istringstream badInput("1 2 -5 3");
    Rectangle r;
    thrown = false;
    try {
        badInput >> r;
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);
}

void testIntersection() {
    Rectangle a(0.0, 6.0, 6.0, 4.0);
    Rectangle b(3.0, 4.0, 5.0, 4.0);
    Rectangle inter = a.intersect(b);
    assert(inter == Rectangle(3.0, 4.0, 3.0, 2.0));


    Rectangle c(10.0, 10.0, 2.0, 2.0);
    Rectangle empty1 = a.intersect(c);
    assert(empty1 == Rectangle::emptySentinel());
    assert(empty1.isEmptySentinel());

    Rectangle touching(6.0, 6.0, 2.0, 4.0);
    Rectangle empty2 = a.intersect(touching);
    assert(empty2 == Rectangle::emptySentinel());
}

void testInputOutput() {
    std::istringstream iss("1.5 7.5 3.0 2.0");
    Rectangle r;
    iss >> r;

    assert(approxEqual(r.getX(), 1.5));
    assert(approxEqual(r.getY(), 7.5));
    assert(approxEqual(r.getWidth(), 3.0));
    assert(approxEqual(r.getHeight(), 2.0));

    std::ostringstream oss;
    oss << r;
    assert(oss.str() == "(1.5, 7.5, 3, 2)");
}
}

int main() {
    testConstructorsAndGetters();
    testInvalidDataRejected();
    testIntersection();
    testInputOutput();

    std::cout << "All tests passed!\n";
    return 0;
}