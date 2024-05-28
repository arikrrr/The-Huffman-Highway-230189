#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string date;
    double amount;
    string type;

    Transaction(string d, double a, string t) : date(d), amount(a), type(t) {}
};

class Loan {
public:
    string date;
    double amount;
    double interestRate;
    int duration;

    Loan(string d, double a, double rate, int dur) 
        : date(d), amount(a), interestRate(rate), duration(dur) {}
};

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    string address;
    string accountType;
    double balance;
    vector<Transaction> transactions;
    vector<Loan> loans;

public:
    Account(int accNum, string holderName, string addr, string accType)
        : accountNumber(accNum), accountHolderName(holderName), address(addr), accountType(accType), balance(0) {}

    virtual void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("2024-05-28", amount, "Deposit");
        cout << "Deposited " << amount << ". Current balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
            transactions.emplace_back("2024-05-28", amount, "Withdrawal");
            cout << "Withdrew " << amount << ". Current balance: " << balance << endl;
        }
    }

    void updateAddress(string newAddress) {
        address = newAddress;
        cout << "Address updated to " << newAddress << endl;
    }

    void viewPassbook() {
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transactions) {
            cout << "Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
        }
    }

    void searchTransactions(string date, double amount) {
        cout << "Searching Transaction History:" << endl;
        for (const auto& transaction : transactions) {
            if (transaction.date == date || transaction.amount == amount) {
                cout << "Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
            }
        }
    }

    virtual void takeLoan(double amount, double interestRate, int duration) {
        loans.emplace_back("2024-05-28", amount, interestRate, duration);
        balance += amount;
        cout << "Loan taken: " << amount << " at " << interestRate << "% interest for " << duration << " months." << endl;
    }

    virtual void transferFunds(Account &toAccount, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds to transfer" << endl;
        } else {
            balance -= amount;
            toAccount.balance += amount;
            transactions.emplace_back("2024-05-28", amount, "Transfer");
            toAccount.transactions.emplace_back("2024-05-28", amount, "Received Transfer");
            cout << "Transferred " << amount << " to account " << toAccount.accountNumber << endl;
        }
    }
};

class JointAccount : public Account {
private:
    string jointHolderName;

public:
    JointAccount(int accNum, string holderName, string addr, string accType, string jointHolder)
        : Account(accNum, holderName, addr, accType), jointHolderName(jointHolder) {}

    void viewJointAccountInfo() {
        cout << "Primary Holder: " << accountHolderName << " and Joint Holder: " << jointHolderName << endl;
    }
};