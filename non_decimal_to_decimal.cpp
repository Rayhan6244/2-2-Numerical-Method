#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string num;
    int base;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter base (2, 8, 10, 16): ";
    cin >> base;

    string intPart = "", fracPart = "";
    int dotPos = num.find('.');

    if (dotPos != string::npos) {
        intPart = num.substr(0, dotPos);   
        fracPart = num.substr(dotPos + 1);
    } else {
        intPart = num;
    }

    double intValue = 0;
    int power = 0;
    for (int i = intPart.length() - 1; i >= 0; i--) {
        char ch = toupper(intPart[i]); 
        int digit;
        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else
            digit = ch - 'A' + 10;

        intValue += digit * pow(base, power);
        power++;
    }

    double fracValue = 0;
    double basePower = base;
    for (int i = 0; i < fracPart.length(); i++) {
        char ch = toupper(fracPart[i]);
        int digit;
        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else
            digit = ch - 'A' + 10;

        fracValue += digit / basePower;
        basePower *= base;
    }

    double total = intValue + fracValue;
    cout << "Decimal value = " << total << endl;
    return 0;
}
