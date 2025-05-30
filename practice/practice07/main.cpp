#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2) << calculateSalary() << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
                  << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
                  << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << std::fixed << std::setprecision(2) << baseSalary
                  << ", Sales: $" << salesAmount
                  << ", Commission Rate: " << (commissionRate * 100) << "%"
                  << ", Salary: $" << calculateSalary() << std::endl;
    }
};

int main() {
    std::ifstream file("employees.txt");
    if (!file) {
        std::cerr << "Error: Could not open employees.txt\n";
        return 1;
    }

    std::vector<Employee*> employees;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type, name;
        int id;

        ss >> type >> id >> name;

        if (type == "Salaried") {
            double salary;
            ss >> salary;
            employees.push_back(new SalariedEmployee(name, id, salary));
        } else if (type == "Hourly") {
            double rate;
            int hours;
            ss >> rate >> hours;
            employees.push_back(new HourlyEmployee(name, id, rate, hours));
        } else if (type == "Commission") {
            double base, sales, rate;
            ss >> base >> sales >> rate;
            employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
        } else {
            std::cerr << "Error: Unknown employee type \"" << type << "\"\n";
        }
    }

    file.close();

    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}
