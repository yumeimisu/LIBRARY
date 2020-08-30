#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


//ABC-177D
vector<vector<int>> g;
vector<int> seen;
int dfs(int i){
  int cnt = 0;
  for(auto j : g[i]) {
    if(seen[j] == 1) continue;
    seen[j] = 1;
    cnt++;// count itseld
    cnt += dfs(j); // count next node
  }
  cout << i << cnt << endl;
  return cnt;
}
  
int main(){
  int n,m;
  cin >> n >> m;
  g.resize(n);
  rep(i,n) g[i].resize(0);
  seen.resize(n,0);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 1;
  rep(i,n) {
    if(i == 1) continue; //printf dbg 2 1 1 2 
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
}
