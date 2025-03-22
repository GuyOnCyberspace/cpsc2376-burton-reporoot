#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole; // Whole number part of the mixed fraction

public:
    // Constructors
    MixedFraction();
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction); // Convert from Fraction

    // Function to convert to string format (e.g., 3 1/2)
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mf);
};

#endif // MIXEDFRACTION_H
