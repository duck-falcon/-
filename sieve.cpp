// int n以下の素数リスト
struct Sieve {
  int n;
  vector<int> sieve, primes;
  Sieve(int n) : n(n), sieve(n+1) {
    sieve[0] = sieve[1] = -1;
    int mx = (int)sqrt(n) + 1;
    for(int i = 2;i < n+1;++i) {
      if(i > mx) break;
      if (sieve[i]) continue;
      primes.emplace_back(i);
      sieve[i] = i;
      // 一番小さい素因数のみ記録する
      for (long long j = i*i; j <= n; j += i) if (!sieve[j]) sieve[j] = i;
    }
  }
  bool isPrime(int m) { return sieve[m] == m; }
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.emplace_back(sieve[x]);
      x /= sieve[x];
    }
    return res;
  }
  vector<pair<int,int>> factorPair(int x) {
    vector<int> fl = factorList(x);
    vector<pair<int,int>> res(1, pair<int,int>(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) res.back().second++;
      else res.emplace_back(p, 1);
    }
    return res;
  }
};
