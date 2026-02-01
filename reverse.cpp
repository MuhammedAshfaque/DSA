// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include<bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int reverse = 0;
    int lastDigit = 0;
    while (x != 0)
    {
        lastDigit = x % 10;
        if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && lastDigit > 7))
        {
            return 0;
        }

        if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && lastDigit < -8))
        {
            return 0;
        }
        reverse = (reverse * 10) + lastDigit;
        x = x / 10;
    }
    return reverse;
}

int main(){
    reverse(-123);
   return 0;
}
