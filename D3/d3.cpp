#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <map>

bool isValidIndex(int i, int j, int colLength, int rowLength)
{
    return i < rowLength && j < colLength && i >= 0 && j >= 0;
}
bool isSymbol(std::vector<std::vector<char>> matrix, int i, int j, int colLength, int rowLength)
{
    return (isValidIndex(i + 1, j, colLength, rowLength) && matrix[i + 1][j] != '.' && !isdigit(matrix[i + 1][j])) || (isValidIndex(i - 1, j, colLength, rowLength) && matrix[i - 1][j] != '.' && !isdigit(matrix[i - 1][j])) || (isValidIndex(i, j + 1, colLength, rowLength) && matrix[i][j + 1] != '.' && !isdigit(matrix[i][j + 1])) || (isValidIndex(i, j - 1, colLength, rowLength) && matrix[i][j - 1] != '.' && !isdigit(matrix[i][j - 1])) || (isValidIndex(i + 1, j + 1, colLength, rowLength) && matrix[i + 1][j + 1] != '.' && !isdigit(matrix[i + 1][j + 1])) || (isValidIndex(i - 1, j - 1, colLength, rowLength) && matrix[i - 1][j - 1] != '.' && !isdigit(matrix[i - 1][j - 1])) || (isValidIndex(i - 1, j + 1, colLength, rowLength) && matrix[i - 1][j + 1] != '.' && !isdigit(matrix[i - 1][j + 1])) || (isValidIndex(i + 1, j - 1, colLength, rowLength) && matrix[i + 1][j - 1] != '.' && !isdigit(matrix[i + 1][j - 1]));
}
int isPartNumbers(std::vector<std::vector<char>> matrix, int i, int j)
{
    int colLength = matrix[i].size();
    int rowLength = matrix.size();
    bool partNumber = false;
    std::string numToAdd = "";

    while (isdigit(matrix[i][j]))
    {
        if (isSymbol(matrix, i, j, colLength, rowLength))
        {
            partNumber = true;
        }
        numToAdd += matrix[i][j];
        j++;
    }

    if (partNumber)
    {
        return std::stoi(numToAdd);
    }
    return 0;
}
int sumPartNumbers(std::vector<std::vector<char>> matrix)
{
    int res = 0;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (isdigit(matrix[i][j]))
            {
                res += isPartNumbers(matrix, i, j);
            }
            while (isdigit(matrix[i][j]))
            {
                j++;
            }
        }
    }

    return res;
}

int main()
{
    std::ifstream inputFile("puzzle.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> matrix;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }

    inputFile.close();
    int res = sumPartNumbers(matrix);

    std::cout << res << std::endl;

    return 0;
}
