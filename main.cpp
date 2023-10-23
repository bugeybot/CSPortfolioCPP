//
// Created by Nathaniel G on 10/09/2023.
//

#include <iostream>
#include <limits>  // For std::cin.ignore() and std::numeric_limits
#include "GroceryTracker.h"  // Include the header file, not the implementation

int main() {
    // Create a GroceryTracker object
    GroceryTracker tracker;

    // Load data from the provided file and save initial backup
    tracker.loadDataFromFile("../CS210_Project_Three_Input_File.txt");
    tracker.saveDataToBackup();

    // Main menu loop
    while (true) {
        // Display menu options to the user
        std::cout << "\nMENU OPTIONS:" << std::endl;
        std::cout << "1. Search for an item's frequency." << std::endl;
        std::cout << "2. Display frequencies of all items." << std::endl;
        std::cout << "3. Display histogram." << std::endl;
        std::cout << "4. Exit." << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        // Clear the input buffer and handle non-integer input
        if(std::cin.fail()) {
            std::cin.clear();
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            continue;
        }

        std::cout << std::endl;
        std::string item;
        switch (choice) {
            case 1:
                std::cout << "Enter the item name: ";
                std::cin.ignore();  // Clear the newline left in the buffer
                std::getline(std::cin, item);  // Use getline to handle item names with spaces
                std::cout << std::endl << "Total Purchased: " << tracker.getFrequencyForItem(item) << std::endl;
                break;
            case 2:
                tracker.displayAllFrequencies();
                break;
            case 3:
                tracker.displayHistogram();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
}
