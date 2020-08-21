#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
#define INF 2147483647

//SegmentTree for RMR//
vector<int> value;
int N;

void update(int i, int x){
  i += N-1;
  value[i] = x;
  while(i > 0){
    i = (i-1)/2;
    value[i] = min(value[2*i+1], value[2*i+2]);
  }
}

int query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return INF;
  if(a <= l && r <= b) return value[k];
  
  else {
    int c1 = query(a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1,c2);
  }
}

int main(){
  int n;
  cin >> n;
  N = 1;
  while(N < n) N *= 2;
  value.assign(2*N-1, INF);


  //RQM
  int q;
  cin >> q;
  rep(i,q){
    int c;
    cin >> c;
    if(c == 0) {
      int i,x;
      cin >> i >> x;
      update(i,x);
    }else{
      int s,t;
      cin >> s >> t;
      cout << query(s,t+1, 0, 0, N) << endl;
    }
  }
  return 0;
}
