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
    sort(vectL.begin(), vectL.end());
    sort(vectR.begin(), vectR.end());
    int res(0);
    for (int pos(0); pos < vectL.size(); pos++) {
        res += abs(vectL[pos] - vectR[pos]);
    }
    std::cout << res << std::endl;
    return 0;
}
