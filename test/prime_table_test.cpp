#define IUTEST_USE_MAIN 1
#include "../../iutest/include/iutest.hpp"
#include <bits/stdc++.h>
using namespace std;
#include "../prime_table.cpp"

const int INF  =  2147483647 - 1;
const int MINF = -2147483648;

IUTEST(primes, max)
{
    Sieve s(INF);
    IUTEST_ASSERT_EQ(s.primes.back(), 2147483629);
}
