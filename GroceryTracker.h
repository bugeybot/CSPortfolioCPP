//
// Created by Nathaniel G on 10/09/2023.
//

#ifndef PROJECT3_GROCERYTRACKER_H
#define PROJECT3_GROCERYTRACKER_H


#include <string>
#include <map>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency{};
    std::string formatItem(const std::string& str) const;

public:
    void loadDataFromFile(const std::string& filename);
    void saveDataToBackup();
    int getFrequencyForItem(const std::string& item);
    void displayAllFrequencies();
    void displayHistogram();
};


#endif //PROJECT3_GROCERYTRACKER_H
