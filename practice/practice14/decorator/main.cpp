#include <iostream>
#include <memory>

// Base Purchase class
class Purchase {
public:
    virtual double getCost() const = 0;
    virtual ~Purchase() = default;
};

// SimplePurchase class with base cost
class SimplePurchase : public Purchase {
private:
    double cost;
public:
    SimplePurchase(double cost) : cost(cost) {}
    double getCost() const override {
        return cost;
    }
};

// Decorator class - Base class for decorators
class PurchaseDecorator : public Purchase {
protected:
    std::shared_ptr<Purchase> purchase;
public:
    PurchaseDecorator(std::shared_ptr<Purchase> purchase) : purchase(purchase) {}
    virtual double getCost() const override {
        return purchase->getCost();
    }
};

// TaxDecorator class - Adds 10% tax
class TaxDecorator : public PurchaseDecorator {
public:
    TaxDecorator(std::shared_ptr<Purchase> purchase) : PurchaseDecorator(purchase) {}
    double getCost() const override {
        return purchase->getCost() * 1.10;  // Add 10% tax
    }
};

// ShippingFeeDecorator class - Adds a flat shipping fee
class ShippingFeeDecorator : public PurchaseDecorator {
private:
    double shippingFee;
public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> purchase, double fee) 
        : PurchaseDecorator(purchase), shippingFee(fee) {}
    double getCost() const override {
        return purchase->getCost() + shippingFee;
    }
};

// DiscountDecorator class - Reduces cost by a percentage
class DiscountDecorator : public PurchaseDecorator {
private:
    double discountPercentage;
public:
    DiscountDecorator(std::shared_ptr<Purchase> purchase, double discount)
        : PurchaseDecorator(purchase), discountPercentage(discount) {}
    double getCost() const override {
        return purchase->getCost() * (1 - discountPercentage / 100);
    }
};

int main() {
    double baseCost = 100.0;
    auto purchase = std::make_shared<SimplePurchase>(baseCost);

    char choice;
    std::cout << "Apply Tax? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<TaxDecorator>(purchase);
    }

    std::cout << "Apply Shipping Fee? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<ShippingFeeDecorator>(purchase, 10.0);
    }

    std::cout << "Apply Discount? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<DiscountDecorator>(purchase, 15.0);
    }

    std::cout << "Final Cost: $" << purchase->getCost() << std::endl;
    return 0;
}
