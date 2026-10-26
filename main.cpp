#include "CornerGrocer.h"

#include <iostream>
#include <string>

using namespace std;

namespace {
void DisplayMenu() {
    cout << "\nCorner Grocer Item Tracker\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display purchase histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int ReadMenuChoice() {
    string userInput;
    getline(cin, userInput);

    // Accept only one menu digit to avoid partial conversions such as "2abc".
    if (userInput.size() != 1 || userInput[0] < '1' || userInput[0] > '4') {
        return 0;
    }

    return userInput[0] - '0';
}
}  // namespace

int main(int argc, char* argv[]) {
    const string inputFileName = argc > 1 ? argv[1] : "CS210_Project_Three_Input_File.txt";
    CornerGrocer groceryTracker;

    if (!groceryTracker.LoadPurchaseData(inputFileName)) {
        cerr << "Error: Could not open " << inputFileName << ".\n";
        cerr << "Place the input file in the program folder and try again.\n";
        return 1;
    }

    // Create the required backup before showing the menu.
    if (!groceryTracker.WriteBackupFile("frequency.dat")) {
        cerr << "Error: Could not create frequency.dat.\n";
        return 1;
    }

    bool programIsRunning = true;
    while (programIsRunning) {
        DisplayMenu();
        const int menuChoice = ReadMenuChoice();

        switch (menuChoice) {
            case 1: {
                cout << "Enter an item name: ";
                string itemName;
                getline(cin, itemName);
                if (itemName.find_first_not_of(" \t\r\n") == string::npos) {
                    cout << "Please enter an item name.\n";
                } else {
                    cout << itemName << " was purchased "
                         << groceryTracker.GetItemFrequency(itemName) << " time(s).\n";
                }
                break;
            }
            case 2:
                groceryTracker.PrintAllFrequencies();
                break;
            case 3:
                groceryTracker.PrintHistogram();
                break;
            case 4:
                cout << "Thank you for using the Corner Grocer Item Tracker.\n";
                programIsRunning = false;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
                break;
        }
    }

    return 0;
}
