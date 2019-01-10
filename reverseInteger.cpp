#include <iostream>

using namespace std;

/*
reverse digits of an integer

Examples:

Input: 123
Output: 321

Input: -123
Output: -321

Input: 120
Output: 21

*/

int reverse(int x)
{

    long long res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

int main()
{
    int inputInt;
    cout << "Enter a string of numbers from 2-9: ";
    cin >> inputInt;
    cout << reverse(inputInt) << endl;
    return 0;
}