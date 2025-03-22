#include "Fraction.h"

// Helper function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Simplifies the fraction
void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    int divisor = gcd(abs(num), abs(den));
    num /= divisor;
    den /= divisor;

    // Ensure denominator is always positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// Default constructor (0/1)
Fraction::Fraction() : num(0), den(1) {}

// Parameterized constructor
Fraction::Fraction(int n, int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    num = n;
    den = d;
    simplify();
}

// Getter methods
int Fraction::getNumerator() const { return num; }
int Fraction::getDenominator() const { return den; }

// Setter methods
void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

// Overloaded arithmetic operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den - rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Division by zero");
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

// Overload << operator for output
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.num << "/" << fraction.den;
    return os;
}
