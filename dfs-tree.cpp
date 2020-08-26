// dfs-tree

int n;
vvi maze;
vi seen;

void dfs(int x) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx);
  }
}

// 入力整形例

int main() {
  cin >> n;
  maze = vvi(n,vi());
  seen = vi(n,0);
  int m;cin >> m;
  rep(i,m) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  int ans = 0;
  rep(i,n) {
    if(!seen.at(i)) {
      dfs(i);
      ans++;
    }
  }

  cout << ans << endl;


  return 0;
}
