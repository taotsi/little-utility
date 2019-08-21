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

int main(int argc, char** argv)
{
  // TestMsg();
  // TestTimer();
  // TestCounter();
  TestRand();

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
  // auto di = Rand::IntRandomDice(0, 99);
  // for (size_t i = 0; i < 20; i++)
  // {
  //   tval(di());
  // }
}