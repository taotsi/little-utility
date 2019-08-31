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
    auto filter = [amp = amp_, wc = wc_](double w)
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
    auto filter = [amp = amp_, wc = wc_](double w)
    {
      return amp / (sqrt(1.0 + pow(pow(2.0, w - wc), 2.0)));
    };
    filters_.push_back(filter);
  };
  DEFAULT_SPECIAL_FUNCTIONS(ButterWorthLP);
private:
  double wc_, amp_;
};

class Gauss : public Filter
{
public:
  Gauss(double wcl, double wch, double amp = 1.0)
    : amp_{amp}
  {
    mean_ = (wcl + wch) / 2.0;
    var_ = mean_ - wcl;
    auto filter = [mean = mean_, var = var_, amp = amp_](double w)
    {
      return amp * exp(-pow(w - mean, 2.0) / (2.0*pow(var, 2.0)));
    };
    filters_.push_back(filter);
  }
  DEFAULT_SPECIAL_FUNCTIONS(Gauss);
private:
  double mean_, var_, amp_;
};

}

#endif // FILTER_HH