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
    string st1 = "   -00000042";
    string st2 = "1337c0d3";
    cout<< myAtoi(st2);
   return 0;
}