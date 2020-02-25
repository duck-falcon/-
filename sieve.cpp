// int n以下の素数リスト
struct Sieve {
  int n;
  vector<int> sieve, primes;
  Sieve(int n) : n(n), sieve(n+1) {
    sieve[0] = sieve[1] = -1;
    FOR(i,2,n+1) {
      if (sieve[i]) continue;
      primes.emb(i);
      sieve[i] = i;
      // 一番小さい素因数のみ記録する
      for (ll j = i*i; j <= n; j += i) if (!sieve[j]) sieve[j] = i;
    }
  }
  bool isPrime(int m) { return sieve[m] == m; }
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.emb(sieve[x]);
      x /= sieve[x];
    }
    return res;
  }
  vector<P> factorPair(int x) {
    vector<int> fl = factorList(x);
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().fi == p) res.back().se++;
      else res.emb(p, 1);
    }
    return res;
  }
};
