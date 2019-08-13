#ifndef COUNTER_HH
#define COUNTER_HH

#include <vector>
#include "macros.hh"

namespace taotsi{


class Counter
{
public:
  static Counter NewCounter(const char* file, int line, const char* func)
  {
    return {file, line, func};
  }
  ~Counter()
  {
    // std::cout << "counter " << counter_index_ << " counted " << counters_[counter_index_] << " times\n";
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << "\033[0;44mCOUNTER(" << counter_index_ << ")\033[0m:" << counters_[counter_index_] << " times, " << file_name_ << "(" << line_number_ << "), " << func_name_ << "\n";
    std::cout << ss.str();
  }
  // DEFAULT_SPECIAL_FUNCTIONS(Counter);
  void Once()
  {
    counters_[counter_index_] ++;
  }
private:
  Counter(const char* file, int line, const char* func)
    : file_name_{file}, line_number_{line}, func_name_{func}
  {
    counters_.push_back(0);
    counter_index_ = num_counters_;
    num_counters_ ++;
  }
  static std::vector<unsigned long long> counters_;
  int counter_index_;
  static int num_counters_;
  std::string file_name_;
  int line_number_;
  std::string func_name_;
};

#define NewCounter() NewCounter(__FILENAME__, __LINE__, __FUNCTION__)

int Counter::num_counters_ = 0;
std::vector<unsigned long long> Counter::counters_ = {};

}

#endif // COUNTER_HH