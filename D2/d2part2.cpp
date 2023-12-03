#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <map>
int minValues(const std::string &input)
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
    int maxRed = 0;
    int maxBlue = 0;
    int maxGreen = 0;
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
        if (colorCounts["blue"] > maxBlue)
            maxBlue = colorCounts["blue"];

        if (colorCounts["green"] > maxGreen)
            maxGreen = colorCounts["green"];

        if (colorCounts["red"] > maxRed)
            maxRed = colorCounts["red"];
        
        colorCounts["blue"] = 0;
        colorCounts["red"] = 0;
        colorCounts["green"] = 0;

    }
    // std::cout << "Blue: " << colorCounts["blue"] << std::endl;
    // std::cout << "Red: " << colorCounts["red"] << std::endl;
    // std::cout << "Green: " << colorCounts["green"] << std::endl;

    // std::cout << "maxBlue: " << maxBlue << std::endl;
    // std::cout << "maxRed: " << maxRed << std::endl;
    // std::cout << "maxGreen: " << maxGreen << std::endl;

    int res  = maxBlue * maxRed * maxGreen;
    std::cout << res << std::endl;
    return res;
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
            res += minValues(line);
        }
        std::cout << "Total: " << res << std::endl;
        file.close();
    }
    return 0;
}