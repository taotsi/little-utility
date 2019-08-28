#ifndef FILTER_HH
#define FILTER_HH

#include <cmath>
#include <functional>
#include "macros.hh"

namespace taotsi
{

class Filter
{
public:
  Filter() {};
  DEFAULT_SPECIAL_FUNCTIONS(Filter);

  template<typename T>
  double operator()(T w)
  {
    auto wd = static_cast<double>(w);
    double result = 1.0;
    for(auto &filter : filters_)
    {
      result *= filter(wd);
    }
    return result;
  }
protected:
  std::vector<std::function<double(double)>> filters_;
};

class ButterWorthHP : public Filter
{
public:
  ButterWorthHP(double wcl, double wch, double amp = 1.0)
    : wcl_{wcl}, wch_{wch}, amp_{amp}
  {
    std::function<double(double)> filter = [this](double w)
    {
      return 1.0 / (sqrt(1.0 + pow(pow(2.0, w - this->wch_), 2.0)));
    };
    filters_.push_back(filter);
  };
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorthHP);

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

private:
  double wcl_, wch_, amp_;
  double mean_, var_;
};

}

#endif // FILTER_HH