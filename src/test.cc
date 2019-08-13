#include <thread>
#include <chrono>
#include <limits>
#include "utility.hh"

using namespace taotsi;
using namespace std::chrono_literals;

void TestMsg();
void TestTimer();
void TestCounter();

int main(int argc, char** argv)
{
  // TestMsg();
  TestTimer();
  TestCounter();
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
  auto c1 = Counter::NewCounter();
  for (size_t i = 0; i < 1234567; i++)
  {
    c1.Once();
  }
  auto c2 = Counter::NewCounter();
  for (size_t i = 0; i < 50; i++)
  {
    c2.Once();
  }
}