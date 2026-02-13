#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - 4*x - 9;
}

void falsePosition(double a, double b, double tol) {
    double c, fa, fb, fc;
    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        cout << "Invalid guesses, try again.\n";
        return;
    }

    int step = 1;
    do {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        cout << step << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << "\n";

        if (fc == 0.0) break;
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        step++;
    } while (fabs(fc) > tol);
    cout << "The root is: " << c << endl;
}

int main() {
    double a, b, tol;
    cout << "Enter initial guesses a and b: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tol;
    falsePosition(a, b, tol);
    return 0;
}

