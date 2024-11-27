#include<bits/stdc++.h>
using namespace std;
int x[200005];
int dp[101][101];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,q;
  cin >> n >> q;
  while(q--){
    int t;
    cin >> t;
    if(t==1){
      int a,b,c;
      cin >> a >> b >> c;
      if(b>100){
        for(int i=a;i<=n;i+=b){
          x[i]+=c;
        }
      }
      else{
        dp[b][a]+=c;
      }
    }
    else if(t==2){
      int a;
      cin >> a;
      int ans=x[a];
      for(int i=1;i<=100;i++){
        ans+=dp[i][a%i];
      }
      cout << ans << "\n";
    }
  }
}
