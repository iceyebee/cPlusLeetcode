#include <iostream>

using namespace std;

/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons):

1-n/a
2-abc
3-def
4-ghi
5-jkl
6-mno
7-pqrs
8-tuv
9-wxyz

Example 1:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

*/

string findLetterCombo(string str)
{
    int letterIndex = 0;

    /*
    create variables
    count of valid number numCount
    count of combinations rowCount

    put all letter fragments togeter ans
    indicate index of first letter of each fragment firstLetterIndex
    total number of fragement is numCount
    */
    int numCount = 0;
    int rowCount = 1;
    int firstLetterIndex[str.length()];

    string ans;
    firstLetterIndex[0] = 0;
    while (letterIndex < str.length())
    {
        switch (str[letterIndex])
        {
        case '2':
            ans = ans + "abc";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '3':
            ans = ans + "def";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '4':
            ans = ans + "ghi";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '5':
            ans = ans + "jkl";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '6':
            ans = ans + "mno";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '7':
            ans = ans + "pqrs";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 4;
            rowCount = rowCount * 4;
            break;
        case '8':
            ans = ans + "tuv";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 3;
            rowCount = rowCount * 3;
            break;
        case '9':
            ans = ans + "wxyz";
            numCount++;
            firstLetterIndex[numCount] = firstLetterIndex[numCount - 1] + 4;
            rowCount = rowCount * 4;
            break;
        }
        letterIndex++;
    }

    /*place a length limit on input*/
    if (numCount > 3)
    {
        cout << "Please enter up to 3 numbers. Thank you for the understanding." << endl;
        return 0;
    }

    string newAns;

    /*a copy of firstLetterIndex is ansArray*/
    int ansArray[sizeof(firstLetterIndex)];
    for (int k = 0; k < sizeof(firstLetterIndex); k++)
        ansArray[k] = firstLetterIndex[k];
    /**/

    /*construct the return string newAns*/
    int j = 0;
    int i;
    int reset = 0;

    while (j < rowCount)
    {
        for (i = 0; i < numCount; i++)
            newAns = newAns + ans[ansArray[i]];
        newAns = newAns + " ";

        if (ansArray[numCount - 1] < (ansArray[numCount] - 1))
        {
            ansArray[numCount - 1]++;
        }
        else
        {
            ansArray[numCount - 1] = firstLetterIndex[numCount - 1];
            if (ansArray[numCount - 2] < (ansArray[numCount - 1] - 1))
            {
                ansArray[numCount - 2]++;
            }
            else
            {
                ansArray[numCount - 2] = firstLetterIndex[numCount - 2];
                if (ansArray[numCount - 3] < (ansArray[numCount - 2] - 1))
                {
                    ansArray[numCount - 3]++;
                }
                else
                {
                    ansArray[numCount - 3] = firstLetterIndex[numCount - 3];
                }
            }
        }

        j++;
    }

    return newAns;
}

int main()
{
    string inputStr;
    cout << "Enter up to 3 numbers from 2-9: ";
    getline(cin, inputStr);
    cout << findLetterCombo(inputStr) << endl;
    return 0;
}
