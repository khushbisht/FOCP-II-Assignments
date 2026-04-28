//5. Problem name: Movie Tickets
#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;

public:
    bool book(int customerID, int movieID)
    {
        // sold out or already booked by this customer
        if (bookings[movieID].size() >= 100 || bookings[movieID].count(customerID))
        {
            return false;
        }
        bookings[movieID].insert(customerID);
        return true;
    }

    bool cancel(int customerID, int movieID)
    {
        if (!bookings[movieID].count(customerID))
        {
            return false;
        }
        bookings[movieID].erase(customerID);
        return true;
    }

    bool isBooked(int customerID, int movieID)
    {
        return bookings[movieID].count(customerID) > 0;
    }

    int availableTicketsCount(int movieID)
    {
        return 100 - (int)bookings[movieID].size();
    }
};

int main()
{
    MovieTicket m;
    int Q;
    cin >> Q;

    while (Q--)
    {
        string queryType;
        cin >> queryType;

        if (queryType == "BOOK")
        {
            int customerID, movieID;
            cin >> customerID >> movieID;
            cout << (m.book(customerID, movieID) ? "true" : "false") << endl;
        }

        else if (queryType == "CANCEL")
        {
            int customerID, movieID;
            cin >> customerID >> movieID;
            cout << (m.cancel(customerID, movieID) ? "true" : "false") << endl;
        }

        else if (queryType == "IS_BOOKED")
        {
            int customerID, movieID;
            cin >> customerID >> movieID;
            cout << (m.isBooked(customerID, movieID) ? "true" : "false") << endl;
        }

        else if (queryType == "AVAILABLE_TICKETS")
        {
            int movieID;
            cin >> movieID;
            cout << m.availableTicketsCount(movieID) << endl;
        }
    }

    return 0;
}