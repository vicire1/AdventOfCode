#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int findXmas(std::vector<std::vector<char>> matrice, int i, int j)
{
    int occur(0); 
    // i-
    if (i - 3 >= 0 && matrice[i - 1][j] == 'M') {
        if (matrice[i - 2][j] == 'A') {
            if (matrice[i - 3][j] == 'S')
                occur++;
        }
    }
    // i- et j-
    if (i - 3 >= 0 && j - 3 >= 0 && matrice[i - 1][j - 1] == 'M') {
        if (matrice[i - 2][j - 2] == 'A') {
            if (matrice[i - 3][j - 3] == 'S')
                occur++;
        }
    }
    // i- et j+
    if (i - 3 >= 0 && j + 3 < matrice[i - 3].size() && matrice[i - 1][j + 1] == 'M') {
        if (matrice[i - 2][j + 2] == 'A') {
            if (matrice[i - 3][j + 3] == 'S')
                occur++;
        }
    }
    // j+
    if (j + 3 < matrice[i].size() && matrice[i][j + 1] == 'M') {
        if (matrice[i][j + 2] == 'A') {
            if (matrice[i][j + 3] == 'S')
                occur++;
        }
    }
    // j+ et i+
    if (j + 3 < matrice[i].size() && i + 3 < matrice.size() && matrice[i + 1][j + 1] == 'M') {
        if (matrice[i + 2][j + 2] == 'A') {
            if (matrice[i + 3][j + 3] == 'S')
                occur++;
        }
    }
    // j-
    if (j - 3 >= 0 && matrice[i][j - 1] == 'M') {
        if (matrice[i][j - 2] == 'A') {
            if (matrice[i][j - 3] == 'S')
                occur++;
        }
    }
    // i+ et j-
    if (i + 3 < matrice.size() && j - 3 >= 0 && matrice[i + 1][j - 1] == 'M') {
        if (matrice[i + 2][j - 2] == 'A') {
            if (matrice[i + 3][j - 3] == 'S')
                occur++;
        }
    }
    // i+
    if (i + 3 < matrice.size() && matrice[i + 1][j] == 'M') {
        if (matrice[i + 2][j] == 'A') {
            if (matrice[i + 3][j] == 'S')
                occur++;
        }
    }
    return occur;
}

int main()
{
    std::string         line;
    std::ifstream       input("../input.txt");
    std::vector<std::vector<char>> matrice;
    int occur(0);

    if (!input) {
        std::cout << "Could not open input file." << std::endl;
        return 1;
    }
    while (getline(input, line)) {
        std::vector<char> v;
        for (int i(0); line[i]; i++) {
            v.push_back(line[i]);
        }
        matrice.push_back(v);
    }
    input.close();
    for (int i(0); i < matrice.size(); i++) {
        for(int j(0); j < matrice[i].size(); j++) {
            if (matrice[i][j] == 'X')
                occur += findXmas(matrice, i, j);
        }
    }
    std::cout << occur << std::endl;
    return 0;
}