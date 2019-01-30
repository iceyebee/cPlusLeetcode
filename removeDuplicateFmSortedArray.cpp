#include <iostream>

using namespace std;

/*
Given a sorted array nums (a string of numbers), remove the duplicates in-place 
such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by 
modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],
(string: 112)

Your function should return length = 2

Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],
(string: 0011122334)

Your function should return length = 5, with the first five elements of nums 
being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

*/

int newLength(string str)
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
    for (int i = 0; i < 10; i++)
    {
        if (numCount[i] > 0)
            uniqueCount++;
    }

    return uniqueCount;
}

int main()
{
    string inputStr;
    cout << "Enter a string of numbers from 0-9: ";
    getline(cin, inputStr);
    cout << newLength(inputStr) << endl;
    return 0;
}