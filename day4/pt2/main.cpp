#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int findXmas(std::vector<std::vector<char>> matrice, int i, int j)
{
    int occur(0); 
    if (j - 1 >= 0 && j + 1 < matrice[i].size() && i - 1 >= 0 && i + 1 < matrice.size()) {
        if (matrice[i - 1][j - 1] == 'M' && matrice[i + 1][j + 1] == 'S') {
            if ((matrice[i - 1][j + 1] == 'M' && matrice[i + 1][j - 1] == 'S') || (matrice[i + 1][j - 1] == 'M' && matrice[i - 1][j + 1] == 'S'))
                occur++;
        }
        if (matrice[i - 1][j - 1] == 'S' && matrice[i + 1][j + 1] == 'M') {
            if ((matrice[i - 1][j + 1] == 'M' && matrice[i + 1][j - 1] == 'S') || (matrice[i + 1][j - 1] == 'M' && matrice[i - 1][j + 1] == 'S'))
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
            if (matrice[i][j] == 'A')
                occur += findXmas(matrice, i, j);
        }
    }
    std::cout << occur << std::endl;
    return 0;
}