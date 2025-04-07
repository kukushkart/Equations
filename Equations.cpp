#include "Equations.h"

LinearEquation::LinearEquation(const int& a, const int& b) : a(a), b(b) {}

LinearEquation::LinearEquation(const LinearEquation& other) : a(other.a), b(other.b) {}

void LinearEquation::Print() const {
    std::cout << a << "x " << (b >= 0 ? "+ " : "") << b << " = 0\n";
}

void LinearEquation::Solve() {
    if (a == 0 && b == 0) {
        std::cout << "Equation has infinity number of solutions\n";
    }
    else if (a == 0) {
        std::cout << "Equation has no solutions\n";
    }
    else {
        std::cout << "x = " << (double(-b) / a) << "\n";
    }
}

bool LinearEquation::HasNoSolution() const {
    return a == 0 && b != 0;
}

bool LinearEquation::HasInfiniteSolutions() const {
    return a == 0 && b == 0;
}

int LinearEquation::GetLeadingCoefficient() const {
    return a;
}

bool LinearEquation::IsQuadratic() const {
    return false;
}

bool LinearEquation::IsNegativeDiscriminant() const {
    return false;
}

bool LinearEquation::IsDownwardParabola() const {
    return false;
}

bool LinearEquation::IsPerfectSquare() const {
    return false;
}

bool LinearEquation::IsLinear() const {
    return true;
}

int LinearEquation::GetB() const {
    return b;
}

int LinearEquation::GetC() const {
    return 0;
}

int LinearEquation::GetA() const {
    return a;
}

QuadraticEquation::QuadraticEquation(int a, int b, int c) : a(a), b(b), c(c) {
    if (a == 0) {
        throw std::logic_error("A must be none zero");
    }
}

QuadraticEquation::QuadraticEquation(const QuadraticEquation& other)
    : QuadraticEquation(other.a, other.b, other.c) {}

void QuadraticEquation::Print() const {
    std::cout << a << "x^2 " << (b >= 0 ? "+ " : "") << b << "x " << (c >= 0 ? "+ " : "") << c << " = 0\n";
}

void QuadraticEquation::Solve() {
    double d = b * b - 4 * a * c;

    if (d < 0) {
        std::cout << "No solutions for this equation, d < 0!!!!";
    }
    else {
        std::cout << "x1 = " << (-b + std::pow(d, 0.5)) / (2 * a) << "\n";
        std::cout << "x2 = " << (-b - std::pow(d, 0.5)) / (2 * a) << "\n";
    }
}

bool QuadraticEquation::HasNoSolution() const {
    return (b * b - 4 * a * c) < 0;
}

bool QuadraticEquation::HasInfiniteSolutions() const {
    return false;
}

int QuadraticEquation::GetLeadingCoefficient() const {
    return a;
}

bool QuadraticEquation::IsQuadratic() const {
    return true;
}

bool QuadraticEquation::IsNegativeDiscriminant() const {
    return (b * b - 4 * a * c) < 0;
}

bool QuadraticEquation::IsDownwardParabola() const {
    return a < 0;
}

bool QuadraticEquation::IsPerfectSquare() const {
    double d = b * b - 4 * a * c;
    return d == 0;
}

bool QuadraticEquation::IsLinear() const {
    return false;
}

int QuadraticEquation::GetB() const {
    return b;
}

int QuadraticEquation::GetC() const {
    return c;
}

int QuadraticEquation::GetA() const {
    return 0;
}
