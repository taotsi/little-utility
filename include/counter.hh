#ifndef COUNTER_HH
#define COUNTER_HH

#include <vector>
#include "macros.hh"
#include "msg.hh"

namespace taotsi{


class Counter
{
public:
  Counter()
  {
    counters_.push_back(0);
    counter_index_ = num_counters_;
    num_counters_ ++;
  }
  ~Counter()
  {
    std::cout << "counter " << counter_index_ << " counted " << counters_[counter_index_] << " times\n";
    // std::stringstream ss;
    // ss << "\033[0;45mCOUNTER " << counter_index_ << " \033[0m" << " " << file_name_ << "(" << line_number_ << "), " << func_name_ << ": counted " << counters_[counter_index_] << " times\n";
    // std::cout << ss.str();
  }
  // DEFAULT_SPECIAL_FUNCTIONS(Counter);
  void Once()
  {
    counters_[counter_index_] ++;
  }
private:
  static std::vector<int> counters_;
  int counter_index_;
  static int num_counters_;
  std::string file_name_;
  int line_number_;
  std::string func_name_;
};

int Counter::num_counters_ = 0;
std::vector<int> Counter::counters_ = {};

}

#endif // COUNTER_HH