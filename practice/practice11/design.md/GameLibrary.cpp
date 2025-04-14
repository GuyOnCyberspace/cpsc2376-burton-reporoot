class GameLibrary {
private:
    std::vector<Game> games;
    std::vector<Loan> activeLoans;

public:
    void addGame(const std::string& title, int copies);
    void listGames() const;
    void checkoutGame(const std::string& gameTitle, const std::string& customerName, const std::string& dueDate);
    void returnGame(const std::string& gameTitle, const std::string& customerName);
    void listLoans() const;
};
