#include <bits/stdc++.h>
using namespace std;
#include "../prime_table.cpp"

int main(int argc,char *argv[]) {
  const int N = 1e7;

  // Sieve生成
  PrimeTable pt(N);

  // factorList
  clock_t start = clock();

  clock_t end   = clock();

  const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
  cout << "factorList" << endl;
  cout << time << "ms" << endl << endl;

  // factorPair
  clock_t start = clock();

  clock_t end   = clock();

  const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
  cout << "facotPair" << endl;
  cout << time << "ms" << endl << endl;

  return 0;
}
