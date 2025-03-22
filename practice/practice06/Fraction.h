#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int num;
    int den;

    void simplify(); // Helper function to simplify fraction

public:
    // Constructors
    Fraction();
    Fraction(int n, int d);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Setters
    void setNumerator(int n);
    void setDenominator(int d);

    // Friend Functions for Operator Overloading
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};

#endif // FRACTION_H
