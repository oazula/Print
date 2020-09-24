#include <iostream>
#include <cstdlib>
#include <cmath>
#include <functional>


d
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