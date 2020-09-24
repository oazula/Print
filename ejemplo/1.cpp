#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cstdlib>

using fptr  = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapezoid(fptr fun, double a, double b, int n);
double richardson(fptr2 alg, fptr func, double a, double b, double eps);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double eps = std::atof(argv[1]);
    std::cout << richardson(trapezoid, f, 0, 1, eps) << "\n";

  return 0;
}




double f(double x)
{
  return (1.2-x)*(1-std::exp(20*(x-1)))*std::pow(x, 0.1);
  
}

double trapezoid(fptr fun, double a, double b, int n)
{
      const double h = (b-a)/n;
    double suma = 0.5*(fun(a) + fun(b));
    for(int ii = 1; ii <= n-1; ++ii) {
        double xi = a + ii*h;
        suma += fun(xi);
    }
    suma *= h;
    return suma;
}

double richardson(fptr2 alg, fptr func, double a, double b, double eps)
{
  double val1= 0;
  double val2= 0;
  int n=0;
  double diff =1;

 for (n=1;diff>eps; n=2*n){

    val1=(4*alg(func, a, b, 2*n) - alg(func, a, b, n))/3;
    val2=(4*alg(func, a, b, 4*n) - alg(func, a, b, 2*n))/3;

    diff= std::fabs(1- val1/val2);
    
  }
  
std::cout<< n << "\n";
std::cout<<"diff: "<<diff << "\n";


    return val1;
}