#include <iostream>
using namespace std;
//number palindrome
class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) return false; 

        long long reversed = 0;  
        int dup = n;

        while (n > 0) {
            int ld = n % 10;
            reversed = reversed * 10 + ld;
            n /= 10;
        }

        return dup == reversed; 
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}

//string palindrome
bool f(int i,string &s){
    if(i>=s.size()/2) return true;
    if(s[i] != s[s.size() - i-1]) return false;
    return f(i+1,s);
}
int main(){
    string s = "madam";
    cout << f(0,s);
    return 0;
}