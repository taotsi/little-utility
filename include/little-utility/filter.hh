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
  friend Filter operator*(const Filter &lhs, const Filter &rhs)
  {
    Filter f;
    f.filters_.insert(f.filters_.end(), lhs.filters_.begin(), lhs.filters_.end());
    f.filters_.insert(f.filters_.end(), rhs.filters_.begin(), rhs.filters_.end());
    return f;
  }
protected:
  std::vector<std::function<double(double)>> filters_;
};

class ButterWorthHP : public Filter
{
public:
  ButterWorthHP(double wc, double amp = 1.0)
    : wc_{wc}, amp_{amp}
  {
    std::function<double(double)> filter = [amp = amp_, wc = wc_](double w)
    {
      return amp / (sqrt(1.0 + pow(pow(2.0, wc - w), 2.0)));
    };
    filters_.push_back(filter);
  };
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorthHP);

private:
  double wc_, amp_;
};

class ButterWorthLP : public Filter
{
public:
  ButterWorthLP(double wc, double amp = 1.0)
    : wc_{wc}, amp_{amp}
  {
    std::function<double(double)> filter = [amp = amp_, wc = wc_](double w)
    {
      return amp / (sqrt(1.0 + pow(pow(2.0, w - wc), 2.0)));
    };
    filters_.push_back(filter);
  };
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorthLP);
private:
  double wc_, amp_;
};

}

#endif // FILTER_HH