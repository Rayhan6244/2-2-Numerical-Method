//for 3x-cosx-1
#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 3*x-cos(x)-1;
}
double f_prime(double x) {
    return 3+sin(x);
}
int main() {
    double a, b, x0, x1;
    cout << "Enter a and b: ";
    cin >> a >> b;

    if (f(a)*f(b) >= 0) {
        cout << "Invalid interval.\n";
        return 1;
    }

    x0 = a;
    do {
        x1 = x0 - f(x0)/f_prime(x0);
        if (fabs(x1 - x0) < 1e-6) break;
        x0 = x1;
    } while (true);

    cout << "Root: " << x1 << endl;
    return 0;
}




