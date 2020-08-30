#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int gcd(int n, int m){
  if(n < m) swap(n,m);

  if(m==0) return n; // 0's deviser is all numbers.
  while(m > 0){
    int res = n%m;
    n = m;
    m = res;
  }
  return n;
}
//

int lcm(int n, int m){
  return m*n/gcd(n,m);
}


int main(){
  ll n,m;
  cout << lcm(n,m) << endl;
}
