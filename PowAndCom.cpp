#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int modpow(ll a, ll n, ll p){
  if(n==0) return 1;
  if(n==1) return a%p;
  if(n%2 == 1) return (a*modpow(a,n-1,p))%p;
  ll t = modpow(a,n/2, p);
  return (t*t)%p;
 }

ll modnCa(ll n, ll a, ll p){
  ll upper = 1;
  ll lower = 1;
  for(ll i = 1; i <= a; i++){
    upper *= n-i+1;
    upper %= p;
    lower *= i;
    lower %= p;
  }
  ll inv_lower = modpow(lower, p-2, p);
  return (upper * inv_lower)%p;
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;

  ll p = 1000000007;
  ll tot = modpow(2, n, p)-1;
  ll atot = modnCa(n, a, p);
  ll btot = modnCa(n, b, p);

  ll ans = (tot - atot - btot+p+p)%p;
  // be careful when the ans is about to be minus
  // to avoid it, add 2*p
  cout << ans << endl;

}
