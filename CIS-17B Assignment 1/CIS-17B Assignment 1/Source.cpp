//Calvin Vo
//CIS-17B
//Assignment 1 Simple Banking System

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class BankAccount
{
private:
    //Private members for BankAccount
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    //Public members for BankAccount
    BankAccount(string name, int accountNum, double startBalance = 0)
    {
        accountNumber = accountNum;
        accountHolderName = name;
        if (startBalance >= 0)
        {
            balance = startBalance;
        }
        else {
            balance = 0;
        }
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            throw invalid_argument("Desposit must be positive");
        }
    }
    void withdraw(double amount)
    {
        if (amount > 0)
        {
            balance -= amount;
        }
        else if (amount > balance)
        {
            throw runtime_error("Insufficient Funds");
        }
        else
        {
            throw invalid_argument("Withdrawl must be positive");
        }
    }
    double getBalance() const
    {
        return balance;
    }
};
//Checks to make sure if the input entered is invalid.
void invalidInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid. Enter a valid number between 1 and 5." << endl;
}

int main()
{
    //Pointer for user
    BankAccount* user = nullptr;
    int choice;
    double amount;

    do
    {
        //Greets users and opens up a menu
        cout << "Welcome to Simple Bank System by Calvin Vo" << endl;
        cout << "1. Create account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdrawl money" << endl;
        cout << "4. Check balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        //Checks if valid is invalid
        if (cin.fail())
        {
            invalidInput();
        }
        //If not invalid, switch statement triggers to perform operations based on what user entered.
        switch (choice)
        {
        case 1:
        {
            string name;
            int accountNum;
            double startDeposit;

            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter account number: ";
            cin >> accountNum;

            if (cin.fail())
            {
                invalidInput();
                break;
            }

            cout << "Enter initial deposit: ";
            cin >> startDeposit;

            if (cin.fail() || startDeposit < 0)
            {
                invalidInput();
                break;
            }

            user = new BankAccount(name, accountNum, startDeposit);
            cout << "Account created!" << endl;
            break;
        }

        case 2:
            if (!user)
            {
                cout << "No account has been identified. Please create an account" << endl;
                break;
            }

            cout << "Enter deposit amount: ";
            cin >> amount;

            if (cin.fail() || amount <= 0)
            {
                invalidInput();
                break;
            }

            user->deposit(amount); 
            cout << "Deposit successful!" << endl;
            break;

        case 3: 
            if (!user)
            {
                cout << "No account identified! Please create an account." << endl;
                break;
            }
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (cin.fail() || amount <= 0) 
            {
                invalidInput();
                break;
            }

            user->withdraw(amount);
            cout << "Withdrawl successful!" << endl;
            break;

        case 4:
            if (!user)
            {
                cout << "No account found! Please create an account first." << endl;
                break;
            }
            cout << "Current balance: " << user->getBalance() << endl;
            break;

        case 5:
            cout << "Thank you for using our service! Terminating program." << endl;
            break;

        default:
            cout << "Invalid. Please enter a number from 1-5." << endl;
        }

    } while (choice != 5);

    if (user)
    {
        delete user;
    }

    return 0;
}