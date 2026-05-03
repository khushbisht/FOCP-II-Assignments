/*
    ============================
     AI Roast Generator in C++
    ============================
    Features:
    - Takes user name as input
    - Picks a random roast every run (using srand with time)
    - Replaces {name} placeholder with actual name
    - Handles empty name input gracefully
*/

#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time() — seeds the random number

using namespace std;

int main() {

    // Seed random number generator with current time
    // This ensures a different roast every time you run the program
    srand(time(0));

    // ---- 10 Roast Lines with {name} placeholder ----
    string roasts[10] = {
        "{name}, your WiFi password has more personality than you do.",
        "Scientists studied {name} for years and concluded: some bugs just can't be fixed.",
        "{name} tried to enter a spelling bee and got eliminated on their own name.",
        "They say everyone is good at something. {name} is still being studied.",
        "{name}'s birth certificate is basically an apology letter from the hospital.",
        "If brains were petrol, {name} couldn't power a toy car around a Rupee coin.",
        "{name} asked Siri for directions once. Siri said 'find yourself first'.",
        "NASA is studying {name} - turns out there IS a black hole with no mass.",
        "{name}'s search history is so embarrassing, their phone takes therapy sessions.",
        "Even {name}'s shadow tried to walk away once. Can't blame it honestly."
    };

    string userName;

    // ---- Keep asking until user enters a non-empty name ----
    while (true) {
        cout << "\nEnter your name: ";
        getline(cin, userName);  // getline handles names with spaces

        // Check if name is empty or only spaces
        bool isEmpty = true;
        for (int i = 0; i < userName.length(); i++) {
            if (userName[i] != ' ') {
                isEmpty = false;
                break;
            }
        }

        if (!isEmpty) break;  // valid name entered, exit loop

        cout << "Name cannot be empty! Try again.\n";
    }

    // ---- Pick a random roast (0 to 9) ----
    int index = rand() % 10;
    string roast = roasts[index];

    // ---- Replace {name} with actual user name ----
    // find() returns the position of "{name}" in the string
    // replace() removes it and puts the real name there
    int pos = roast.find("{name}");
    if (pos != string::npos) {
        roast.replace(pos, 6, userName);  // 6 = length of "{name}"
    }

    // ---- Print the final roast ----
    cout << "\n=============================\n";
    cout << "   YOUR ROAST IS READY!\n";
    cout << "=============================\n";
    cout << roast << "\n";
    cout << "=============================\n\n";

    return 0;
}
