#ifndef FILTER_HH
#define FILTER_HH

#include <cmath>
#include "macros.hh"

class ButterWorth
{
public:
  ButterWorth(double wcl, double wch, double amp = 1.0)
    : amp_{amp}, wcl_{wcl}, wch_{wch}
  {};
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorth);

  double operator()(double w)
  {
    double val = amp_ *
      (1.0 / (sqrt(1.0 + pow(pow(2.0, w - wch_), 2.0)))) *
      (1.0 / (sqrt(1.0 + pow(pow(2.0, wcl_ - w), 2.0))));
    return val;
  }
private:
  double amp_, wcl_, wch_;
};


#endif // FILTER_HH