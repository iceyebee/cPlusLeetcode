#include <iostream>

using namespace std;

/*
count-and-say sequence:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

*/

string countAndSay(string str)
{
    int letterIndex = 0;
    int numCount[10] = {0};
    while (letterIndex < str.length())
    {
        switch (str[letterIndex])
        {
        case '0':
            numCount[0]++;
            break;
        case '1':
            numCount[1]++;
            break;
        case '2':
            numCount[2]++;
            break;
        case '3':
            numCount[3]++;
            break;
        case '4':
            numCount[4]++;
            break;
        case '5':
            numCount[5]++;
            break;
        case '6':
            numCount[6]++;
            break;
        case '7':
            numCount[7]++;
            break;
        case '8':
            numCount[8]++;
            break;
        case '9':
            numCount[9]++;
            break;
        }
        letterIndex++;
    }

    int uniqueCount = 0;
    string ans;
    for (int i = 0; i < 10; i++)
    {
        if (numCount[i] > 0)
            ans += to_string(numCount[i]) + to_string(i);
    }

    return ans;
}

int main()
{
    string inputStr;
    cout << "Enter a string of numbers from 0-9: ";
    getline(cin, inputStr);
    cout << countAndSay(inputStr) << endl;
    return 0;
}