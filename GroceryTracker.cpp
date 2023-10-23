//
// Created by Nathaniel G on 10/09/2023.
//

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Function to load data from a file into the itemFrequency map
void GroceryTracker::loadDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string item;
    while (getline(inputFile, item)) {
        itemFrequency[item]++;
    }
    inputFile.close();
}

// Function to save the frequency data to a backup file named 'frequency.dat'
void GroceryTracker::saveDataToBackup() {
    std::ofstream backupFile("../frequency.dat");
    for (const auto& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << std::endl;
    }
    backupFile.close();
}

// Function to retrieve frequency for a specific item
int GroceryTracker::getFrequencyForItem(const std::string& item) {
    return itemFrequency[formatItem(item)];
}

// Function to display frequencies for all items
void GroceryTracker::displayAllFrequencies() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Function to display a histogram representation of the frequencies
void GroceryTracker::displayHistogram() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

std::string GroceryTracker::formatItem(const std::string &str) const {
    std::string result = str;
    if (!result.empty()) {
        result[0] = std::toupper(result[0]);
        for (size_t i = 1; i < result.length(); ++i) {
            result[i] = std::tolower(result[i]);
        }
    }
    return result;
}
