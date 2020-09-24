#include <iostream>
#include <cstdlib>
#include <cmath>
#include <functional>


double f(double x);
double deriv2_exact(double x1);
double deriv2a(double f1,double x1,double dx);
double deriv2b(double f1,double x1,double dx);


int main(int argc, char **argv)
{
    std::cout.precision(16); std::cout.setf(std::ios::scientific);
    const double x = std::atof(argv[1]);
    double h = 0;
    double delta1, delta2; // percentual diffs
    for (int ii = 1; ii <= 16; ++ii) {
        double h = M_PI*std::pow(10.0, -ii);
        delta1 = std::fabs(1.0 - deriv2a(f(x), x, h)/deriv2_exact(x));
        delta2 = std::fabs(1.0 - deriv2b(f(x), x, h)/deriv2_exact(x));
        std::cout << h << " \t" << delta1 << "\t" << delta2 << "\n";
    }
  
    return 0;
}

double deriv2a(double f1,double x1,double dx)
{
return ((f(x1+dx)-f1)-(f1-f(x1-dx)))/(dx*dx);
}

double deriv2b(double f1,double x1,double dx)
{
return (f(x1+dx)+f(x1-dx)-2*f1)/(dx*dx);

}

double deriv2_exact(double x1)
{
  return ((-2*std::sin(x1))-(x1*std::cos(x1)));
}

double f(double x)
{
    return x*std::cos(x);
}