gcd(ll a,ll b)  { return b ? return gcd(a,a%b) : a }
lcm(ll a, ll b) { return a/gcd(a,b)*b }
