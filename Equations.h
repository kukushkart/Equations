#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <stdexcept>

class Equation {
public:
    virtual void Print() const = 0;
    virtual void Solve() = 0;
    virtual bool HasNoSolution() const = 0;
    virtual bool HasInfiniteSolutions() const = 0;
    virtual int GetLeadingCoefficient() const = 0;
    virtual bool IsQuadratic() const = 0;
    virtual bool IsNegativeDiscriminant() const = 0;
    virtual bool IsDownwardParabola() const = 0;
    virtual bool IsPerfectSquare() const = 0;
    virtual bool IsLinear() const = 0;
    virtual int GetB() const = 0;
    virtual int GetC() const = 0;
    virtual int GetA() const = 0;
    virtual ~Equation() = default;
};

class LinearEquation : public Equation {
private:
    int a;
    int b;
public:
    LinearEquation(const int& a = 1, const int& b = 0);
    LinearEquation(const LinearEquation& other);
    void Print() const override;
    void Solve() override;
    bool HasNoSolution() const override;
    bool HasInfiniteSolutions() const override;
    int GetLeadingCoefficient() const override;
    bool IsQuadratic() const override;
    bool IsNegativeDiscriminant() const override;
    bool IsDownwardParabola() const override;
    bool IsPerfectSquare() const override;
    bool IsLinear() const override;
    int GetB() const override;
    int GetC() const override;
    int GetA() const override;
};

class QuadraticEquation : public Equation {
    int a, b, c;
public:
    QuadraticEquation(int a = 1, int b = 0, int c = 0);
    QuadraticEquation(const QuadraticEquation& other);
    void Print() const override;
    void Solve() override;
    bool HasNoSolution() const override;
    bool HasInfiniteSolutions() const override;
    int GetLeadingCoefficient() const override;
    bool IsQuadratic() const override;
    bool IsNegativeDiscriminant() const override;
    bool IsDownwardParabola() const override;
    bool IsPerfectSquare() const override;
    bool IsLinear() const override;
    int GetB() const override;
    int GetC() const override;
    int GetA() const override;
};

#endif EQUATIONS_H
