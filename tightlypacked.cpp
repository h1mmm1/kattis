//https://open.kattis.com/problems/tightlypacked
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,mn=LLONG_MAX;
  cin >> n;
  for(int i=sqrt(n/2);i<=sqrt(2*n);i++){
  	if(i==0) continue;
    ll w=i;
    ll h=n/w;
    if(n%w!=0) h++;
//    cout << w << ' ' << h << "\n";
    if(w*h-n>=0) mn=min(mn,w*h-n);
  }
  cout << mn;
}
