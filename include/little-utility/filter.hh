#ifndef FILTER_HH
#define FILTER_HH

#include <cmath>
#include "macros.hh"

class ButterWorth
{
public:
  ButterWorth(double wcl, double wch, double amp = 1.0)
    : wcl_{wcl}, wch_{wch}, amp_{amp}
  {};
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorth);

  template<typename T>
  double operator()(T w)
  {
    auto wd = static_cast<double>(w);
    double val = amp_ *
      (1.0 / (sqrt(1.0 + pow(pow(2.0, wd - wch_), 2.0)))) *
      (1.0 / (sqrt(1.0 + pow(pow(2.0, wcl_ - wd), 2.0))));
    return val;
  }
private:
  double wcl_, wch_, amp_;
};

class Gauss
{
public:
  Gauss(double wcl, double wch, double amp = 1.0)
    : wcl_{wcl}, wch_{wch}, amp_{amp}
  {
    mean_ = (wch_ + wcl_) / 2.0;
    var_ = wch_ - mean_;
  }
  template<typename T>
  double operator()(T w)
  {
    auto wd = static_cast<double>(w);
    double val = amp_ *
      exp(-pow(wd - mean_, 2.0)/(2.0*pow(var_, 2.0)));
    return val;
  }

private:
  double wcl_, wch_, amp_;
  double mean_, var_;
};


#endif // FILTER_HH