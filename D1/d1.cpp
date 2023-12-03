#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::string replaceStringNumbers(const std::string& input) {
    std::unordered_map<std::string, std::string> numberMap;
    numberMap["one"] = "1";
    numberMap["two"] = "2";
    numberMap["three"] = "3";
    numberMap["four"] = "4";
    numberMap["five"] = "5";
    numberMap["six"] = "6";
    numberMap["seven"] = "7";
    numberMap["eight"] = "8";
    numberMap["nine"] = "9";
    std::string result;
    size_t currentPosition = 0;
    while (currentPosition < input.length()) {
        bool replaced = false;
        for (const auto& entry : numberMap) {
            const std::string& stringNumber = entry.first;
            const std::string& numericValue = entry.second;

            if (input.compare(currentPosition, stringNumber.length(), stringNumber) == 0) {
                result += numericValue;
                currentPosition += stringNumber.length();
                replaced = true;
                break;
            }
        }

        if (!replaced) {
            result += input[currentPosition];
            currentPosition++;
        }
    }

    return result;
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
            
            line = replaceStringNumbers(line);
            std::cout << line << std::endl;
            std::string firstNumber = "";
            char secondNumber = '\0';
            bool first = false;

            for (size_t i = 0; i < line.length(); i++)
            {

                if (isdigit(line[i]))
                {
                    if (!first)
                    {
                        firstNumber += line[i];
                        first = true;
                    }
                    else
                        secondNumber = line[i];
                }
            }
            if (secondNumber == '\0')
                firstNumber += firstNumber[0];

            else
                firstNumber += secondNumber;

            res += std::stoi(firstNumber);
            std::cout << res << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    return 0;
}
