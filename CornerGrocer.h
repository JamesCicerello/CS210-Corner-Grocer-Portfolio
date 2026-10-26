#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H

#include <map>
#include <string>

class CornerGrocer {
public:
    bool LoadPurchaseData(const std::string& inputFileName);
    bool WriteBackupFile(const std::string& outputFileName) const;
    int GetItemFrequency(const std::string& itemName) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;

private:
    std::map<std::string, int> itemFrequencies;

    static std::string NormalizeItemName(const std::string& itemName);
};

#endif
