#include "MixedFraction.h"

// Default constructor
MixedFraction::MixedFraction() : Fraction(), whole(0) {}

// Parameterized constructor
MixedFraction::MixedFraction(int w, int n, int d) : Fraction(n, d), whole(w) {
    // Normalize in case the fraction part is improper
    if (getNumerator() >= getDenominator()) {
        whole += getNumerator() / getDenominator();
        setNumerator(getNumerator() % getDenominator());
    }
}

// Constructor that converts a Fraction to MixedFraction
MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    whole = fraction.getNumerator() / fraction.getDenominator();
    setNumerator(fraction.getNumerator() % fraction.getDenominator());
}

// Overloaded << operator to print in mixed fraction format
std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    if (mf.whole != 0) {
        if (mf.getNumerator() != 0) {
            os << mf.whole << " " << mf.getNumerator() << "/" << mf.getDenominator();
        } else {
            os << mf.whole;
        }
    } else {
        os << mf.getNumerator() << "/" << mf.getDenominator();
    }
    return os;
}
