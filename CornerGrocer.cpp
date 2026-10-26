#include "CornerGrocer.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

string CornerGrocer::NormalizeItemName(const string& itemName) {
    string normalizedName = itemName;

    // Remove spaces around the search term so common typing mistakes still work.
    const size_t firstCharacter = normalizedName.find_first_not_of(" \t\r\n");
    if (firstCharacter == string::npos) {
        return "";
    }

    const size_t lastCharacter = normalizedName.find_last_not_of(" \t\r\n");
    normalizedName = normalizedName.substr(firstCharacter, lastCharacter - firstCharacter + 1);

    transform(normalizedName.begin(), normalizedName.end(), normalizedName.begin(),
              [](unsigned char character) { return static_cast<char>(tolower(character)); });
    normalizedName.front() = static_cast<char>(toupper(static_cast<unsigned char>(normalizedName.front())));
    return normalizedName;
}

bool CornerGrocer::LoadPurchaseData(const string& inputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        return false;
    }

    itemFrequencies.clear();
    string itemName;
    while (getline(inputFile, itemName)) {
        const string normalizedName = NormalizeItemName(itemName);
        if (!normalizedName.empty()) {
            ++itemFrequencies[normalizedName];
        }
    }

    return true;
}

bool CornerGrocer::WriteBackupFile(const string& outputFileName) const {
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        return false;
    }

    for (const auto& item : itemFrequencies) {
        outputFile << item.first << ' ' << item.second << '\n';
    }

    return true;
}

int CornerGrocer::GetItemFrequency(const string& itemName) const {
    const string normalizedName = NormalizeItemName(itemName);
    const auto item = itemFrequencies.find(normalizedName);
    return item == itemFrequencies.end() ? 0 : item->second;
}

void CornerGrocer::PrintAllFrequencies() const {
    cout << "\nItem Frequencies\n";
    cout << "----------------\n";
    for (const auto& item : itemFrequencies) {
        cout << left << setw(14) << item.first << item.second << '\n';
    }
}

void CornerGrocer::PrintHistogram() const {
    cout << "\nPurchase Histogram\n";
    cout << "------------------\n";
    for (const auto& item : itemFrequencies) {
        cout << left << setw(14) << item.first << string(item.second, '*') << '\n';
    }
}
