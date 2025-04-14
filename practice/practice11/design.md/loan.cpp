class Loan {
private:
    Game* game;
    Customer* customer;
    std::string dueDate;

public:
    Loan(Game* game, Customer* customer, const std::string& dueDate);
    Game* getGame() const;
    Customer* getCustomer() const;
    std::string getDueDate() const;
};
