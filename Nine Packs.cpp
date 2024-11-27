#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp1[N];
int dp2[N];
int a[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=N;i++){
    dp1[i]=dp2[i]=1e6;
  }
  dp1[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=N;j>=a[i];j--){
      dp1[j]=min(dp1[j],dp1[j-a[i]]+1);
    }
  }
  int m;
  cin >> m;
  for(int i=1;i<=m;i++){
    cin >> a[i];
  }
  dp2[0]=0;
  for(int i=1;i<=m;i++){
    for(int j=N;j>=a[i];j--){
      dp2[j]=min(dp2[j],dp2[j-a[i]]+1);
    }
  }
  int ans=INT_MAX;
  for(int i=1;i<=N;i++){
    if(dp2[i]!=1e6 && dp1[i]!=1e6){
      ans=min(ans,dp1[i]+dp2[i]);
      //cout << i << ' ' << dp1[i] << ' ' << dp2[i] << "\n";
    }
  }
  if(ans==INT_MAX) cout << "impossible";
  else cout << ans;
}

