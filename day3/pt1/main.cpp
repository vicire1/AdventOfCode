#include <iostream>
#include <fstream>
#include <string>

int checkParam(std::string occur)
{
    int i(0), j(0), a, b;
    for (; isdigit(occur[i]) && i < 3; i++) {}
    if (i == 0 || occur[i] != ',')
        return 0;
    else {
        a = atoi(occur.substr(0, i).c_str());
        i++;
    }
    for (; isdigit(occur[i + j]) && j < 3; j++) {}
    if (j == 0 || occur[i + j] != ')')
        return 0;
    else
        b = atoi(occur.substr(i, j).c_str());
    return (a * b);
}

int findMul(std::string line)
{
    int pos(-4);
    int res(0);
    while (pos != std::string::npos) {
        pos = line.find("mul(", pos + 4);
        res += checkParam(&line[pos + 4]);
    }
    return res;
}

int main()
{
    std::string         line;
    std::ifstream       input("../input.txt");
    int res(0);

    if (!input) {
        std::cout << "Could not open input file." << std::endl;
        return 1;
    }
    while (getline(input, line)) {
        res += findMul(line);
    }
    input.close();
    std::cout << res << std::endl;
    return 0;
}