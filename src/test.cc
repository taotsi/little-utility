#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib>
#include "utility.hh"

using namespace taotsi;
using namespace std::chrono_literals;

void TestMsg();
void TestTimer();
void TestCounter();
void TestRand();
void test_filter();

int main(int argc, char** argv)
{
  // TestMsg();
  // TestTimer();
  // TestCounter();
  // TestRand();
  test_filter();

  return 0;
}

void TestMsg()
{
  // int x = 42;
  // tval(x);
  // tmark();
  std::vector<int> vec{1, 2, 3, 4, 5};
  tval(vec);
}
void TestTimer()
{
  Timer t;
  t.tStart();
  std::this_thread::sleep_for(1234ms);
  t.tPutNow();
}

void TestCounter()
{
  for (size_t i = 0; i < 50; i++)
  {
    COUNT_HERE();
  }
  SHOW_COUNTS();
  for (size_t i = 0; i < 10000; i++)
  {
    COUNT_HERE();
  }
}

void TestRand()
{
  auto di = Rand::int_random_dice(0, 99);
  for (size_t i = 0; i < 20; i++)
  {
    tval(di());
  }
  auto dp = Rand::probability_dice();
  for (size_t i = 0; i < 20; i++)
  {
    tval(dp());
  }
}

void test_filter()
{
  ButterWorth bw{10.0, 100.0};
  for(double w=0; w<200; w+=1)
  {
    std::cout << bw(w) << "\n";
  }
  Gauss gs{10, 100};
  for(double w=0; w<200; w+=1)
  {
    std::cout << gs(w) << "\n";
  }
}