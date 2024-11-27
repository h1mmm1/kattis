#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using ll=long long int;
ll a[N],dp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll s,p,m,n;
  cin >> s >> p >> m >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
  	dp[i]=dp[i-1]+s;
    auto v=lower_bound(a+1,a+1+n,a[i]-m+1)-a;
    dp[i]=min(dp[i],dp[v-1]+p);
//    cout << v << ' ';
//    for(int j=1;j<=n;j++) cout << dp[j] << " ";
//    cout << '\n';
  }
//  for(int i=1;i<=n;i++)
  cout << dp[n];
}
