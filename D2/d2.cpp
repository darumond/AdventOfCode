#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <map>
bool isPossible(const std::string &input)
{
    size_t colonPos = input.find(':');
    std::string result;
    if (colonPos != std::string::npos)
    {
        result = input.substr(colonPos + 1);
        size_t firstNonSpace = result.find_first_not_of(" \t\n\r");
        result = result.substr(firstNonSpace);
    }

    std::unordered_map<std::string, int> colorCounts;
    std::istringstream setsStream(result);
    std::string set;
    while (std::getline(setsStream, set, ';'))
    {
        std::istringstream pairsStream(set);
        std::string pair;
        while (std::getline(pairsStream, pair, ','))
        {
            std::istringstream pairStream(pair);
            int count;
            std::string color;
            pairStream >> count >> color;
            colorCounts[color] += count;
        }
        if (!(colorCounts["blue"] <= 14 && colorCounts["red"] <= 12 && colorCounts["green"] <= 13))
        {
            return false;
        }
        colorCounts["blue"] = 0;
        colorCounts["red"] = 0;
        colorCounts["green"] = 0;
    }
    // std::cout << "Blue: " << colorCounts["blue"] << std::endl;
    // std::cout << "Red: " << colorCounts["red"] << std::endl;
    // std::cout << "Green: " << colorCounts["green"] << std::endl;

   return true;
}

int main()
{
    int id = 1;
    int res = 0;
    std::ifstream file("puzzle.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            if (isPossible(line))
            {
                std::cout << id << std::endl;
                res += id;
            }
            id++;
        }
        std::cout << "Total: " << res << std::endl;
        file.close();
    }
    return 0;
}