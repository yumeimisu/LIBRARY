#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

//submit
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A

int main(){
  int v,e,r;
  cin >> v >> e >> r;

  vector<vector<pair<int,int>>> c(v);

  rep(i,e){
    int s,t,d;
    cin >> s >> t >> d;
    c[s].push_back({d,t});
    //d is cost, s amd t are node
  }

  vector<int> cost(v,inf);
  cost[r] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
  // arrange nodes upsorting
  pair<int,int> st = {0,r};
  q.push(st);
  
  while(!q.empty()){
    int ct = q.top().second;
    q.pop();
    for(auto p : c[ct]){
      int nd = p.first;
      int nt = p.second;
      if(cost[nt] <= cost[ct]+nd) continue;
      //updata the minimum cost
      cost[nt] = cost[ct]+nd;
      q.push({nd,nt});
    }
    
  }

  rep(i,v){
    if(cost[i] == inf) cout << "INF" << endl;
    else cout << cost[i] << endl;
  }
  

}
