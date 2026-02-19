#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

size_t FindMaxConsecutiveSpaces(const string s)
{
    size_t maxSpaces = 0;
    size_t currentSpaces = 0;
    size_t start = 0;
    size_t pos;

    pos = s.find(' ', start);

    while (pos != string::npos)
    {
        size_t end = s.find_first_not_of(' ', pos);

        if (end == string::npos)
            end = s.length();

        currentSpaces = end - pos;

        if (currentSpaces > maxSpaces)
            maxSpaces = currentSpaces;

        pos = s.find(' ', end);
    }

    return maxSpaces;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    size_t result = FindMaxConsecutiveSpaces(str);

    cout << "Maximum number of consecutive spaces: " << result << endl;

    return 0;
}