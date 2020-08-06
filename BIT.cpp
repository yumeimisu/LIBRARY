#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

// Binary Indexed Tree
// 1-indexed
template<typename T> //T:type of cost
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i, T x){
    for(i++; i <= n; i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++; i; i -= i&-i){
      x += d[i];
    }
    return x;
  }
};


int main(){
  BIT<int> bit(8);
  for(int i = 0; i < 8; i++){
    bit.add(i,1);
    cout << bit.sum(i) << endl;
  }
}
