#include <iostream>

using namespace std;

/*
Given a string, find the length of the longest
substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3

Example 2:
Input: "bbbbb"
Output: 1
"b"

Example 3:
Input: "pwwkew"
Output: 3 
"wke"

*/

int calcLongestSubstr(string str)
{
    int i, j = 0;
    int length = str.length();
    int ans = 0;
    int bucket[128];
    for (i = 0; i < 127; i++)
        bucket[i] = -1;
    if (length <= 1)
        return length;

    for (i = 0; i < length; i++)
    {
        if (j < bucket[str[i]] + 1)
            j = bucket[str[i]] + 1;
        bucket[str[i]] = i;

        if (i - j + 1 > ans)
            ans = i - j + 1;
    }

    return ans;
}

int main()
{
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);
    cout << calcLongestSubstr(inputStr) << endl;
    return 0;
}
