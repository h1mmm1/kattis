#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int a[105];
long long int dp[2000200];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=a[n]*2;i++) dp[i]=INT_MAX;
  for(int i=1;i<=n;i++){
    for(int j=a[i];j<=a[n]*2;j++){
      dp[j]=min(dp[j],dp[j-a[i]]+1);
    }
  }
//  for(int i=1;i<=20;i++){
//    cout << dp[i] << ' ';
//  }

//  13 7 6
 for(int i=a[1];i<=a[n]*2;i++){
   int x=i,sum=0;
   while(x>0){
     auto v=upper_bound(a+1,a+n+1,x)-a-1;
     if(v==0) break;     
     sum+=x/a[v];
     x%=a[v];

   }
   //cout << i << ' ' << sum << ' ' << dp[i] << "\n";
   if(sum>dp[i]){
     cout << "non-canonical";
     return 0;
   }
 }
 cout << "canonical";
}
