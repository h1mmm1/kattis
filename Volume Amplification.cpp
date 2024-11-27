#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int dp[N];
int a[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    memset(dp,0,sizeof dp);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    dp[1]=1;
    for(int i=1;i<=n;i++){
      if(a[i]==1) continue;
      for(int j=m/a[i];j>0;j--){
        if(dp[j]!=1) continue;
        dp[j*a[i]]=1;
      }
    }
    for(int i=m;i>0;i--){
      if(dp[i]==1){
        cout << i << "\n";
        break;
      }
    }
  }
}
