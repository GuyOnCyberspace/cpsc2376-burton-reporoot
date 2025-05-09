Board Game Café Lending System – Design Document

1. Program Specification (Rephrased)

This program is a lightweight board game lending system designed for a local board game café. It tracks the café's collection of board games, their availability, and who has currently borrowed which games. The system allows staff to view the full game inventory, check out games to customers, and mark them as returned. Each game may have multiple copies, and the system must ensure games are only lent out if copies are available.

The key entities include the games, customers, and transactions (checkouts and returns). The system will record customer information and manage lending dates to facilitate proper return tracking.


2. Nouns and Verbs

Nouns (Potential Classes or Attributes)
- Game
- Customer
- Loan / Transaction
- Inventory
- Copy
- Due Date

 Verbs (Potential Methods or Behaviors)
- Add a new game
- View available games
- Check out a game
- Return a game
- List all borrowed games
- Look up who has what
- Track due dates

3. Class Definitions


class Game {
public:
    string title;
    int totalCopies;
    int availableCopies;

    Game(string title, int totalCopies);
    void incrementAvailable();
    void decrementAvailable();
};

class Customer {
public:
    string name;
    int customerID;

    Customer(string name, int id);
};

class Loan {
public:
    Game* game;
    Customer* customer;
    string dueDate;

    Loan(Game* game, Customer* customer, string dueDate);
    void returnGame();
};
