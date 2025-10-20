#include <iostream>
#include<cmath>>
using namespace std;

double g(double x) {
    return (cos(x) + 1) / 3;
}

int main() {
    double x, x_new;
    double tol = 0.0001;
    int step = 0, max_steps = 100;

    x = 0.5;

    x_new = g(x);

    while ((x_new - x > tol || x - x_new > tol) && step < max_steps) {
        x = x_new;
        x_new = g(x);
        step++;
    }

    cout << "Fixed point is: " << x_new << endl;
    cout << "Total steps: " << step << endl;

    return 0;
}
