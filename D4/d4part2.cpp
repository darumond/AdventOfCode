#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

std::vector<int> vecOcur(219, 1);
int currentIndex = 0;
int countPoints(const std::string &input)
{
    size_t colonPos = input.find(':');
    std::string result;
    if (colonPos != std::string::npos)
    {
        result = input.substr(colonPos + 1);
        size_t firstNonSpace = result.find_first_not_of(" \t\n\r");
        result = result.substr(firstNonSpace);
    }
    std::vector<int> winningCardArr;
    std::vector<int> myCardArr;

    std::istringstream setsStream(result);

    std::string winningCard;
    std::getline(setsStream, winningCard, '|');
    std::string myCard;
    std::getline(setsStream, myCard, '|');

    std::istringstream winningStream(winningCard);
    std::istringstream myCardStream(myCard);

    for (size_t i = 0; i < 10; i++)
    {
        int number;
        winningStream >> number;
        winningCardArr.push_back(number);
    }
    for (size_t i = 0; i < 25; i++)
    {
        int number;
        myCardStream >> number;
        myCardArr.push_back(number);
    }
    int res = 0;
    int numOfCard = 0;
    for (size_t i = 0; i < 25; i++)
    {
        if (std::find(winningCardArr.begin(), winningCardArr.end(), myCardArr[i]) != winningCardArr.end())
        {
            if (res >= 1)
                res *= 2;
            else
                res++;

            numOfCard++;
        }
    }

    for (size_t i = 1; i < numOfCard + 1; i++)
    {
        vecOcur[currentIndex + i] += 1;
    }

    return numOfCard;
}
int main()
{
    int res = 0;
    std::ifstream file("puzzle.txt");
    
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::cout << std::endl;
            for (size_t i = 0; i < vecOcur[currentIndex]; i++)
            {
                int count = countPoints(line);
                // std::cout << count << std::endl;
            }
            currentIndex++;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
    for (size_t i = 0; i < vecOcur.size(); i++)
    {
        res += vecOcur[i];
    }
    std::cout << "final: " << res << std::endl;

    return 0;
}
