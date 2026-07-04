#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    // Display account details
    void display() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    int accNo;
    string name;
    double initialBalance;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount account(accNo, name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- Bank Menu ---" << endl;
        cout << "1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}


