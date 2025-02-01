// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;  // Map to store item counts
    string inputFile = "C:\\CS 210\\Project_Three_Input_File.txt";
    string backupFile = "frequency.dat";

    // Reads the input file and populates the map
    void LoadItems() {
        ifstream inFile(inputFile);
        string item;

        if (!inFile) {
            cout << "Error: Unable to open input file." << endl;
            return;
        }

        while (inFile >> item) {
            itemFrequency[item]++;
        }
        inFile.close();
        SaveToFile();  // Backup frequency data
    }

    // Saves the frequency data to a backup file
    void SaveToFile() {
        ofstream outFile(backupFile);
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

public:
    ItemTracker() {
        LoadItems();
    }

    // Searches for an item and prints its frequency
    void SearchItem() {
        string item;
        cout << "Enter item name: ";
        cin >> item;

        if (itemFrequency.find(item) != itemFrequency.end()) {
            cout << item << " was purchased " << itemFrequency[item] << " times." << endl;
        }
        else {
            cout << item << " was not found in the purchase records." << endl;
        }
    }

    // Displays all items and their purchase frequencies
    void DisplayAllItems() {
        cout << "\nItem Purchase Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Prints a histogram representing item frequencies
    void DisplayHistogram() {
        cout << "\nPurchase Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Displays the menu and handles user input
    void RunMenu() {
        int choice;
        do {
            cout << "\n=== Corner Grocer Item Tracking ===\n";
            cout << "1. Search for an item\n";
            cout << "2. Display all item frequencies\n";
            cout << "3. Display purchase histogram\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                SearchItem();
                break;
            case 2:
                DisplayAllItems();
                break;
            case 3:
                DisplayHistogram();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ItemTracker tracker;
    tracker.RunMenu();
    return 0;
}
