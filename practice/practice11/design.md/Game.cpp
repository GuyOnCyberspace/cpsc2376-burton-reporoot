class Game {
private:
    std::string title;
    int totalCopies;
    int availableCopies;

public:
    Game(const std::string& title, int copies);
    std::string getTitle() const;
    int getAvailableCopies() const;
    void checkoutCopy();
    void returnCopy();
};
