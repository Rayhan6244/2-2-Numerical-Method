#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 3 * x - cos(x) - 1;
}

int main() {
    double a = 0.0, b = 1.0;  
    
    if (f(a) * f(b) >= 0) {
        cout << "f(a) and f(b) must have opposite signs. Choose different a and b." << endl;
        return 1;
    }

    double c;
    
    for (int i = 0; i < 2; ++i) {
        c = (a + b) / 2.0;
        double fc = f(c);

        cout << "Iteration " << i + 1 << ": c = " << c << ", f(c) = " << fc << endl;

        if (f(a) * fc <= 0) {
            b = c;
        } else {
            a = c;
        }
    }

    cout << "After 2 iterations, approximate root is: " << c << endl;

    return 0;
}
