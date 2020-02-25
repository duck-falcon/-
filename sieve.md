
## Sieve(int n)
 n以下のエラトステネスの篩

#### メンバ変数
 - `vector<int> primes`
   - n以下の素数
 - `vector<int> sieve`
   - n以下の篩
   - sieve[i] = iの素因数のうち最小の値

#### メンバ関数
 - `bool isPrime(int x)`
  - xが素数ならtrue
 - `vector<int> factorList(int x)`
  - xの素因数分解
  - 小さい順
 - `vector<pair<int,int>> factorPair(int x)`
  - xの素因数分解
  - 素因数が小さい順
  - 冪乗形式

---

## 例
#### メンバ変数
 - `vector<int> primes`
   - n以下の素数
 - `vector<int> sieve`
   - n以下の篩
   - sieve[i] = iの素因数のうち最小の値

#### メンバ関数
 - `bool isPrime(int x)`
  - xが素数ならtrue
 - `vector<int> factorList(int x)`
  - xの素因数分解
  - 小さい順
 - `vector<pair<int,int>> factorPair(int x)`
  - xの素因数分解
  - 素因数が小さい順
  - 冪乗形式
