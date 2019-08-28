#ifndef RAND_HH
#define RAND_HH

#include <random>
#include <functional>

namespace taotsi
{

class Rand
{
public:
  static auto probability_dice()
  {
    double begin = 0.0, end = 1.0;
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_real_distribution<double> dist{begin, end};
    auto dice = std::bind(dist, mt);
    return dice;
  }

  static auto int_random_dice(int begin, int end)
  {
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> dist{begin, end};
    auto dice = std::bind(dist, mt);
    return dice;
  }
  static bool die_once(double p)
  {
    assert(p >= 0 && p <=1);
    auto dice = probability_dice();
    if(dice() <= p)
    {
      return true;
    }
    return false;
  }
private:

};

} // namespace taotsi

#endif // RAND_HH