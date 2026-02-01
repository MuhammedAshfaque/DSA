#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "A man, a plan, a canal: Panama";
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    string result = "";
    for (char c : s) {
        if (isalpha(c))   // keep only alphabets
            result += c;
    }
    cout<< result;
   return 0;
}