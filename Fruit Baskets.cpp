#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[45];
ll sum=0,n;
void rec(ll cnt,ll i){
  if(i==n) return; 
  rec(cnt,i+1);
  if(cnt+a[i+1]<200) {
    sum-=(cnt+a[i+1]);
    rec(cnt+a[i+1],i+1);
  } 
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  ll x=pow(2,n-1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  sum*=x;
  rec(0,0);
  cout << sum;
}
