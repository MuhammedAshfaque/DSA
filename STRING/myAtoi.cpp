#include<bits/stdc++.h>
using namespace std;

bool isDigit(char c){
    if(c < '0' || c > '9') return false;
    return true;
}

int myAtoi(string s){
    int i = 0, n = s.length();
    // "1337c0d3"
    while(s[i] == ' '){
        i++;
    }
    int sign = +1;
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    while(s[i] == '0'){
        i++;
    }
    int number = 0;
    while(i < n && isDigit(s[i])){
        number = number * 10 + (s[i] - '0');
        i++;
    }
    return sign * number;
}

int main(){
    // string st1 = "   -00000042";
    // string st2 = "1337c0d3";
    // cout<< myAtoi(st2);


    
    // string str = to_string(num);
    int num = stoi("1337"); //stoi is a built in function in c++ which is used to convert a string to an integer. It takes a string as input and returns the integer value of the string. If the string is not a valid integer, it throws an exception. If the string is a valid integer but is out of the range of int, it throws an exception.

    cout<< num;
   return 0;
}