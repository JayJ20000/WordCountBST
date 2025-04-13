#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function to remove punctuation and convert to lowercase
string convertWord(string& word) {
    string convert;
    for (int i = 0; i < word.length(); ++i) {
        char c = word[i];
        // Allow alphanumeric characters and apostrophes
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '\'') {
            // Convert uppercase letters to lowercase
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            convert += c;
        }
    }
    return convert;
}

// Function to read words from a file and count their occurrences
void readFile(BST& bst, string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    string word;
    while (file >> word) {
        string converted = convertWord(word);
        if (!converted.empty()) {
            int currentCount = bst.find(converted);
            if (currentCount == -1) {
                bst.set(converted, 1); // Add the word with count 1 if not there
            } else {
                bst.set(converted, currentCount + 1); // Increment count if there
            }
        }
    }

    file.close();
}

int main() {
    BST bst;
    string filename;
    int choice;
    string key;
    int value;

    // Ask the user for the filename
    cout << "Enter filename to load words from: ";
    cin >> filename;
    readFile(bst, filename);

    cout << "Loaded";

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert or update a pair\n";
        cout << "2. Find a key\n";
        cout << "3. Print Tree In-Order\n";
        cout << "4. Delete a Key\n";
        cout << "5. Find minimum Key\n";
        cout << "6. Find maximum Key\n";
        cout << "7. Save to File\n";
        cout << "8. Load from File\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (string): ";
                cin >> key;
                cout << "Enter value (integer): ";
                cin >> value;
                bst.set(key, value);
                cout << "Inserted.\n";
                break;

            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                value = bst.find(key);
                if (value != -1) {
                    cout << "Value for '" << key << "' is " << value << ".\n";
                } else {
                    cout << key << " not found.\n";
                }
                break;

            case 3:
                cout << "In-Order contents:\n";
                bst.print();
                break;

            case 4:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteKey(key);
                break;

            case 5:
                cout << "Minimum key: \n";
                bst.min();
                break;

            case 6:
                cout << "Maximum key: \n";
                bst.max();
                break;

            case 7:
                cout << "Enter filename to save: ";
                cin >> key;
                bst.save_file(key);
                cout << "Tree saved to file '" << key << "'.\n";
                break;

            case 8:
                cout << "Enter filename to load from: ";
                cin >> key;
                readFile(bst, key);
                break;

            case 9:
                cout << "Exit\n";
                break;

            default:
                cout << "Retry choice\n";
                break;
        }
    } while (choice != 9);

    return 0;
}
