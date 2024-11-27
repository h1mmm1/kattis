#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
const int N=45,M=805;
int a[N],b[N];
ll dp[N][M][M];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i] >> b[i];
  }
  dp[0][401][401]=1;
  for(int i=1;i<=n;i++){
    for(int j=M;j>=a[i];j--){
      for(int k=M;k>=b[i];k--){
        dp[i][j][k]+=dp[i-1][j][k]+dp[i-1][j-a[i]][k-b[i]];
      }
    }
  }
  cout << dp[n][401][401]-1;
}



