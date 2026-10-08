#include <iostream>
#include <vector>
#include <string>
using namespace std;

string intToRoman(int num) {
    vector<int> values = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    vector<string> symbols = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    string result = "";

    for (int i = 0; i < values.size(); i++) {
        while (num >= values[i]) {
            result += symbols[i];
            num -= values[i];
        }
    }

    return result;
}

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    cout << "Roman numeral: " << intToRoman(num) << endl;

    return 0;
}