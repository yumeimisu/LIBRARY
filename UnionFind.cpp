#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


vector<int> par;

void init(int n) {
  par.resize(n);
  rep(i,n){
    par[i] = i;
  }
}

int root(int x){
  if(par[x] == x) return x;
  else{
    return par[x] = root(par[x]);
  }
}

bool same(int x, int y){
  return root(x) == root(y);
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;
  par[x] = y;
}
  
  
int main(){
  int n,q;
  cin >> n >> q;
  init(n);

  rep(i,q){
    int p, a, b;
    a--; b--;
    cin >> p >> a >> b;
    if(p == 0) unite(a,b);
    else {
      if(same(a,b)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    
  }
  
}
