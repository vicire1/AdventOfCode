#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void fillVector(std::string line, std::vector<int> &report)
{
    int pos(0);
    int tmp(0);
    while (pos != std::string::npos) {
        pos = line.find(' ', tmp);
        report.push_back(atoi(line.substr(tmp, pos - tmp).c_str()));
        tmp = pos + 1;
    }
}

int isSafe(std::vector<int> &report)
{
    int diff(0);
    int prev_diff(0);
    if (report.size() == 1)
        return 1;
    for (int i(1); i < report.size(); i++) {
        diff += report[i] - report[i - 1];
        if ((diff < 0 && prev_diff > 0) || (diff > 0 && prev_diff < 0) || abs(diff) <= abs(prev_diff) || abs(diff) - abs(prev_diff) > 3)
            return 0;
        prev_diff = diff;
    }
    return 1;
}

int main()
{
    std::string         line;
    std::vector<int>    report;
    std::ifstream       input("../input.txt");

    if (!input) {
        std::cout << "Could not open input file." << std::endl;
        return 1;
    }
    int safeCount(0);
    while (getline(input, line)) {
        fillVector(line, report);
        if (isSafe(report)) {
            safeCount++;
        }
        else {
            for (int i(0); i < report.size(); i++) {
                std::vector<int> copy = report;
                copy.erase(copy.begin() + i);
                if (isSafe(copy)) {
                    safeCount++;
                    break;
                }
            }
        }
        report.clear();
    }
    std::cout << safeCount << std::endl;
    input.close();
    return 0;
}