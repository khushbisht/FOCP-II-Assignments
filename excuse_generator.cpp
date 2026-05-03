/*
    ================================
     Student Excuse Generator
    ================================
    - Takes student name as input
    - Stores 10 excuse templates with {name} placeholder
    - Randomly selects a different excuse each run
    - Replaces {name} with actual student name
    - Handles empty name input gracefully
*/

#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time() — makes random truly random each run

using namespace std;

int main() {

    // Seed random number with current time so excuse changes every run
    srand(time(0));

    // ---- 10 Excuse Templates with {name} placeholder ----
    string excuses[10] = {
        "{name} couldn't complete the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to submit the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} had the homework ready, but the printer ran out of ink at exactly 11:58 PM.",
        "{name} was writing the last answer when the electricity went out for three hours.",
        "{name} completed the assignment, but the file got corrupted after a Windows update.",
        "{name} was ready to submit when the school portal kept showing 'Error 404' all night.",
        "{name} tried to email the assignment but the attachment kept failing to upload.",
        "{name} finished the homework but the notebook was accidentally left on the school bus.",
        "{name} was solving the last question when the laptop battery died and the charger stopped working."
    };

    string studentName;

    // ---- Keep asking until a valid name is entered ----
    while (true) {
        cout << "Enter your name: ";
        getline(cin, studentName);  // getline so full name with spaces works

        // Check if name is empty or only spaces
        bool isEmpty = true;
        for (int i = 0; i < studentName.length(); i++) {
            if (studentName[i] != ' ') {
                isEmpty = false;
                break;
            }
        }

        if (!isEmpty) break;  // valid name, move forward

        cout << "Name cannot be empty! Please try again.\n";
    }

    // ---- Pick a random excuse (index 0 to 9) ----
    int index = rand() % 10;
    string excuse = excuses[index];

    // ---- Replace {name} placeholder with actual student name ----
    // find() gives the position of "{name}" in the string
    // replace() removes those 6 characters and puts the real name
    int pos = excuse.find("{name}");
    if (pos != string::npos) {
        excuse.replace(pos, 6, studentName);  // 6 = length of "{name}"
    }

    // ---- Display the final excuse ----
    cout << "\n-----------------------------------------" << endl;
    cout << "  EXCUSE GENERATED SUCCESSFULLY" << endl;
    cout << "-----------------------------------------" << endl;
    cout << excuse << endl;
    cout << "-----------------------------------------" << endl;

    return 0;
}
