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

int findMul(std::string line, bool &disabled)
{
    int pos(0);
    int doPos;
    int dontPos;
    int res(0);
    if (disabled) {
        pos = line.find("do()", pos);
        disabled = false;
    }
    while (pos != std::string::npos) {
        pos = line.find("mul(", pos);
        if (pos != std::string::npos)
            pos += 4;
        doPos = line.rfind("do()", pos);
        dontPos = line.rfind("don't()", pos);
        if (doPos > dontPos || dontPos == std::string::npos)
            res += checkParam(&line[pos]);
    }
    doPos = line.rfind("do()", line.size());
    dontPos = line.rfind("don't()", line.size());
    if (doPos < dontPos)
        disabled = true;
    return res;
}

int main()
{
    std::string         line;
    std::ifstream       input("../input.txt");
    bool                disabled = false;
    int                 res(0);

    if (!input) {
        std::cout << "Could not open input file." << std::endl;
        return 1;
    }
    while (getline(input, line)) {
        res += findMul(line, disabled);
    }
    input.close();
    std::cout << res << std::endl;
    return 0;
}