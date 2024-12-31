#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[],int N,double c[]){
    
    double sum, sum2, sumh = 0;
    double sumg = 1;

    for(int i =0; i<N; i++){
        sum += a[i] ;
        sum2 += pow(a[i],2) ;
        sumg *= a[i] ;
        sumh += (1/a[i]) ;
    }
    double xbar = sum/N ;
    c[0] = xbar ; 
    c[1] = sqrt((sum2/N)-pow(xbar,2)) ;

    double root = 1.0/N ;
    double GM = pow(sumg,root) ;
    c[2] = GM ;

    double HM = (N/sumh) ;
    c[3] = HM ;

    double max, min ;
    max = a[0];
    min = a[0];
    for(int i=0; i<N ; i++){
        if(a[i]>max) max = a[i] ;
        if(a[i]<min) min = a[i] ;
    }
    c[4] = max ;
    c[5] = min ;

}