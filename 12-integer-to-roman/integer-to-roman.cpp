#include <string>
#include <vector>
#include <utility>

class Solution {
public:
    std::string intToRoman(int num) {
        // Predefined list of 13 unique Roman values in descending order
        const std::vector<std::pair<int, std::string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        std::string result = "";

        for (const auto& [value, symbol] : romanMap) {
            if (num == 0) break;
            
            // Append symbol as many times as the value fits into num
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};