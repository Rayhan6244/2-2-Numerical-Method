#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,k;
    float a[10][10], b[10], x[10] = {0};

    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter co-efficient of metrix A: " << endl;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter constant vector b: " << endl;
    for(i = 0; i < n; i++)
        cin >> b[i];

    int iterations = 10;

    for(k = 0; k < iterations; k++){
        for(i = 0; i < n; i++){
            float sum = 0;
            for(j = 0; j < n; j++){
                if(j != i)
                    sum += a[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
        }
    }

    cout << "Solutions: " << endl;
    for(i = 0; i < n; i++)
        cout<<"x" << i + 1 << " = " << x[i] << endl;

    return 0;
}
