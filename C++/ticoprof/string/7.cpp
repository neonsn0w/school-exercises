#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    for(int i=0; i<s.length()/2; i++) {
        if(!(s[i]==s[s.length()-i-1])){
            return false;
        }
    }
    return true;
}

int main() {
    string s;

    getline(cin, s);

    if(isPalindrome(s)) {
        cout << "The string is palindrome";
    } else {
        cout << "The string isn't palindrome";
    }
}