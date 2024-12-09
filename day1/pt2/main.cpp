#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main()
{
    std::string         line;
    std::vector<int>    vectL, vectR;
    std::ifstream        input("../input.txt");
    if (!input) {
        std::cout << "Could not open input file." << std::endl;
        return 1;
    }

    while (getline(input, line)) {
        vectL.push_back(atoi((line.substr(0, 5)).c_str()));
        vectR.push_back(atoi((line.substr(8)).c_str()));
    }
    int res(0);
    for (int i(0); i < vectL.size(); i++) {
        int count (0);
        for (int j(0); j < vectR.size(); j++) {
            if (vectL[i] == vectR[j])
                count++;
        }
        res += count * vectL[i];
    }
    std::cout << res << std::endl;
    return 0;
}