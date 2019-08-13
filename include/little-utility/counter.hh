#ifndef COUNTER_HH
#define COUNTER_HH

// #include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include "macros.hh"

namespace taotsi{

class Counter
{
private:
  friend void CountHere(const char* file, int line);
  Counter() {}
  ~Counter()
  {
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << "\033[0;44mCOUNTER:\033[0m\n";
    for(auto &it : counters_)
    {
      ss << "  " << it.first << ":\t" << it.second << " times\n";
    }
    std::cout << ss.str();
  }
  // DEFAULT_SPECIAL_FUNCTIONS(Counter);
  void HereOnce(const char* file, int line)
  {
    std::stringstream ss;
    ss << file << "(" << line << ")";
    if(counters_.find(ss.str()) != counters_.end())
    {
      counters_[ss.str()] ++;
    }
    else
    {
      counters_[ss.str()] = 1;
    }
  }

  std::unordered_map<std::string, unsigned long long> counters_;
};

void CountHere(const char* file, int line)
{
  static Counter c;
  c.HereOnce(file, line);
}

#define COUNT_HERE() CountHere(__FILENAME__, __LINE__)
}

#endif // COUNTER_HH