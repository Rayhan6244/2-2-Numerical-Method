#include <iostream>
using namespace std;

int main() {
    double num;
    int base;

    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Enter base (2-16): ";
    cin >> base;

    int intPart = (int)num;
    double fracPart = num - intPart;

    string intResult = "";
    if (intPart == 0)
        intResult = "0";
    else {
        while (intPart > 0) {
            int remainder = intPart % base;
            if (remainder < 10)
                intResult = char('0' + remainder) + intResult;
            else
                intResult = char('A' + remainder - 10) + intResult;
            intPart /= base;
        }
    }

    string fracResult = "";
    int limit = 10;  
    while (fracPart > 0 && limit--) {
        fracPart *= base;
        int digit = (int)fracPart;
        if (digit < 10)
            fracResult += char('0' + digit);
        else
            fracResult += char('A' + digit - 10);
        fracPart -= digit;
    }

    cout << "Number in base " << base << " = " << intResult;
    if (!fracResult.empty())
        cout << "." << fracResult;
    cout << endl;

    return 0;
}
