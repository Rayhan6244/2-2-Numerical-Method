#include<iostream>
using namespace std;
int main(){
   int n;
   cout<<"Enter number of data points: "<<endl;
   cin>>n;
   double x[n], y[n][n];
   cout<<"Enter x value: "<<endl;
   for(int i=0; i<n; i++){
       cin>>x[i];
   }
   cout<<"Enter y value: "<<endl;
   for(int i=0; i<n; i++ ){
       cin>>y[i][0];
   }
   for(int col=1; col<n; col++){
       for(int row=0; row<n-col; row++){
            y[row][col]=y[row+1][col-1]-y[row][col-1];
       }
   }
   double value;
   cout<<"Enter x to interpolation: "<<endl;
   cin>>value;
   double h=x[1]-x[0];
   double p=(value-x[0])/h;
   double result=y[0][0];
   double p_term=1;
   int fact=1;
   for(int i=1; i<n; i++){
      p_term=p_term*(p-(i-1));
      fact=fact*i;
      double term=(p_term/fact)* y[0][i];
      result +=term;
      cout<<"Iteration "<<i<<" :\n"<<endl;
      cout<<"Numerator(p term)= "<<p_term<<endl;
      cout<<"Denominator(factorial)= "<<fact<<endl;
      cout<<"Difference"<<i<<" y0 = "<<y[0][i]<<endl;
      cout<<"Term added= "<<term<<endl;
      cout<<"Current result= "<<result<<"\n\n"<<endl;
    }
   cout<<"Interpolation value: "<<result<<endl;
}

