#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib>
#include "utility.hh"
#include "catch.hpp"

using namespace taotsi;
using namespace std::chrono_literals;

TEST_CASE("butterworth filter")
{
  ButterWorthLP bl{100.0};
  SECTION("butterwort low pass")
  {
    REQUIRE(abs(bl(200.0)) < 0.001);
    REQUIRE(abs(bl(50.0) - 1.0) < 0.001);
    REQUIRE(abs(bl(100.0) - 0.707) < 0.001);
  }
  ButterWorthHP bh{10.0};
  SECTION("butterworth high pass")
  {
    REQUIRE(abs(bh(0.0)) < 0.001);
    REQUIRE(abs(bh(50.0) - 1.0) < 0.001);
    REQUIRE(abs(bh(10.0) - 0.707) < 0.001);
  }
  SECTION("filter mutiples")
  {
    ButterWorthLP bl2{100.0};
    auto bl3 = bl * bl2;
    REQUIRE(abs(bl3(100.0) - 0.707*0.707) < 0.001);
    REQUIRE(abs(bl3(50.0) - 1.0) < 0.001);
    REQUIRE(abs(bl3(200.0)) < 0.001);

    ButterWorthLP bl4{100.0};
    auto bl5 = bl3 * bl4;
    REQUIRE(abs(bl5(100.0) - 0.707*0.707*0.707) < 0.001);
  }
  SECTION("butterworth band pass")
  {
    auto bb = bh * bl;
    REQUIRE(abs(bb(50.0) - 1.0) < 0.001);
    REQUIRE(abs(bb(10.0) - 0.707) < 0.001);
    REQUIRE(abs(bb(100.0) - 0.707) < 0.001);
    REQUIRE(abs(bb(0.0)) < 0.001);
    REQUIRE(abs(bb(200.0)) < 0.001);
  }
}

TEST_CASE("gauss band pass")
{
  Gauss gs{10.0, 100.0};
  REQUIRE(abs(gs(55.0) - 1.0) < 0.001);
  REQUIRE(gs(10.0) == gs(100.0));
  REQUIRE(abs(gs(10.0) - exp(-0.5)) < 0.001);
}

TEST_CASE("macros")
{
  int some_var = 42;
  REQUIRE(VAR_NAME(some_var) == std::string("some_var"));
}

TEST_CASE("counter")
{
  for (size_t i = 0; i < 1000; i++)
  {
    tCountOnce();
  }
  for (size_t i = 0; i < 1000; i++)
  {
    tCount(i+1);
  }
}

TEST_CASE("timer")
{
  Timer t;
  t.tStart();
  for (size_t i = 0; i < 9999; i++)
  {
    int x = i*i*i;
  }
  t.tPutNow();
}
// void TestMsg()
// {
//   // int x = 42;
//   // tval(x);
//   // tmark();
//   std::vector<int> vec{1, 2, 3, 4, 5};
//   tval(vec);
// }
// void TestTimer()
// {
//   Timer t;
//   t.tStart();
//   std::this_thread::sleep_for(1234ms);
//   t.tPutNow();
// }


// void test_rand()
// {
//   // auto di = Rand::int_random_dice(0, 99);
//   // for (size_t i = 0; i < 20; i++)
//   // {
//   //   tval(di());
//   // }
//   // auto dp = Rand::probability_dice();
//   // for (size_t i = 0; i < 20; i++)
//   // {
//   //   tval(dp());
//   // }
//   int count = 0;
//   for (size_t i = 0; i < 10000; i++)
//   {
//     if(Rand::die_once(0.5))
//     {
//       count++;
//     }
//   }
//   tval(count);
// }

// void test_filter()
// {
//   ButterWorth bw{10.0, 100.0};
//   for(double w=0; w<200; w+=1)
//   {
//     std::cout << bw(w) << "\n";
//   }
//   Gauss gs{10, 100};
//   for(double w=0; w<200; w+=1)
//   {
//     std::cout << gs(w) << "\n";
//   }
// }