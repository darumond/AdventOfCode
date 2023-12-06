#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <map>

bool isValidIndex(int i, int j, int colLength, int rowLength)
{
    return i >= 0 && i < rowLength && j >= 0 && j < colLength;
}

int retrieveNumber(const std::vector<std::vector<char>> &matrix, int i, int j)
{
    std::string res = "";

    while (j > 0 && isdigit(matrix[i][j - 1]))
    {
        j--;
    }

    int colLength = matrix[i].size();

    while (j < colLength && isdigit(matrix[i][j]))
    {
        res += matrix[i][j];
        j++;
    }

    return std::stoi(res);
}

int isNumbers(const std::vector<std::vector<char>> &matrix, int i, int j, int colLength, int rowLength)
{
    int found = 0;
    int firstNumber = 0;
    int res = 0;
    std::vector<int> arr;

    if (isValidIndex(i + 1, j, colLength, rowLength) && isdigit(matrix[i + 1][j]))
    {
        int number = retrieveNumber(matrix, i + 1, j);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i - 1, j, colLength, rowLength) && isdigit(matrix[i - 1][j]))
    {
        int number = retrieveNumber(matrix, i - 1, j);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i, j + 1, colLength, rowLength) && isdigit(matrix[i][j + 1]))
    {
        int number = retrieveNumber(matrix, i, j + 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i, j - 1, colLength, rowLength) && isdigit(matrix[i][j - 1]))
    {
        int number = retrieveNumber(matrix, i, j - 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i + 1, j + 1, colLength, rowLength) && isdigit(matrix[i + 1][j + 1]))
    {
        int number = retrieveNumber(matrix, i + 1, j + 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i - 1, j - 1, colLength, rowLength) && isdigit(matrix[i - 1][j - 1]))
    {
        int number = retrieveNumber(matrix, i - 1, j - 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i - 1, j + 1, colLength, rowLength) && isdigit(matrix[i - 1][j + 1]))
    {
        int number = retrieveNumber(matrix, i - 1, j + 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (isValidIndex(i + 1, j - 1, colLength, rowLength) && isdigit(matrix[i + 1][j - 1]))
    {
        int number = retrieveNumber(matrix, i + 1, j - 1);
        if (std::find(arr.begin(), arr.end(), number) == arr.end())
        {
            arr.push_back(number);
        }
    }

    if (arr.size() == 2)
    {
        return arr[0] * arr[1];
    }
    return 0;
}

int isGear(std::vector<std::vector<char>> matrix, int i, int j)
{
    int colLength = matrix[i].size();
    int rowLength = matrix.size();

    return isNumbers(matrix, i, j, colLength, rowLength);
}
int sumPartNumbers(std::vector<std::vector<char>> matrix)
{
    int res = 0;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == '*')
            {
                res += isGear(matrix, i, j);
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
