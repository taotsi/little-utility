#include "utility.hh"

using namespace taotsi;

void TestMsg();
void TestTimer();


int main(int argc, char** argv)
{
  TestMsg();
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

}