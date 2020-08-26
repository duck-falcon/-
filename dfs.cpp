// dfs

int rows,columns;
vi maze;
// 4方向
vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
// 8方向
// vi dx = {1,1,0,-1,-1,-1,0,1}, dy = {0,1,1,1,0,-1,-1,-1};
// start goal
// int sx,sy,gx,gy;

void dfs(int x, int y) {
  int n = dx.size();
  maze.at(x).at(y) = 0;
  rep(i,n) {
    int nx = x + dx.at(i), ny = y + dy.at(i);
    if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny)) dfs(nx,ny);
  }
}

// 入力整形例
int main() {
  // h w のこと
  cin >> columns >> rows;
  maze = vvi(columns,vi(rows,0));
  rep(i, columns) {
    string s; cin >> s;
    rep(j, rows) {
      if(s.at(j)=='.') maze.at(i).at(j) = 1;
      else if (s.at(j)=='#') maze.at(i).at(j) = 0;
//      else if (s.at(j) == 's') {sx = i; sy = j;maze.at(i).at(j)=1;}
//      else if (s.at(j) == 'g') {gx = i, gy = j;maze.at(i).at(j)=1;}
    }
  }

  return 0;
}
