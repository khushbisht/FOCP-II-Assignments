//4. Problem name: Bank Balance
#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<int, int> accounts;

public:
    bool create(int userID, int initialBalance)
    {
        if (accounts.count(userID))
        {
            accounts[userID] += initialBalance;
            return false;
        }
        accounts[userID] = initialBalance;
        return true;
    }

    bool debit(int userID, int amount)
    {
        if (!accounts.count(userID) || accounts[userID] < amount)
        {
            return false;
        }
        accounts[userID] -= amount;
        return true;
    }

    bool credit(int userID, int amount)
    {
        if (!accounts.count(userID))
        {
            return false;
        }
        accounts[userID] += amount;
        return true;
    }

    int balance(int userID)
    {
        if (!accounts.count(userID))
        {
            return -1;
        }
        return accounts[userID];
    }
};

int main()
{
    Bank bank;
    int Q;
    cin >> Q;

    while (Q--)
    {
        string queryType;
        cin >> queryType;

        if (queryType == "CREATE")
        {
            int userID, initialBalance;
            cin >> userID >> initialBalance;
            cout << (bank.create(userID, initialBalance) ? "true" : "false") << endl;
        }

        else if (queryType == "DEBIT")
        {
            int userID, amount;
            cin >> userID >> amount;
            cout << (bank.debit(userID, amount) ? "true" : "false") << endl;
        }

        else if (queryType == "CREDIT")
        {
            int userID, amount;
            cin >> userID >> amount;
            cout << (bank.credit(userID, amount) ? "true" : "false") << endl;
        }

        else if (queryType == "BALANCE")
        {
            int userID;
            cin >> userID;
            cout << bank.balance(userID) << endl;
        }
    }

    return 0;
}