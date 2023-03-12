// task 12.7.1 20230312.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

bool IsKPeriodic(const std::string& text, const int k)
{
    if (k <= 0 || text.empty() || (text.size() % k)) return false;
    std::string subtext{ text.substr(0, k) };
    for (auto i = 0; i < ( (text.size() - k) / k); ++i)
    {
        std::string subtext2{ text.substr(k * i + k, k) };
        if (subtext != subtext2) return false;
    }
    return true;    
}

bool IsKPeriodicAlternative(char* text, const int size, const int k)
{
    if (k <= 0 || size <= 0 || (size % k)) return false;
    for (auto i = 0; i < k; ++i)
    {
        for (auto j = 0; i < (size / k - 1); ++i)
        {
            if (text[i] != text[j * k + k + i]) return false;
        }
    }
    return true;
}

int main()
{
    std::string text{ "abcabcabcabc" };
    std::cout << std::boolalpha << IsKPeriodic(text, 3) << '\n';

    char testArray[255]{};
    strcpy_s(testArray, text.c_str());
    std::cout << std::boolalpha << IsKPeriodicAlternative(testArray, text.size(), 3) << '\n';
}