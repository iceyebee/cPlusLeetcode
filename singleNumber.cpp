#include <iostream>

using namespace std;

/*
Given an array of integers, every element appears twice except for one. 
Find that single one.

*/

int singleNumber(string str)
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

    int singleCount = 0;
    int errorNum = 0;
    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        if (numCount[i] > 2)
            errorNum = 12;

        if (numCount[i] == 1)
        {
            singleCount++;
            answer = i;
        }
    }

    if (singleCount > 1 || singleCount == 0)
        errorNum += 11;

    if (errorNum > 10)
        return errorNum;
    else
        return answer;
}

int main()
{
    string inputStr;
    cout << "Enter a string of numbers from 0-9: ";
    getline(cin, inputStr);
    //cout << singleNumber(inputStr) << endl;
    int result = singleNumber(inputStr);
    if (result == 12)
        cout << "Please enter numbers that are paired or unpaired." << endl;
    else if (result == 11)
        cout << "Please enter one and only one unpaired number." << endl;
    else if (result > 20)
        cout << "Please enter only 1 unpaired number and other paired number(s)." << endl;
    else
        cout << result << endl;
    return 0;
}