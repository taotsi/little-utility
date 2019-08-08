#include <thread>
#include <chrono>
#include "utility.hh"

using namespace taotsi;
using namespace std::chrono_literals;

void TestMsg();
void TestTimer();

int main(int argc, char** argv)
{
  // TestMsg();
  TestTimer();
  return 0;
}

void TestMsg()
{
  int x = 42;
  tval(x);
  tmark();
}
void TestTimer()
{
  Timer t;
  t.tStart();
  std::this_thread::sleep_for(42ms);
  t.tPutNow();
}