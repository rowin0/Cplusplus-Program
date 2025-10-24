//Calculator.cpp
//Date 10 / 18 / 2025
//Roxana Windsor


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>
using namespace std;

class grocerySearch {
private:
    map<string, int> itemFrequency;

public:
    // Load data from input file
    void LoadData(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cout << "Error: Input file not found.\n";
            return;
        }

        string item;
        while (inputFile >> item) {
            itemFrequency[item]++;
        }
        inputFile.close();
    }

    // Write frequency data to backup file
    void WriteBackup(const string& outFilename) {
        ofstream outputFile(outFilename);
        for (auto const& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
    }

    // Search for an item?s frequency
    void SearchItem() {
        string searchItem;
        cout << "Enter item to search: ";
        cin >> searchItem;

        if (itemFrequency.find(searchItem) != itemFrequency.end()) {
            cout << searchItem << " was purchased " << itemFrequency[searchItem] << " times.\n";
        }
        else {
            cout << searchItem << " not found.\n";
        }
    }

    // Display all items and their frequencies
    void DisplayAll() {
        cout << "\nItem Frequencies:\n";
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Display histogram
    void DisplayHistogram() {
        cout << "\nPurchase Frequency Histogram:\n";
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    grocerySearch analyzer;
    analyzer.LoadData("CS210_Project_Three_Input_File.txt");
    analyzer.WriteBackup("frequency.dat");

    //display the user menu
    int choice;
    do {
        cout << "1. Search for item frequency\n";
        cout << "2. Display all item frequencies\n";
        cout << "3. Display histogram of item frequencies\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        //loop handles the user?s menu selection 
        cin >> choice;

        //reads the user input choice and checks for valid number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        //calls different functions 
        switch (choice) {
        case 1:
            analyzer.SearchItem();
            break;
        case 2:
            analyzer.DisplayAll();
            break;
        case 3:
            analyzer.DisplayHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}